/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:24:35 by srussame          #+#    #+#             */
/*   Updated: 2025/03/28 13:24:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_collect(t_so_long *so_long)
{
	t_list			*lst;
	t_map_object	*temp;
	int				count;

	lst = so_long->map_info->collects;
	count = 0;
	while (lst != NULL)
	{
		temp = (t_map_object *)(lst->content);
		if (temp->status == TRUE)
			count++;
		lst = lst->next;
	}
	ft_printf(YELLOW_COLOR "COLLECTIBLES %d/%d\n" RESET_COLOR, count,
		ft_lstsize(so_long->map_info->collects));
	if (count == ft_lstsize(so_long->map_info->collects))
		return (-1);
	return (count);
}

void	player_move_sub2(t_so_long **so_long, int x, int y)
{
	t_map_object	*exit_object;
	t_map_object	*player;
	t_map_object	*target;
	t_map_data		**map;

	map = (*so_long)->map_info->map_data;
	player = (*so_long)->map_info->player;
	target = ((t_map_object *)(ft_lstlast(map[player->y + y][player->x
					+ x].object_list)->content));
	target->status = TRUE;
	if (check_all_collect(*so_long) == -1)
	{
		exit_object = (*so_long)->map_info->exit;
		exit_object->status = TRUE;
		ft_printf(GREEN_COLOR "collected all collectibles!\n" RESET_COLOR);
		player->status = TRUE;
	}
}

int	player_move(t_so_long **so_long, int x, int y)
{
	t_map_data		**map;
	t_map_object	*player;
	t_map_object	*target;

	map = (*so_long)->map_info->map_data;
	player = (*so_long)->map_info->player;
	target = ((t_map_object *)(ft_lstlast(map[player->y + y][player->x
					+ x].object_list)->content));
	if (target->type == WALL)
	{
		ft_printf(RED_COLOR "Hit the wall!\n" RESET_COLOR);
		return (0);
	}
	if (target->type == COLLECT && target->status == FALSE)
		player_move_sub2(so_long, x, y);
	ft_move_to_newlist(&(map[player->y][player->x].object_list),
		find_from_object_lst(map[player->y][player->x].object_list, PLAYER),
		&(map[player->y + y][player->x + x].object_list), &ft_lstadd_back);
	player->x += x;
	player->y += y;
	return (1);
}
