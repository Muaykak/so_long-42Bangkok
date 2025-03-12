/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:56:17 by srussame          #+#    #+#             */
/*   Updated: 2024/08/26 18:56:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*temp;

	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof (char));
	if (temp == 0)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(temp + i) = *(s + i);
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
