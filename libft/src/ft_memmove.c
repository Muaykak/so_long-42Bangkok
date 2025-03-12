/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:27:11 by srussame          #+#    #+#             */
/*   Updated: 2024/08/25 15:27:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (dest);
	if (dest > src && n != 0)
	{
		n--;
		while (n > 0)
		{
			*((unsigned char *)(dest + n)) = *((unsigned char *)(src + n));
			n--;
		}
		*((unsigned char *)(dest + n)) = *((unsigned char *)(src + n));
	}
	else if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}
	return (dest);
}
