/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:55:50 by srussame          #+#    #+#             */
/*   Updated: 2025/03/23 21:55:52 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handling(int keysym, t_so_long *so_long)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == XK_Escape)
	{
		write(1, "Exit\n", 5);
		free_so_long(&so_long);
		exit(EXIT_SUCCESS);
	}
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
	{
		if (so_long->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			if (player_move(&so_long, 0, -1) == 0)
				return (1);	
			map_re_paint(&so_long);
			mlx_put_image_to_window(so_long->mlx_ptr,
				so_long->window->win_ptr, so_long->map_img->img_ptr, 0, 0);
			so_long->num_moves++;
			ft_printf("Move: UP\n"
						"number of moves: %u\n", so_long->num_moves);
		}
	}
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
	{
		if (so_long->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			if (player_move(&so_long, 0, 1) == 0)
				return (1);	
			map_re_paint(&so_long);
			mlx_put_image_to_window(so_long->mlx_ptr,
				so_long->window->win_ptr, so_long->map_img->img_ptr, 0, 0);
			so_long->num_moves++;
			ft_printf("Move: DOWN\n"
						"number of moves: %u\n", so_long->num_moves);
		}
	}
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
	{
		if (so_long->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			if (player_move(&so_long, -1, 0) == 0)
				return (1);	
			map_re_paint(&so_long);
			mlx_put_image_to_window(so_long->mlx_ptr,
				so_long->window->win_ptr, so_long->map_img->img_ptr, 0, 0);
			so_long->num_moves++;
			ft_printf("Move: LEFT\n"
						"number of moves: %u\n", so_long->num_moves);
		}
	}
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
	{
		if (so_long->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			if (player_move(&so_long, 1, 0) == 0)
				return (1);	
			map_re_paint(&so_long);
			mlx_put_image_to_window(so_long->mlx_ptr,
				so_long->window->win_ptr, so_long->map_img->img_ptr, 0, 0);
			so_long->num_moves++;
			ft_printf("Move: RIGHT\n"
						"number of moves: %u\n", so_long->num_moves);
		}
	}
	return (1);
}

int	destroy_handling(t_so_long *so_long)
{
	write(1, "Exit\n", 5);
	ft_printf("reach here\n");
	free_so_long(&so_long);
	exit(EXIT_SUCCESS);
	return (1);
}

void	so_long_exit_hooks(t_so_long *so_long)
{
	mlx_hook(so_long->window->win_ptr, DestroyNotify, 0,
		&destroy_handling, so_long);
	mlx_hook(so_long->window->win_ptr, KeyPress, KeyPressMask,
		&key_handling, so_long);
}
