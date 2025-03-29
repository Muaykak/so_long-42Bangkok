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

static t_map_object	*map_data_link_img_sub1(t_so_long **so_long, int x, int y)
{
	t_map_object	*object;

	object = (t_map_object *)ft_calloc(1, sizeof(t_map_object));
	if (object == NULL)
	{
		perror("Error\n\nmap_data_link_img(): ");
		free_so_long(so_long);
		exit(EXIT_FAILURE);
	}
	object->object_img = find_from_img_list((*so_long)->img_list,
			FLOOR);
	object->type = FLOOR;
	object->x = x;
	object->y = y;
	return (object);
}

static t_map_object	*map_data_link_img_sub2(t_so_long **so_long, int x, int y)
{
	t_map_object	*object;
	t_map_data		**temp;

	temp = (*so_long)->map_info->map_data;
	object = (t_map_object *)ft_calloc(1, sizeof(t_map_object));
	if (object == NULL)
	{
		perror("Error\n\nmap_data_link_img(): ");
		free_so_long(so_long);
		exit(EXIT_FAILURE);
	}
	object->object_img = find_from_img_list((*so_long)->img_list,
			temp[y][x].type);
	object->type = object->object_img->obj_type;
	object->x = x;
	object->y = y;
	return (object);
}

static void	map_data_link_img_sub3(t_so_long **so_long, int x, int y)
{
	t_map_object	*object;
	t_map_data		**temp;

	object = map_data_link_img_sub1(so_long, x, y);
	temp = (*so_long)->map_info->map_data;
	ft_lstadd_back(&(temp[y][x].object_list), ft_lstnew(&(*object)));
	if (temp[y][x].type != FLOOR)
	{
		object = map_data_link_img_sub2(so_long, x, y);
		ft_lstadd_back(&(temp[y][x].object_list),
			ft_lstnew(&(*object)));
		if (temp[y][x].type == PLAYER)
			(*so_long)->map_info->player = &(*object);
		else if (temp[y][x].type == COLLECT)
			ft_lstadd_front(&((*so_long)->map_info->collects),
				ft_lstnew(&(*object)));
		else if (temp[y][x].type == EXIT)
			(*so_long)->map_info->exit = &(*object);
	}
}

int	map_data_link_img(t_so_long **so_long)
{
	t_map_data		**temp;
	int				x;
	int				y;

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
			map_data_link_img_sub3(so_long, x, y);
			temp[y][x].map_coor.x = x * (*so_long)->grid_size;
			temp[y][x].map_coor.y = y * (*so_long)->grid_size;
			x++;
		}
		y++;
	}
	return (1);
}
