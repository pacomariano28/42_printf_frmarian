/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:08:45 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/14 12:03:51 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_pf(unsigned int n, int *cont)
{
	if (n > 9)
		ft_putunbr_pf((n / 10), cont);
	ft_putchar_pf(('0' + n % 10), cont);
}
