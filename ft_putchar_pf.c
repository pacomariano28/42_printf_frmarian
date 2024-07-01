/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:11:13 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/15 10:40:43 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, int *cont)
{
	int	res;

	res = 0;
	res = write(1, &c, 1);
	if (res == -1)
		*cont = -1;
	else
		(*cont)++;
}
