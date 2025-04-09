/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:48:42 by srussame          #+#    #+#             */
/*   Updated: 2025/03/17 23:48:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_info(t_map_info **map_info);
void	free_map_data(t_map_data ***map_data, t_map_info *map_info);
void	free_map_char(char ***map_char);
void	free_collect(void *collect);
void	free_path_data(void *path_data);

void	free_collect(void *collect)
{
	if (collect)
		(void)collect;
}

void	free_map_char(char ***map_char)
{
	int	i;

	if (map_char == NULL || (*map_char) == NULL)
		return ;
	i = 0;
	while ((*map_char)[i] != NULL)
		i++;
	while (i >= 0)
		free((*map_char)[i--]);
	if ((*map_char))
		free((*map_char));
	((*map_char)) = NULL;
	return ;
}

void	free_map_data(t_map_data ***map_data, t_map_info *map_info)
{
	int	x;
	int	y;

	if (map_data == NULL || *map_data == NULL || map_info == NULL)
		return ;
	y = map_info->map_height;
	while (y >= 0)
	{
		x = map_info->map_width - 1;
		while (y < map_info->map_height && x >= 0)
		{
			if ((*map_data)[y][x].object_list != NULL)
				ft_lstclear(&((*map_data)[y][x].object_list), &free_path_data);
			x--;
		}
		free((*map_data)[y]);
		y--;
	}
	if ((*map_data))
		free((*map_data));
	(*map_data) = NULL;
}

void	free_map_info(t_map_info **map_info)
{
	if (map_info == NULL || *map_info == NULL)
		return ;
	if ((*map_info)->map_data != NULL)
		free_map_data(&((*map_info)->map_data), *map_info);
	if ((*map_info)->path_collects != NULL)
		ft_lstclear(&((*map_info)->path_collects), &free_collect);
	if ((*map_info)->collects != NULL)
		ft_lstclear(&((*map_info)->collects), &free_collect);
	free(*map_info);
	(*map_info) = NULL;
	return ;
}

void	free_path_data(void *path_data)
{
	if (path_data)
		free(path_data);
}
