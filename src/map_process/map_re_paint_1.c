/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_re_paint_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:29:56 by srussame          #+#    #+#             */
/*   Updated: 2025/03/28 17:29:57 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_re_paint(t_so_long **so_long)
{
	t_list		*map_update;
	t_map_data	*target;
	t_list		*list;

	if (so_long == NULL || *so_long == NULL
		|| (*so_long)->map_info->update_map == NULL)
		return (0);
	map_update = (*so_long)->map_info->update_map;
	while (map_update != NULL)
	{
		target = ((t_map_data *)map_update->content);
		list = target->object_list;
		while (list != NULL)
		{
			ft_printf("paint object: %d\ton map:%dx%d\n", ((t_map_object *)(list->content))->object_img->obj_type, target->x, target->y);
			paint_img_to_img((*so_long)->map_img, ((t_map_object *)(list->
				content))->object_img, target->map_coor.x, target->map_coor.y);
			list = list->next;			
		}
	ft_printf("update map: %p\n", map_update);
		map_update = map_update->next;
	}
	ft_lstclear(&((*so_long)->map_info->update_map), &free_collect);
	return (1);
}
