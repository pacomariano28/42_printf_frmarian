/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:08:57 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/18 14:57:04 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	if (s)
	{
		cc = (char) c;
		i = 0;
		while (s[i])
		{
			if (s[i] == cc)
				return (i);
			i++;
		}
		if (s[i] == cc)
			return (i);
	}
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (s1)
	{
		while (s1[i])
		{
			line[i] = s1[i];
			i++;
		}
		free(s1);
		s1 = NULL;
	}
	while (s2[j])
	{
		line[i + j] = s2[j];
		j++;
	}
	free(s2);
	s2 = NULL;
	return (line);
}

char	*ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	dst = malloc((dstsize + 1) * sizeof(char));
	if (!dst)
		return (0);
	if (dstsize != 0)
	{
		while ((i < dstsize) && (src[i]))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}


char	*ft_getrest(char **line, int index)
{
	char	*rest;
	int		rest_len;
	int		i;

	i = 0;
	rest_len = 0;
	while ((*line)[rest_len + index])
		rest_len++;
	rest = malloc ((rest_len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	while ((*line)[index + i])
	{
		rest[i] = (*line)[index + i];
		i++;
	}
	rest[i] = '\0';
	free(*line);
	*line = ft_strlcpy(*line, rest, rest_len + 1);
	free(rest);
	return (*line);
}

char	*ft_getline(char **line)
{
	char	*str;
	int		i;

	str = "";
	i = ft_strchr((*line), '\n');
	str = ft_strlcpy(str, (*line), (i + 1));
	*line = ft_getrest(line, (i + 1));
	return (str);
}

void	*ft_exit(char **txt, int fd)
{
	int			bytes_read;
	char		*str;
	static int	check;

	if (fd == 0 && check != 1)
	{
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!str)
			return (NULL);
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(str);
			free(*txt);
			str = NULL;
			*txt = NULL;
			return (NULL);
		}
		str[bytes_read] = '\0';
		check = 1;
		return (free(*txt), str);
	}
	free(*txt);
	*txt = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*txt;
	int				bytes_read;

	txt = NULL;
	while (ft_strchr(txt, '\n') == -1)
	{
		txt = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!txt || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd <= 0)
			return (ft_exit(&txt, fd));
		bytes_read = read(fd, txt, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !line))
			return (ft_exit(&txt, fd));
		txt[bytes_read] = '\0';
		line = ft_strjoin(line, txt);
		txt = NULL;
		if (ft_strchr(line, '\n') != -1)
			return (ft_getline(&line));
		if (ft_strchr(line, '\n') == -1 && bytes_read == 0)
		{
			txt = ft_strlcpy(txt, line, ft_strlen(line));
			return (free(line), line = NULL, txt);
		}
	}
	return (NULL);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	if (fd == -1)
		return (-1);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("\n");
	return (0);
}
