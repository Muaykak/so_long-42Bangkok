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

/* remove from the list in map*/


int	player_move(t_so_long **so_long, int x, int y)
{
	t_map_data	**map;
	t_map_object	*player;
	t_list		*new_list;
	t_map_object	*target;

	map = (*so_long)->map_info->map_data;
	player = (*so_long)->map_info->player;
	target = ((t_map_object *)(ft_lstlast(map[player->y + y]
		[player->x + x].object_list)->content));
	ft_printf("player old pos: %dx%d\n", player->x, player->y);
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
		ft_move_to_newlist(&(map[player->y][player->x].object_list),
			find_from_object_lst(map[player->y][player->x].object_list
			, PLAYER), &(map[player->y + y][player->x + x].object_list),
			&ft_lstadd_back);
		player->x += x;
		player->y += y;
		(*so_long)->map_info->update_map = new_list;
		ft_printf("player new pos: %dx%d\n", player->x, player->y);
	}
	return (1);
}

