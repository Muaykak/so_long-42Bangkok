/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:23:56 by srussame          #+#    #+#             */
/*   Updated: 2024/08/26 16:23:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i[2];

	if (*little == '\0')
		return ((char *)big);
	i[0] = 0;
	while (i[0] < len && *(big + i[0]) != '\0')
	{
		i[1] = 0;
		while (*(big + i[0] + i[1]) == *(little + i[1]) \
		&& *(big + i[0] + i[1]) != '\0' && *(little + i[1]) != '\0' \
		&& i[0] + i[1] < len)
			i[1]++;
		if (*(little + i[1]) == '\0')
			return ((char *)(big + i[0]));
		i[0]++;
	}
	return (NULL);
}
