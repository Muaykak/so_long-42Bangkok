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

void	map_re_paint_sub1(t_so_long **so_long, t_map_data *target)
{
	t_list			*list;
	t_map_object	*content;

	list = target->object_list;
	while (list != NULL)
	{
		content = ((t_map_object *)(list->content));
		if (content->type != COLLECT || content->status != TRUE)
		{
			if (content->type != FLOOR && content->status == TRUE
				&& content->object_img->next != NULL)
				paint_img_to_img((*so_long)->map_img, content->object_img->next,
					target->map_coor.x, target->map_coor.y);
			else
				paint_img_to_img((*so_long)->map_img, content->object_img,
					target->map_coor.x, target->map_coor.y);
		}
		list = list->next;
	}
}

int	map_re_paint(t_so_long **so_long)
{
	t_list		*map_update;
	t_map_data	*target;

	if (so_long == NULL || *so_long == NULL
		|| (*so_long)->map_info->update_map == NULL)
		return (0);
	map_update = (*so_long)->map_info->update_map;
	while (map_update != NULL)
	{
		target = ((t_map_data *)map_update->content);
		map_re_paint_sub1(so_long, target);
		map_update = map_update->next;
	}
	ft_lstclear(&((*so_long)->map_info->update_map), &free_collect);
	return (1);
}
