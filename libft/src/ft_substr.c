/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:37:28 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 10:37:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	i = 0;
	while (start + i < start + len)
	{
		*(temp + i) = *(s + start + i);
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
