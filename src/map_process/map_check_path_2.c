/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:43:16 by srussame          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			map_check_path(t_map_info **map_info);
// int			map_check_path_data(t_list **path_data, int path_x, int path_y);

int			map_check_path_data(t_map_data **map_data, int path_x, int path_y);

static int	map_check_path_sub2(t_map_info **map_info);

void		reset_check_path(t_map_info *map_info);

static int	map_check_path_sub2(t_map_info **map_info)
{
	t_list		*temp;
	t_map_data	*temp_2;

	temp = (*map_info)->path_collects;
	while (temp != NULL)
	{
		temp_2 = ((t_map_data *)(temp->content));
		if (temp_2->path_check == FALSE)
		{
			free_map_info(map_info);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	map_check_path(t_map_info **map_info)
{
	if (map_info == NULL || (*map_info) == NULL)
		return (0);
	map_check_path_sub1((*map_info), (*map_info)->path_player->x,
		(*map_info)->path_player->y);
	if ((*map_info)->path_exit->path_check == FALSE)
	{
		free_map_info(map_info);
		ft_strerr("Error\n: No valid path to complete the game\n");
		return (0);
	}
	if (map_check_path_sub2(map_info) == 0)
	{
		ft_strerr("Error\n: No valid path to complete the game\n");
		return (0);
	}
	reset_check_path(*map_info);
	return (1);
}

void	reset_check_path(t_map_info *map_info)
{
	int			y;
	int			x;
	t_map_data	**map_data;

	if (map_info == NULL || map_info->map_data == NULL)
		return ;
	map_data = map_info->map_data;
	y = 0;
	while (y < map_info->map_height)
	{
		x = 0;
		while (x < map_info->map_width)
		{
			map_data[y][x].path_check = FALSE;
			x++;
		}
		y++;
	}
	return ;
}

int	map_check_path_data(t_map_data **map_data, int path_x, int path_y)
{
	if (map_data == NULL)
		return (0);
	if (map_data[path_y][path_x].path_check == TRUE)
		return (1);
	map_data[path_y][path_x].path_check = TRUE;
	return (0);
}
