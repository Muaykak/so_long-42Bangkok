/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:23:50 by srussame          #+#    #+#             */
/*   Updated: 2025/03/29 16:23:51 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	expose_handling(t_so_long *so_long)
{
	mlx_clear_window(so_long->mlx_ptr, so_long->window->win_ptr);
	paint_map_to_window(so_long);
	return (1);
}
