/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:42:10 by srussame          #+#    #+#             */
/*   Updated: 2025/03/25 16:42:11 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_complete(t_so_long **so_long)
{
	t_map_object	*exit_object;
	t_map_object	*player;

	if (so_long == NULL)
		return ;
	exit_object = (*so_long)->map_info->exit;
	player = (*so_long)->map_info->player;
	if (exit_object == FALSE)
		return ;
	if (exit_object->x == player->x && exit_object->y == player->y)
	{
		free_so_long(so_long);
		ft_printf("COMPLETE\n");
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	control_hooks_sub1(t_so_long **so_long, int x, int y)
{
	if (player_move(so_long, x, y) == 0)
		return ;	
	map_re_paint(so_long);
	push_map_to_window(*so_long);
	(*so_long)->num_moves++;
	ft_printf("number of moves: %u\n", (*so_long)->num_moves);
	check_complete(so_long);
}

void	control_hooks(int keysym, t_so_long **so_long)
{
	if (keysym != XK_w && keysym != XK_W && keysym != XK_Up
		&& keysym != XK_s && keysym != XK_S && keysym != XK_Down
		&& keysym != XK_a && keysym != XK_A && keysym != XK_Left
		&& keysym != XK_d && keysym != XK_D && keysym != XK_Right)
		return ;
	if ((*so_long)->num_moves >= UINT_MAX)
		ft_printf("maximum number of moves\n");
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		control_hooks_sub1(so_long, 0, -1);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		control_hooks_sub1(so_long, 0, 1);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		control_hooks_sub1(so_long, -1, 0);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		control_hooks_sub1(so_long, 1, 0);
}
