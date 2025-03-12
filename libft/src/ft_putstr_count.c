/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:47 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 15:01:20 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count(char *str, int *count)
{
	int	i;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*count = *count + 6;
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		*count = *count + 1;
		i++;
	}
	return (1);
}
