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

# include "so_long.h"

int	check_all_collect(t_so_long *so_long)
{
	t_list			*lst;
	t_map_object	*temp;
	int		count;

	lst = so_long->map_info->collects;
	count = 0;
	while (lst != NULL)
	{
		temp = (t_map_object *)(lst->content);
		if (temp->status == TRUE)
			count++;
		lst = lst->next;
	}
	if (count == ft_lstsize(so_long->map_info->collects))
		return (-1);
	return (count);
}

int	player_move(t_so_long **so_long, int x, int y)
{
	t_map_data	**map;
	t_map_object	*player;
	t_list		*new_list;
	t_map_object	*target;
	t_map_object	*exit;

	map = (*so_long)->map_info->map_data;
	player = (*so_long)->map_info->player;
	target = ((t_map_object *)(ft_lstlast(map[player->y + y]
		[player->x + x].object_list)->content));
	if (target->type == WALL)
	{
		ft_printf("Hit the wall!\n");
		return (0);
	}
	new_list = 0;
	if (target->type != WALL)
	{
		ft_lstadd_front(&new_list, ft_lstnew(&(map[player->y][player->x])));
		ft_lstadd_front(&new_list, ft_lstnew(&(map[player->y + y][player->x + x])));
		if (target->type == COLLECT && target->status == FALSE)
		{
			target->status = TRUE;
			if (check_all_collect(*so_long) == -1)
			{
				exit = (*so_long)->map_info->exit;
				exit->status = TRUE;
				player->status = TRUE;
				ft_lstadd_front(&new_list, ft_lstnew(&(map[exit->y][exit->x])));
			}
		}
		ft_move_to_newlist(&(map[player->y][player->x].object_list),
			find_from_object_lst(map[player->y][player->x].object_list
			, PLAYER), &(map[player->y + y][player->x + x].object_list),
			&ft_lstadd_back);
		player->x += x;
		player->y += y;
		(*so_long)->map_info->update_map = new_list;
	}
	return (1);
}

