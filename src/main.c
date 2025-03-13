/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:15 by srussame          #+#    #+#             */
/*   Updated: 2025/03/12 15:32:16 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct	s_window
{
	void	*mlx_connect;
	void	*window;
}				t_window;

int	key_handling1(int keysym, t_window *window)
{
	if (keysym != XK_Escape)
		return (0);
	write(1, "Exit\n", 5);
	mlx_destroy_window(window->mlx_connect, window->window);
	mlx_destroy_display(window->mlx_connect);
	free(window->mlx_connect);
	exit(EXIT_SUCCESS);
	return (1);
}

int	mouse_handling1(int button, t_window *window)
{
	ft_printf("mouse button press: %d\n", button);
	(void)window;
	return (1);
}

int	destroy_handling(t_window *window)
{
	mlx_destroy_window(window->mlx_connect, window->window);
	mlx_destroy_display(window->mlx_connect);
	free(window->mlx_connect);
	exit(EXIT_SUCCESS);
	return (1);
}

int	main(void)
{
	void		*mlx_connection;
	t_window	win1;

	mlx_connection = mlx_init();

	win1.mlx_connect = mlx_connection;
	win1.window = mlx_new_window(win1.mlx_connect, 400, 400, "window1");
	if (win1.window == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
	}
	mlx_key_hook(win1.window, &key_handling1, &win1);
	mlx_mouse_hook(win1.window, &mouse_handling1, &win1);
	mlx_hook(win1.window, DestroyNotify, 0, &destroy_handling, &win1);
	mlx_loop(mlx_connection);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}
