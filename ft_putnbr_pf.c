/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:08:45 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/14 12:03:41 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, int *cont)
{
	if (n == -2147483648)
	{
		ft_putnbr_pf((n / 10), cont);
		ft_putchar_pf('8', cont);
	}
	else if (n < 0)
	{
		ft_putchar_pf('-', cont);
		ft_putnbr_pf(-n, cont);
	}
	else
	{
		if (n > 9)
			ft_putnbr_pf((n / 10), cont);
		ft_putchar_pf(('0' + n % 10), cont);
	}
}
