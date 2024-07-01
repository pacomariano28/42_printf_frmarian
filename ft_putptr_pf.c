/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:53:44 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/16 11:50:47 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *ptr, int *cont)
{
	ft_putchar_pf('0', cont);
	ft_putchar_pf('x', cont);
	ft_puthexa_pf((uintptr_t)ptr, 'x', cont);
}
