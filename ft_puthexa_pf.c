/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:08 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/14 12:03:37 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_pf(uintptr_t lst, char format, int *cont)
{
	if (lst >= 16)
		ft_puthexa_pf(lst / 16, format, cont);
	if (format == 'x')
		ft_putchar_pf("0123456789abcdef" [lst % 16], cont);
	if (format == 'X')
		ft_putchar_pf("0123456789ABCDEF" [lst % 16], cont);
}
