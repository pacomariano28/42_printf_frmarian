/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:11:30 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/16 11:58:43 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char s, va_list args, int *cont)
{
	if (s == '%')
		ft_putchar_pf(s, cont);
	else if (s == 'd' || s == 'i')
		ft_putnbr_pf(va_arg(args, int), cont);
	else if (s == 'u')
		ft_putunbr_pf(va_arg(args, unsigned int), cont);
	else if (s == 'c')
		ft_putchar_pf((char)va_arg(args, int), cont);
	else if (s == 's')
		ft_putstr_pf(va_arg(args, char *), cont);
	else if (s == 'p')
		ft_putptr_pf(va_arg(args, void *), cont);
	else if (s == 'x' || s == 'X')
		ft_puthexa_pf(va_arg(args, unsigned int), s, cont);
}

int	ft_printf(char const *str, ...)
{
	char	*s;
	int		cont;
	va_list	args;

	if (write(1, "", 0) == -1)
		return (-1);
	cont = 0;
	s = (char *)str;
	va_start(args, str);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_write(*s, args, &cont);
		}
		else
		{
			ft_putchar_pf(*s, &cont);
			if (cont == -1)
				return (-1);
		}
		s++;
	}
	return (cont);
}
