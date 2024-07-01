/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:11:54 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/10 13:56:38 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

void	ft_write(char s, va_list args, int *cont);
void	ft_putchar_pf(char c, int *cont);
void	ft_putunbr_pf(unsigned int n, int *cont);
void	ft_putstr_pf(char *str, int *cont);
void	ft_putnbr_pf(int n, int *cont);
void	ft_putptr_pf(void *ptr, int *cont);
void	ft_puthexa_pf(uintptr_t num, char c, int *cont);
int		ft_printf(char const *str, ...);

#endif