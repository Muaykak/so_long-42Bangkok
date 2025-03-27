/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:18:36 by srussame          #+#    #+#             */
/*   Updated: 2025/03/27 23:18:37 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_first_paint(t_so_long **so_long)
{
	t_map_data	**temp;
	int			x;
	int			y;

	if (so_long == NULL || *so_long == NULL)
		return (0);
	if ((*so_long)->map_img == NULL)
	{
		free_so_long(so_long);
		exit(EXIT_FAILURE);
	}
	temp = (*so_long)->map_info->map_data;
	y = 0;
	while (y < (*so_long)->map_info->map_height)
	{
		x = 0;
		while (x < (*so_long)->map_info->map_width)
		{
			if (temp[y][x].type != FLOOR)
				paint_img_to_img((*so_long)->map_img,
					find_from_img_list((*so_long)->img_list, FLOOR),
					temp[y][x].map_coor.x, temp[y][x].map_coor.y);
			paint_img_to_img((*so_long)->map_img, temp[y][x].object_img,
				temp[y][x].map_coor.x, temp[y][x].map_coor.y);
			x++;
		}
		y++;
	}
	return (1);
}
