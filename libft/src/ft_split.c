/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:05:33 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 12:05:34 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countsplit(char const *s, char c);
static int		ft_malloc_string(char **temp, char const *s, char c);
static void		ft_assign_string(char **temp, char const *s, char c);
static void		ft_free_split(char **save);

char	**ft_split(char const *s, char c)
{
	size_t	k;
	char	**temp;

	if (!s)
		return (0);
	k = ft_countsplit(s, c);
	temp = (char **)malloc((k + 1) * sizeof(char *));
	if (!temp)
		return (0);
	temp[k] = 0;
	if (ft_malloc_string(temp, s, c) == 0)
	{
		ft_free_split(temp);
		return (0);
	}
	ft_assign_string(temp, s, c);
	return (temp);
}

static void	ft_free_split(char **save)
{
	size_t	i;

	i = 0;
	while (save[i] != 0)
	{
		free(save[i]);
		i++;
	}
	free(save);
}

static void	ft_assign_string(char **temp, char const *s, char c)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	while (s[i[1]] != '\0')
	{
		if (s[i[1]] != c && s[i[1]] != '\0')
		{
			i[2] = 0;
			while (s[i[1] + i[2]] != c && s[i[1] + i[2]] != '\0')
			{
				temp[i[0]][i[2]] = s[i[1] + i[2]];
				i[2]++;
			}
			temp[i[0]][i[2]] = '\0';
			i[1] += i[2];
			i[0]++;
		}
		else
			i[1]++;
	}
}

static int	ft_malloc_string(char **temp, char const *s, char c)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	while (s[i[1]] != '\0')
	{
		if (s[i[1]] != c && s[i[1]] != '\0')
		{
			i[2] = 0;
			while (s[i[1] + i[2]] != c && s[i[1] + i[2]] != '\0')
				i[2]++;
			temp[i[0]] = (char *)malloc(i[2] + 1);
			if (!temp[i[0]])
				return (0);
			i[1] += i[2];
			i[0]++;
		}
		else
			i[1]++;
	}
	return (1);
}

static size_t	ft_countsplit(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (!s)
		return (count);
	i = 0;
	while (*(s + i) == c && *(s + i) != '\0')
		i++;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}
