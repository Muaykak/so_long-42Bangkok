/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:31:17 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 11:31:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_index_no_set(char const *s1, char const *set);
static int		ft_check_isset(char c, char const *set);
static void		ft_assigntrim(size_t i, size_t k, char *temp, char const *s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	k;

	k = ft_index_no_set(s1, set);
	i = 0;
	while (ft_check_isset(*(s1 + i), set) == 1 && i < k)
		i++;
	if ((i == k && ft_check_isset(*(s1 + i), set) == 1) || ft_strlen(s1) == 0)
		temp = (char *)malloc(1 * sizeof(char));
	else
		temp = (char *)malloc(((k - i) + 2) * sizeof(char));
	if (temp == 0)
		return (0);
	if ((i == k && ft_check_isset(*(s1 + i), set) == 1) || ft_strlen(s1) == 0)
		temp[0] = '\0';
	else
		ft_assigntrim(i, k, temp, s1);
	return (temp);
}

static void	ft_assigntrim(size_t i, size_t k, char *temp, char const *s1)
{
	size_t	j;

	j = 0;
	if (i != k)
	{
		while (i + j <= k && i != k)
		{
			temp[j] = s1[i + j];
			j++;
		}
		temp[j] = '\0';
		return ;
	}
	temp[0] = s1[i];
	temp[1] = '\0';
}

static size_t	ft_index_no_set(char const *s1, char const *set)
{
	size_t	i;

	if (set == 0 || s1 == 0)
		return (0);
	i = ft_strlen(s1);
	if (i != 0)
		i--;
	while (ft_check_isset(*(s1 + i), set) == 1 && i != 0)
		i--;
	return (i);
}

static int	ft_check_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}
