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

void	player_move_swap(t_map_data *player, t_map_data *dest, int x, int y)
{
	t_map_data temp;

	temp = *player;
	player->now_x = player->now_x + x;
	player->now_y = player->now_y + y;
	dest->now_x = temp.now_x;
	dest->now_y = temp.now_y;
}

int	player_move(t_so_long **so_long, int x, int y)
{
	t_map_data	**map;
	t_map_data	*player;
	t_list		*new_list;
	t_map_data	*target;

	map = (*so_long)->map_info->map_data;
	player = (*so_long)->map_info->player;
	target = &(map[player->now_y + y][player->now_x + x]);
	if (target->type == WALL)
	{
		ft_printf("Hit the wall!\n");
		return (0);
	}
	new_list = 0;
	if (target->type != WALL)
	{
		player_move_swap(player, target, x, y);
		ft_lstadd_front(&new_list, ft_lstnew(&(*target)));
		ft_lstadd_front(&new_list, ft_lstnew(&(*player)));
		(*so_long)->map_info->update_map = new_list;
	}
	return (1);
}

