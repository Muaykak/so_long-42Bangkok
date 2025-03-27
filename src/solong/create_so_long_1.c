/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_so_long_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:28:44 by srussame          #+#    #+#             */
/*   Updated: 2025/03/25 23:28:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	max_win_size_calculation(t_so_long *so_long);

t_so_long	*create_so_long(void *mlx_ptr, t_map_info *map_info)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)ft_calloc(1, sizeof(t_so_long));
	if (so_long == NULL)
	{
		perror("Error\n\ncreate_so_long(): ");
		return (NULL);
	}
	so_long->mlx_ptr = mlx_ptr;
	mlx_get_screen_size(mlx_ptr, &(so_long->display_width),
		&(so_long->display_height));
	so_long->map_info = map_info;
	max_win_size_calculation(so_long);
	return (so_long);
}

void	max_win_size_calculation_sub1(t_so_long *so_long)
{
	int	temp;

	if (so_long->grid_size * so_long->map_info->map_width > so_long->max_win_x
		|| so_long->grid_size * so_long->map_info->map_height
		> so_long->max_win_y)
	{
		temp = (int)round(so_long->max_win_x
			/ (double)so_long->map_info->map_width);
		so_long->grid_size = (int)round(so_long->max_win_y
			/ (double)so_long->map_info->map_height);
		if (temp < so_long->grid_size)
			so_long->grid_size = temp;
		if (so_long->grid_size < SOLONG_MIN_GRID_SIZE)
			so_long->grid_size = SOLONG_MIN_GRID_SIZE;
	}
	so_long->canvas_x = so_long->grid_size * so_long->map_info->map_width;
	so_long->canvas_y = so_long->grid_size * so_long->map_info->map_height;
}

void	max_win_size_calculation(t_so_long *so_long)
{
	int temp;

	so_long->max_win_x = (int)round(so_long->display_width
		* SOLONG_MAX_WIN_RATIO);
	so_long->max_win_y = (int)round(so_long->display_height
		* SOLONG_MAX_WIN_RATIO);
	so_long->grid_size = (int)round(so_long->display_height
		* SOLONG_GRID_SIZE_RATIO);
	temp = (int)round(so_long->display_width
		* SOLONG_GRID_SIZE_RATIO);
	if (temp < so_long->grid_size)
		so_long->grid_size = temp;
	max_win_size_calculation_sub1(so_long);
}
