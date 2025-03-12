/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_big_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:44:13 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 18:28:32 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_big_count(unsigned int num, int *count)
{
	if (num / 16 != 0)
	{
		if (ft_puthex_big_count(num / 16, count) == -1)
			return (-1);
	}
	if (num % 16 < 10)
	{
		if (ft_putchar_count((num % 16) + 48, count) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_count((num % 16) + 55, count) == -1)
			return (-1);
	}
	return (1);
}
