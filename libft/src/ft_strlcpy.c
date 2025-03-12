/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:37:45 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 23:37:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	while (index < size - 1 && *(src + index) != '\0')
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = '\0';
	return (ft_strlen(src));
}
