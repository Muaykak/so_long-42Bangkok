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
	if (target->type == WALL)
	{
		ft_printf("Hit the wall!\n");
		return (0);
	}
	new_list = 0;
	if (target->type != WALL)
	{
		player->x += x;
		player->y += y;
		ft_lstadd_front(&new_list, ft_lstnew(&(*target)));
		ft_lstadd_front(&new_list, ft_lstnew(&(*player)));
		(*so_long)->map_info->update_map = new_list;
	}
	return (1);
}

