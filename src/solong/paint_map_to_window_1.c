/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_to_window_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:24 by srussame          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:37 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_calculate_sub1(t_so_long *so_long)
{
	t_draw_map	*draw;

	if (so_long == NULL)
		return ;
	draw = &(so_long->window->draw);
	draw->end_x = draw->start_x + draw->range_x;
	draw->end_y = draw->start_y + draw->range_y;
	if (draw->end_x == so_long->map_info->map_width)
		draw->off_x = so_long->window->width
			- (draw->range_x * so_long->grid_size);
	else
		draw->off_x = 0;
	if (draw->end_y == so_long->map_info->map_height)
		draw->off_y = so_long->window->height
			- (draw->range_y * so_long->grid_size);
	else
		draw->off_y = 0;
}

static void	draw_calculate(t_so_long *so_long)
{
	t_draw_map	*draw;

	if (so_long == NULL)
		return ;
	draw = &(so_long->window->draw);
	draw->start_x = so_long->map_info->player->x - (draw->range_x / 2);
	if (draw->start_x + draw->range_x > so_long->map_info->map_width)
		draw->start_x = so_long->map_info->map_width - draw->range_x;
	if (draw->start_x < 0)
		draw->start_x = 0;
	draw->start_y = so_long->map_info->player->y - (draw->range_y / 2);
	if (draw->start_y + draw->range_y > so_long->map_info->map_height)
		draw->start_y = so_long->map_info->map_height - draw->range_y;
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw_calculate_sub1(so_long);
}

static void	paint_map_to_window_sub1(t_so_long *so_long, int map_x, int map_y)
{
	t_list			*object_list;
	t_map_object	*object;
	t_draw_map		*draw;

	object_list = (so_long->map_info->map_data)[map_y][map_x].object_list;
	draw = &so_long->window->draw;
	while (object_list != NULL)
	{
		object = (t_map_object *)(object_list->content);
		if (object->type != COLLECT || object->status != TRUE)
		{
			if (object->type != FLOOR && object->status == TRUE
				&& object->object_img->next != NULL)
				paint_img_to_img(so_long->window->img, object->object_img
					->next, ((map_x - draw->start_x) * so_long->grid_size)
					+ draw->off_x, ((map_y - draw->start_y) * so_long
						->grid_size) + draw->off_y);
			else
				paint_img_to_img(so_long->window->img, object->object_img,
					((map_x - draw->start_x) * so_long->grid_size) + draw
					->off_x, ((map_y - draw->start_y) * so_long->grid_size)
					+ draw->off_y);
		}
		object_list = object_list->next;
	}
}

void	paint_map_to_window(t_so_long *so_long)
{
	int				map_x;
	int				map_y;

	if (so_long == NULL)
		return ;
	draw_calculate(so_long);
	map_y = so_long->window->draw.start_y;
	while (map_y < so_long->window->draw.end_y)
	{
		map_x = so_long->window->draw.start_x;
		while (map_x < so_long->window->draw.end_x)
		{
			paint_map_to_window_sub1(so_long, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->window->win_ptr,
		so_long->window->img->img_ptr, 0, 0);
}
