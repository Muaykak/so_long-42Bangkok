/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_map_to_window_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:46:30 by srussame          #+#    #+#             */
/*   Updated: 2025/03/29 17:46:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_map_to_window(t_so_long *so_long)
{
	t_map_data	*player_pos;
	t_offset	*offset;
	int			cal_x;
	int			cal_y;

	if (so_long == NULL)
		return ;
	player_pos = &((so_long->map_info->map_data)[so_long->map_info->player->y]
		[so_long->map_info->player->x]);
	offset = &(so_long->window->offset);
	cal_x = player_pos->map_coor.x - (so_long->window->width / 2);
	if (cal_x < 0)
		cal_x = 0;
	else if (cal_x > offset->max_x)
		cal_x = offset->max_x;
	cal_y = player_pos->map_coor.y - (so_long->window->height / 2);
	if (cal_y < 0)
		cal_y = 0;
	else if (cal_y > offset->max_y)
		cal_y = offset->max_y;
	offset->x = cal_x;
	offset->y = cal_y;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->window->win_ptr,
		so_long->map_img->img_ptr, -1 * offset->x, -1 * offset->y);
}
