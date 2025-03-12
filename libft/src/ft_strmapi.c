/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:46:21 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 22:46:25 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	k;
	char	*temp;

	k = ft_strlen(s);
	temp = (char *)malloc((k + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	i = 0;
	while (i < k)
	{
		*(temp + i) = (*f)(i, *(s + i));
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
