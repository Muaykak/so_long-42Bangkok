/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:49:02 by srussame          #+#    #+#             */
/*   Updated: 2025/04/09 10:49:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		add_fill_list(t_list **fill_list, t_map_info *map_info,
				t_map_path *mark);

static void	add_down_fill_list(t_list **fill_list, t_map_info *map_info,
				t_map_path *mark);
static void	add_up_fill_list(t_list **fill_list, t_map_info *map_info,
				t_map_path *mark);
static void	add_right_fill_list(t_list **fill_list, t_map_info *map_info,
				t_map_path *mark);
static void	add_left_fill_list(t_list **fill_list, t_map_info *map_info,
				t_map_path *mark);

static void	add_left_fill_list(t_list **fill_list, t_map_info *map_info,
		t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y][mark->x - 1].type == WALL
		|| (map_info->map_data)[mark->y][mark->x - 1].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x - 1;
	new_fill->y = mark->y;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

static void	add_right_fill_list(t_list **fill_list, t_map_info *map_info,
		t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y][mark->x + 1].type == WALL
		|| (map_info->map_data)[mark->y][mark->x + 1].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x + 1;
	new_fill->y = mark->y;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

static void	add_up_fill_list(t_list **fill_list, t_map_info *map_info,
		t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y - 1][mark->x].type == WALL
		|| (map_info->map_data)[mark->y - 1][mark->x].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x;
	new_fill->y = mark->y - 1;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

static void	add_down_fill_list(t_list **fill_list, t_map_info *map_info,
		t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y + 1][mark->x].type == WALL
		|| (map_info->map_data)[mark->y + 1][mark->x].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x;
	new_fill->y = mark->y + 1;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

void	add_fill_list(t_list **fill_list, t_map_info *map_info,
		t_map_path *mark)
{
	if (fill_list == NULL || map_info == NULL)
		return ;
	add_up_fill_list(fill_list, map_info, mark);
	add_down_fill_list(fill_list, map_info, mark);
	add_left_fill_list(fill_list, map_info, mark);
	add_right_fill_list(fill_list, map_info, mark);
}
