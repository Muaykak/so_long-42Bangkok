/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:10:53 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 11:10:55 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	i;
	size_t	k;

	temp = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)) * sizeof(char));
	if (temp == 0)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(temp + i) = *(s1 + i);
		i++;
	}
	k = 0;
	while (*(s2 + k) != '\0')
	{
		*(temp + i + k) = *(s2 + k);
		k++;
	}
	*(temp + i + k) = '\0';
	return (temp);
}
