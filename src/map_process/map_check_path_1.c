/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:24:13 by srussame          #+#    #+#             */
/*   Updated: 2025/03/18 22:24:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_fill_list_error(t_list **fill_list, t_map_info *map_info)
{
	perror("Error\n\nmap_check_path_sub1()");
	ft_lstclear(fill_list, &free_path_data);
	free_map_info(&map_info);
	exit(EXIT_FAILURE);
}

void	ft_lstremove_top(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	(*lst) = (*lst)->next;
	ft_lstdelone(temp, &free_path_data);
}

int	mark_check_path(t_list **fill_list, t_map_info *map_info)
{
	t_map_path	mark;

	if (fill_list == NULL || *fill_list == NULL)
		return (0);
	mark = *((t_map_path *)((*fill_list)->content));
	(map_info->map_data)[mark.y][mark.x].path_check = TRUE;
	ft_lstremove_top(fill_list);
	add_fill_list(fill_list, map_info, &mark);
	return (1);
}

void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y)
{
	t_map_path	*to_fill;
	t_list		*fill_list;
	t_list		*first_list;

	if (map_info == NULL)
		return ;
	fill_list = 0;
	to_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (to_fill == NULL)
		add_fill_list_error(&fill_list, map_info);
	to_fill->x = path_x;
	to_fill->y = path_y;
	first_list = ft_lstnew(&to_fill[0]);
	if (first_list == NULL)
		add_fill_list_error(&fill_list, map_info);
	ft_lstadd_front(&fill_list, first_list);
	while (fill_list != NULL)
	{
		mark_check_path(&fill_list, map_info);
	}
}
