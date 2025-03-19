/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:43:16 by srussame          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_path(t_map_data **map_data);

int	map_check_path(t_map_data **map_data)
{
	t_list	*temp;
	if (map_data == NULL || *map_data == NULL)
		return (0);
	(*map_data)->path_dest = &((*map_data)->exit);
	map_check_path_sub1(map_data, (*map_data)->player.x, (*map_data)->player.y);
	ft_lstclear(&((*map_data)->path_data), &free_collect);
	(*map_data)->path_data = 0;
	if ((*map_data)->path_dest->status == 0)
	{
		free_map_data(map_data);
		return (0);
	}
	temp = (*map_data)->collect_pos;
	while (temp != NULL)
	{
		(*map_data)->path_dest = ((t_map_object *)(temp->content));
		map_check_path_sub1(map_data, (*map_data)->player.x,
			(*map_data)->player.y);
		ft_lstclear(&((*map_data)->path_data), &free_collect);
		(*map_data)->path_data = 0;
		if ((*map_data)->path_dest->status == 0)
		{
			free_map_data(map_data);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

