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
	if (keysym == XK_Escape)
	{
		write(1, "Exit\n", 5);
		free_so_long(&so_long);
		exit(EXIT_SUCCESS);
	}
	else
		control_hooks(keysym, &so_long);
	return (1);
}

int	destroy_handling(t_so_long *so_long)
{
	write(1, "Exit\n", 5);
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
	mlx_expose_hook(so_long->window->win_ptr, &expose_handling,so_long);
}
