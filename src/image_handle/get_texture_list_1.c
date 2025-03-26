/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_list_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:29:00 by srussame          #+#    #+#             */
/*   Updated: 2025/03/26 14:29:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* return a list of img data of each object type*/
static int	get_texture_list_sub0(t_so_long *so_long, t_list **new_list);
static int	get_texture_list_sub1(t_so_long *so_long, t_list **new_list);
static int	get_texture_list_sub2(t_so_long *so_long, t_list **new_list);

t_list	*get_texture_list(t_so_long *so_long)
{
	t_list	*new_list;

	if (so_long == NULL)
		return (NULL);
	new_list = NULL;
	if (get_texture_list_sub0(so_long, &new_list) == 0)
		return (NULL);
	if (get_texture_list_sub1(so_long, &new_list) == 0)
		return (NULL);
	if (get_texture_list_sub2(so_long, &new_list) == 0)
		return (NULL);
	return (new_list);
}

static int	get_texture_list_sub0(t_so_long *so_long, t_list **new_list)
{
	t_img_data	*temp;

	temp = get_texture(so_long, SOLONG_BACKGROUND_XPM,
		so_long->canvas_x, so_long->canvas_y);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	temp = get_texture(so_long, SOLONG_FLOOR_XPM,
		so_long->grid_size, so_long->grid_size);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	return (1);
}

static int	get_texture_list_sub1(t_so_long *so_long, t_list **new_list)
{
	t_img_data	*temp;

	temp = get_texture(so_long, SOLONG_WALL_XPM,
		so_long->grid_size, so_long->grid_size);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	temp = get_texture(so_long, SOLONG_PLAYER_XPM,
		so_long->grid_size, so_long->grid_size);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	return (1);
}

static int	get_texture_list_sub2(t_so_long *so_long, t_list **new_list)
{
	t_img_data	*temp;

	temp = get_texture(so_long, SOLONG_COLLECT_XPM,
		so_long->grid_size, so_long->grid_size);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	temp = get_texture(so_long, SOLONG_EXIT_XPM,
		so_long->grid_size, so_long->grid_size);
	if (temp == NULL)
	{
		if (*new_list != NULL)
			ft_lstclear(new_list, &free_img_data);
		return (0);
	}
	ft_lstadd_back(new_list, ft_lstnew(&temp[0]));
	return (1);
}
