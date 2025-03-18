/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:40:36 by srussame          #+#    #+#             */
/*   Updated: 2025/03/18 13:40:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_wall_check(t_map_data **map_data);

static int	map_wall_check_sub1(t_map_data **map_data, int y);
static int	map_wall_check_sub2(t_map_data **map_data, int x);

int	map_wall_check(t_map_data **map_data)
{
	if (map_data == NULL || *map_data == NULL)
		return (0);
	if (map_wall_check_sub1(map_data, 0) == 0)
		return (0);
	if (map_wall_check_sub1(map_data, (*map_data)->map_height - 1) == 0)
		return (0);
	if (map_wall_check_sub2(map_data, 0)== 0)
		return (0);
	if (map_wall_check_sub2(map_data, (*map_data)->map_width - 1) == 0)
		return (0);
	return (1);
}

static int	map_wall_check_sub2(t_map_data **map_data, int x)
{
	int	y;

	y = 0;
	while (y < (*map_data)->map_height)
	{
		if (((*map_data)->map_char)[y][x] != '1')
		{
			ft_printf("Error\nThe map must be enclosed by walls.\n\n");
			free_map_char((*map_data)->map_char);
			free(*map_data);
			*map_data = NULL;
			return (0);
		}
		y++;
	}
	return (1);
}

static int	map_wall_check_sub1(t_map_data **map_data, int y)
{
	int	x;

	x = 0;
	while (x < (*map_data)->map_width)
	{
		if (((*map_data)->map_char)[y][x] != '1')
		{
			ft_printf("Error\nThe map must be enclosed by walls.\n\n");
			free_map_char((*map_data)->map_char);
			free(*map_data);
			*map_data = NULL;
			return (0);
		}
		x++;
	}
	return (1);
}
