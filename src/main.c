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

#define HEIGHT 400
#define WIDTH 400

typedef struct	s_window
{
	void	*mlx_connect;
	void	*window;
}				t_window;

void	paint_white(t_window *window)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(window->mlx_connect, window->window, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	ft_printf("paint success");
}

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

int	motion_handling1(int x, int y, void *p)
{
	(void)p;
	ft_printf("mouse position: x= %d y= %d\n", x, y);
	return (1);
}

int	main(void)
{
	void		*mlx_connection;
	t_window	win1;
	int			a;
//	int			local_endian;
//
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		ft_printf("endian=1\n");
	else
		ft_printf("endian=0\n");
	
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
	mlx_hook(win1.window, MotionNotify, PointerMotionMask, &motion_handling1, &win1);
	paint_white(&win1);
	mlx_string_put(win1.mlx_connect, win1.window, HEIGHT / 2, WIDTH / 2, 0xFF000000, "hello world");
	mlx_loop(mlx_connection);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}
