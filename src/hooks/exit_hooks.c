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

int	key_handling(int keysym, t_window *window)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == XK_Escape)
	{
		write(1, "Exit\n", 5);
		mlx_clear_window(window->mlx_ptr, window->win_ptr);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
	{
		if (window->so_long_info->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			window->so_long_info->num_moves++;
			ft_printf("Move: UP\n"
						"number of moves: %u", window->so_long_info->num_moves);
		}
	}
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
	{
		if (window->so_long_info->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			window->so_long_info->num_moves++;
			ft_printf("Move: DOWN\n"
						"number of moves: %u", window->so_long_info->num_moves);
		}
	}
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
	{
		if (window->so_long_info->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			window->so_long_info->num_moves++;
			ft_printf("Move: LEFT\n"
						"number of moves: %u", window->so_long_info->num_moves);
		}
	}
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Down)
	{
		if (window->so_long_info->num_moves >= UINT_MAX)
		{
			ft_printf("maximum number of moves\n");
		}
		else
		{
			window->so_long_info->num_moves++;
			ft_printf("Move: RIGHT\n"
						"number of moves: %u", window->so_long_info->num_moves);
		}
	}
	return (1);
}

int	destroy_handling(t_window *window)
{
	if (window->img != NULL)
	{
		if (window->img->orig_img != NULL)
		{
			mlx_destroy_image(window->mlx_ptr, window->img->orig_img->img_ptr);
			free(window->img->orig_img);
		}
		mlx_destroy_image(window->mlx_ptr, window->img->img_ptr);
		free(window->img);
	}
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}

void	so_long_exit_hooks(t_window *so_long_win)
{
	mlx_hook(so_long_win->win_ptr, DestroyNotify, 0,
		&destroy_handling, so_long_win);
	mlx_key_hook(so_long_win->mlx_ptr, &key_handling, so_long_win);
//	mlx_hook(so_long_win->mlx_ptr, KeyPress, KeyPressMask,
//		&key_handling, so_long_win);
}
