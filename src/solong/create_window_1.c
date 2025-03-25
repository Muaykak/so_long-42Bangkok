/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:28:00 by srussame          #+#    #+#             */
/*   Updated: 2025/03/25 23:28:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*create_so_long_window(t_so_long *so_long, void *mlx_ptr)
{
	t_window	*new_win;

	new_win = (t_window *)ft_calloc(1, sizeof(t_window));
	if (new_win == NULL)
	{
		perror("Error\n\ncreate_so_long_window(): ");
		return (NULL);
	}
	if (so_long->max_win_x > so_long->canvas_x)
		new_win->width = so_long->canvas_x;
	else
		new_win->width = so_long->max_win_x;
	if (so_long->max_win_y > so_long->canvas_y)
		new_win->height = so_long->canvas_y;
	else
		new_win->height = so_long->max_win_y;
	new_win->mlx_ptr = mlx_ptr;
	new_win->win_ptr = mlx_new_window(mlx_ptr, new_win->width, new_win->height, "test");
	if (new_win->win_ptr == NULL)
	{
		perror("Error\n\ncreate_so_long_window(): ");
		free(new_win);
		return (NULL);
	}
	return (new_win);
}
