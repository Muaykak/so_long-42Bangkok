/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_first_paint_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:29:09 by srussame          #+#    #+#             */
/*   Updated: 2025/03/28 17:29:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_first_paint_sub1(t_map_data **temp, int x, int y, t_so_long **so_long)
{
	t_list	*list;

	list = temp[y][x].object_list;
	while (list != NULL)
	{
		paint_img_to_img((*so_long)->map_img, ((t_map_object *)list)->
			object_img, temp[y][x].map_coor.x, temp[y][x].map_coor.y);
		list = list->next;
	}
}

int	map_first_paint(t_so_long **so_long)
{
	t_map_data	**temp;
	int			x;
	int			y;

	if (so_long == NULL || *so_long == NULL)
		return (0);
	temp = (*so_long)->map_info->map_data;
	y = 0;
	while (y < (*so_long)->map_info->map_height)
	{
		x = 0;
		while (x < (*so_long)->map_info->map_width)
		{
			map_first_paint_sub1(temp, x, y, so_long);
			x++;
		}
		y++;
	}
	return (1);
}
