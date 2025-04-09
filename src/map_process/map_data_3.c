/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:11:10 by srussame          #+#    #+#             */
/*   Updated: 2025/03/22 13:11:11 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_data_put_xy(t_map_info *map_info, char **map_char);
int			get_map_data(char *filepath, t_map_info **map_info);
static void	get_map_data_sub3(t_map_info **map_info, char **map_char);
static void	get_map_data_sub1(t_map_info **map_info, char **map_char, int y,
				int x);
static void	get_map_data_sub2(t_map_info **map_info, char **map_char, int y,
				int x);

static void	get_map_data_sub2(t_map_info **map_info, char **map_char, int y,
		int x)
{
	if (map_char[y][x] == 'E')
	{
		((*map_info)->map_data)[y][x].type = EXIT;
		((*map_info)->map_data)[y][x].x = x;
		((*map_info)->map_data)[y][x].y = y;
		((*map_info)->path_exit) = &(((*map_info)->map_data)[y][x]);
	}
	else if (map_char[y][x] == 'C')
	{
		((*map_info)->map_data)[y][x].type = COLLECT;
		((*map_info)->map_data)[y][x].x = x;
		((*map_info)->map_data)[y][x].y = y;
		ft_lstadd_back(&((*map_info)->path_collects),
			ft_lstnew(&(((*map_info)->map_data)[y][x])));
		if ((t_map_data *)(ft_lstlast((*map_info)->path_collects)->content)
			!= &(((*map_info)->map_data)[y][x]))
		{
			perror("Error\nget_map_data_sub2(): ");
			ft_lstclear(&(*map_info)->path_collects, &free_collect);
		}
	}
}

static void	get_map_data_sub1(t_map_info **map_info, char **map_char, int y,
		int x)
{
	if (map_char[y][x] == '0')
	{
		((*map_info)->map_data)[y][x].type = FLOOR;
		((*map_info)->map_data)[y][x].x = x;
		((*map_info)->map_data)[y][x].y = y;
	}
	else if (map_char[y][x] == '1')
	{
		((*map_info)->map_data)[y][x].type = WALL;
		((*map_info)->map_data)[y][x].x = x;
		((*map_info)->map_data)[y][x].y = y;
	}
	else if (map_char[y][x] == 'P')
	{
		((*map_info)->map_data)[y][x].type = PLAYER;
		((*map_info)->map_data)[y][x].x = x;
		((*map_info)->map_data)[y][x].y = y;
		((*map_info)->path_player) = &(((*map_info)->map_data)[y][x]);
	}
}

static void	get_map_data_sub3(t_map_info **map_info, char **map_char)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*map_info)->map_height)
	{
		x = 0;
		while (x < (*map_info)->map_width)
		{
			get_map_data_sub1(map_info, map_char, y, x);
			get_map_data_sub2(map_info, map_char, y, x);
			x++;
		}
		y++;
	}
}

int	get_map_data(char *filepath, t_map_info **map_info)
{
	char	**map_char;

	map_char = get_map_char(filepath);
	if (map_char == NULL || map_char_check(map_char) == 0)
		return (0);
	map_data_put_xy(*map_info, map_char);
	(*map_info)->map_data = get_empty_map_data(map_char);
	if ((*map_info)->map_data == NULL)
		return (0);
	get_map_data_sub3(map_info, map_char);
	free_map_char(&map_char);
	if ((*map_info)->path_collects == NULL)
		return (0);
	return (1);
}

static void	map_data_put_xy(t_map_info *map_info, char **map_char)
{
	map_info->map_width = ft_strlen(map_char[0]);
	while (map_char[map_info->map_height] != NULL)
		map_info->map_height++;
}
