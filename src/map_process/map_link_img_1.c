/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_link_img_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:42:59 by srussame          #+#    #+#             */
/*   Updated: 2025/03/27 22:43:02 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	create_map_img(t_so_long **so_long)
{
	(*so_long)->map_img = create_image((*so_long)->mlx_ptr,
		(*so_long)->canvas_x, (*so_long)->canvas_y);
	if ((*so_long)->map_img == NULL)
	{
		free_so_long(so_long);
		return (0);
	}
	return (1);
}

int map_data_link_img(t_so_long **so_long)
{
	t_map_data	**temp;
	int			x;
	int			y;

	if (*so_long == NULL || so_long == NULL)
		return (0);
	temp = (*so_long)->map_info->map_data;
	y = 0;
	if (create_map_img(so_long) == 0)
		exit(EXIT_FAILURE);
	while (y < (*so_long)->map_info->map_height)
	{
		x = 0;
		while (x < (*so_long)->map_info->map_width)
		{
			temp[y][x].object_img =
				find_from_img_list((*so_long)->img_list, temp[y][x].type);
			temp[y][x].map_coor.x = x * (*so_long)->grid_size;
			temp[y][x].map_coor.y = y * (*so_long)->grid_size;
			x++;
		}
		y++;
	}
	return (1);
}
