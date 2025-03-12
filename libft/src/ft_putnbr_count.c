/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:04:23 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 17:36:57 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_count(int num, int *count)
{
	char	c;

	if (num < -2147483647)
	{
		if (ft_putstr_count("-2147483648", count) == -1)
			return (-1);
		return (1);
	}
	if (num < 0)
	{
		if (ft_putchar_count('-', count) == -1)
			return (-1);
		num = num * -1;
	}
	if (num / 10 != 0)
		if (ft_putnbr_count((num / 10), count) == -1)
			return (-1);
	c = (num % 10) + 48;
	if (ft_putchar_count(c, count) == -1)
		return (-1);
	return (1);
}
