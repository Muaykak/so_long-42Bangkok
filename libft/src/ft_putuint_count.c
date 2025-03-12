/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:21:59 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 18:08:34 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuint_count(unsigned int num, int *count)
{
	if (num / 10 != 0)
	{
		if (ft_putuint_count((num / 10), count) == -1)
			return (-1);
	}
	if (ft_putchar_count((char)((num % 10) + 48), count) == -1)
		return (-1);
	return (1);
}
