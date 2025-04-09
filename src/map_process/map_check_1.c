/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:24:29 by srussame          #+#    #+#             */
/*   Updated: 2025/03/17 23:24:31 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			map_char_check(char **map_char);

int			map_check_component(char **map_char);
int			map_check_rectangle(char **map);
int			map_check_minimum(char **map_char);

static int	map_check_minimum_sub1(int *count, char **map_char);

int	map_char_check(char **map_char)
{
	if (map_char == NULL)
		return (0);
	if (map_check_rectangle(map_char) == 0)
		return (0);
	if (map_check_component(map_char) == 0)
		return (0);
	if (map_check_minimum(map_char) == 0)
		return (0);
	return (1);
}

int	map_check_rectangle(char **map)
{
	size_t	line_size;
	int		i;

	i = 1;
	line_size = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != line_size)
		{
			ft_strerr("Error\n: The map must has rectangle shape\n");
			free_map_char(&map);
			return (0);
		}
		i++;
	}
	return (1);
}

/* The map can be composed of only these 5 characters:
	0 for an empty space,
	1 for a wall,
	C for a collectible,
	E for a map exit,
	P for the player’s starting position. */
int	map_check_component(char **map_char)
{
	int	x;
	int	y;

	y = 0;
	while (map_char[y] != NULL)
	{
		x = 0;
		while (map_char[y][x] != '\0')
		{
			if (map_char[y][x] != '1' && map_char[y][x] != '0'
				&& map_char[y][x] != 'P' && map_char[y][x] != 'E'
				&& map_char[y][x] != 'C')
			{
				ft_strerr("Error\n: The map can be composed of only these 5\n"
					"\'0\' \'1\' \'P\' \'C\' \'E\'\n");
				free_map_char(&map_char);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/* To be valid, a map must contain 1 exit, 1 starting position and at least 1
collectible. */
int	map_check_minimum(char **map_char)
{
	int	xy[2];
	int	count[3];

	if (map_char == NULL || *map_char == NULL)
		return (0);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	xy[1] = 0;
	while (map_char[xy[1]] != NULL)
	{
		xy[0] = 0;
		while (map_char[xy[1]][xy[0]] != '\0')
		{
			if (map_char[xy[1]][xy[0]] == 'P')
				count[0]++;
			if (map_char[xy[1]][xy[0]] == 'E')
				count[1]++;
			if (map_char[xy[1]][xy[0]] == 'C')
				count[2]++;
			xy[0]++;
		}
		xy[1]++;
	}
	return (map_check_minimum_sub1(count, map_char));
}

static int	map_check_minimum_sub1(int *count, char **map_char)
{
	if (count == NULL || map_char == NULL)
		return (0);
	if (count[0] != 1 || count[1] != 1 || count[2] < 1)
	{
		ft_strerr("Error\n: To be valid, a map must contain 1 exit, 1 starting "
			"position\n and at least 1 collectible.\n");
		free_map_char(&map_char);
		return (0);
	}
	return (1);
}
