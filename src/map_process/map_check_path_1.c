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

static int		map_path_up(int path_x, int path_y, t_map_data **map_data);
static int		map_path_down(int path_x, int path_y, t_map_data **map_data);
static int		map_path_left(int path_x, int path_y, t_map_data **map_data);
static int		map_path_right(int path_x, int path_y, t_map_data **map_data);

void			map_check_path_sub1(t_map_data **map_data,
					int path_x, int path_y);

/* return 1 if this path is already pass*/
int		map_check_path_data(t_list **path_data, int path_x, int path_y)
{
	t_list		*temp;
	t_map_path	*new_path;

	if (path_data == NULL)
		return (0);
	temp = *path_data;
	while (temp != NULL)
	{
		if (((t_map_path *)(temp->content))->x == path_x
			&& ((t_map_path *)(temp->content))->y == path_y)
			return (1);
		temp = temp->next;
	}
	new_path = (t_map_path *)ft_calloc(1, sizeof(t_map_path));
	if (new_path == NULL)
	{
		ft_lstclear(path_data, &free_collect);
		*path_data = 0;
		perror("Error\nmap_check_path_data(): ");
		return (0);
	}
	new_path->x = path_x;
	new_path->y = path_y;
	ft_lstadd_front(path_data, ft_lstnew(&new_path[0]));
	return (0);
}

void	map_check_path_sub1(t_map_data **map_data, int path_x, int path_y)
{
	if (map_data == NULL || (*map_data) == NULL)
		return ;
	if (map_check_path_data(&((*map_data)->path_data), path_x, path_y) == 1)
		return ;	
	if (path_x == (*map_data)->path_dest->x && path_y == (*map_data)->path_dest->y)
	{
		(*map_data)->path_dest->status = 1;
		return ;
	}
	if (map_path_up(path_x, path_y, map_data) == 1)
		map_check_path_sub1(map_data, path_x, path_y - 1);
	if (map_path_down(path_x, path_y, map_data) == 1)
		map_check_path_sub1(map_data, path_x, path_y + 1);
	if (map_path_left(path_x, path_y, map_data) == 1)
		map_check_path_sub1(map_data, path_x - 1, path_y);
	if (map_path_right(path_x, path_y, map_data) == 1)
		map_check_path_sub1(map_data, path_x + 1, path_y);
	return ;
}

static int	map_path_right(int path_x, int path_y, t_map_data **map_data)
{
	if (((*map_data)->map_char)[path_y][path_x + 1] != '1'
		&& (*map_data)->path_dest->status == 0)
		return (1);
	else
		return (0);
}

static int	map_path_left(int path_x, int path_y, t_map_data **map_data)
{
	if (((*map_data)->map_char)[path_y][path_x - 1] != '1'
		&& (*map_data)->path_dest->status == 0)
		return (1);
	else
		return (0);
}

static int	map_path_up(int path_x, int path_y, t_map_data **map_data)
{
	if (((*map_data)->map_char)[path_y - 1][path_x] != '1'
		&& (*map_data)->path_dest->status == 0)
		return (1);
	else
		return (0);
}

static int	map_path_down(int path_x, int path_y, t_map_data **map_data)
{
	if (((*map_data)->map_char)[path_y + 1][path_x] != '1'
		&& (*map_data)->path_dest->status == 0)
		return (1);
	else
		return (0);
}
