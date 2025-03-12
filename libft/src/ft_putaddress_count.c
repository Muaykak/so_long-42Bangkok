/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:33:55 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 18:27:36 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthexaddress_count(unsigned long ptr, int *count);

int	ft_putaddress_count(void *ptr, int *count)
{
	if (ptr == 0)
	{
		if (ft_putstr_count("(nil)", count) == -1)
			return (-1);
		return (1);
	}
	if (ft_putstr_count("0x", count) == -1)
		return (-1);
	if (ft_puthexaddress_count((unsigned long)ptr, count) == -1)
		return (-1);
	return (1);
}

static int	ft_puthexaddress_count(unsigned long ptr, int *count)
{
	if (ptr / 16 != 0)
	{
		if (ft_puthexaddress_count(ptr / 16, count) == -1)
			return (-1);
	}
	if (ptr % 16 < 10)
	{
		if (ft_putchar_count((ptr % 16) + 48, count) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_count((ptr % 16) + 87, count) == -1)
			return (-1);
	}
	return (1);
}
