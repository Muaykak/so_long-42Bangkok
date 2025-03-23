/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:24:13 by srussame          #+#    #+#             */
/*   Updated: 2025/03/18 22:24:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_path_up(int path_x, int path_y, t_map_info *map_info);
static int	map_path_down(int path_x, int path_y, t_map_info *map_info);
static int	map_path_left(int path_x, int path_y, t_map_info *map_info);
static int	map_path_right(int path_x, int path_y, t_map_info *map_info);

void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y);

void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y)
{
	if (map_info == NULL)
		return ;
	if (path_x == map_info->path_dest->x && path_y == map_info->path_dest->y)
	{
		map_info->path_dest->status = TRUE;
		ft_lstclear(&(map_info->path_data), &free_path_data);
		map_info->path_data = 0;
		return ;
	}
	if (map_check_path_data(&(map_info->path_data), path_x, path_y) == 1)
		return ;
	if (map_path_up(path_x, path_y, map_info) == 1)
		map_check_path_sub1(map_info, path_x, path_y - 1);
	if (map_path_down(path_x, path_y, map_info) == 1)
		map_check_path_sub1(map_info, path_x, path_y + 1);
	if (map_path_left(path_x, path_y, map_info) == 1)
		map_check_path_sub1(map_info, path_x - 1, path_y);
	if (map_path_right(path_x, path_y, map_info) == 1)
		map_check_path_sub1(map_info, path_x + 1, path_y);
	return ;
}

static int	map_path_right(int path_x, int path_y, t_map_info *map_info)
{
	if ((map_info->map_data)[path_y][path_x + 1].type != WALL
		&& map_info->path_dest->status == FALSE)
			return (1);
	else
		return (0);
}

static int	map_path_left(int path_x, int path_y, t_map_info *map_info)
{
	if ((map_info->map_data)[path_y][path_x - 1].type != WALL
		&& map_info->path_dest->status == FALSE)
			return (1);
	else
		return (0);
}

static int	map_path_up(int path_x, int path_y, t_map_info *map_info)
{
	if ((map_info->map_data)[path_y - 1][path_x].type != WALL
		&& map_info->path_dest->status == FALSE)
			return (1);
	else
		return (0);
}

static int	map_path_down(int path_x, int path_y, t_map_info *map_info)
{
	if ((map_info->map_data)[path_y + 1][path_x].type != WALL
		&& map_info->path_dest->status == FALSE)
			return (1);
	else
		return (0);
}
