/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:47 by srussame          #+#    #+#             */
/*   Updated: 2024/08/26 14:22:50 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index[2];

	if (size == 0)
		return (ft_strlen(src));
	index[0] = 0;
	while (index[0] < size && *(dst + index[0]) != '\0')
		index[0]++;
	if (*(dst + index[0]) != '\0')
		return (index[0] + ft_strlen(src));
	index[1] = 0;
	while (index[0] + index[1] < size - 1 \
	&& *(src + index[1]) != '\0')
	{
		*(dst + index[0] + index[1]) = *(src + index[1]);
		index[1]++;
	}
	*(dst + index[0] + index[1]) = '\0';
	while (*(src + index[1]) != '\0')
		index[1]++;
	return (index[0] + index[1]);
}
