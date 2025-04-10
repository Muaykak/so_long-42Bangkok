/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:03:04 by srussame          #+#    #+#             */
/*   Updated: 2025/03/26 00:03:06 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img_data(void *p)
{
	t_img_data	*temp;
	t_img_data	*img_data;

	img_data = (t_img_data *)p;
	if (img_data == NULL)
		return ;
	while (img_data != NULL)
	{
		temp = img_data->next;
		if (img_data->orig_img != NULL)
			free_img_data(img_data->orig_img);
		mlx_destroy_image(img_data->mlx_ptr, img_data->img_ptr);
		free(img_data);
		img_data = temp;
	}
	img_data = NULL;
	return ;
}

void	free_so_long(t_so_long **so_long)
{
	if (so_long == NULL || *so_long == NULL)
		return ;
	if ((*so_long)->map_info != NULL)
		free_map_info(&((*so_long)->map_info));
	if ((*so_long)->img_list != NULL)
		ft_lstclear(&((*so_long)->img_list), &free_img_data);
	if ((*so_long)->window != NULL)
	{
		if ((*so_long)->window->img != NULL)
			free_img_data(((*so_long)->window->img));
		mlx_destroy_window((*so_long)->window->mlx_ptr,
			(*so_long)->window->win_ptr);
		free((*so_long)->window);
	}
	mlx_destroy_display((*so_long)->mlx_ptr);
	free((*so_long)->mlx_ptr);
	free(*so_long);
	(*so_long) = NULL;
	return ;
}

t_list	*find_from_object_lst(t_list *object_list, enum e_object_type type)
{
	t_list	*target;

	if (object_list == NULL)
		return (NULL);
	target = object_list;
	while (target != NULL && ((t_map_object *)(target->content))->type != type)
		target = target->next;
	if (target == NULL)
		return (NULL);
	return (target);
}

t_img_data	*find_from_img_list(t_list *img_list, enum e_object_type type)
{
	t_list	*temp;

	if (img_list == NULL)
		return (NULL);
	temp = img_list;
	while (temp != NULL && ((t_img_data *)(temp->content))->obj_type != type)
		temp = temp->next;
	if (temp == NULL)
		return (NULL);
	return (((t_img_data *)(temp->content)));
}
