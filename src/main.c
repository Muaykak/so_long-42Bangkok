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

#include "so_long.h"

int	key_handling1(int keysym, t_window *window)
{
	if (keysym != XK_Escape)
		return (0);
	write(1, "Exit\n", 5);
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}

int	paint_whole_image(t_img_data *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->img_width)
	{
		y = 0;
		while (y < img->img_height)
		{
			put_pixel_img(img, x, y, color);
			y++;
		}
		x++;
	}
	ft_printf("paint whole: %x\n", color);
	img->color = color;
	return (1);
}

int	mouse_handling1(int button, int x, int y, t_window *window)
{
	ft_printf("mouse button press: %d at: %d, %d\n", button, x, y);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img->img_ptr, 0, 0);
	if ((unsigned int)window->img->color == WHITE)
		paint_whole_image(window->img, RED);
	else if ((unsigned int)window->img->color == RED)
		paint_whole_image(window->img, GREEN);
	else if ((unsigned int)window->img->color == GREEN)
		paint_whole_image(window->img, BLUE);
	else if ((unsigned int)window->img->color == BLUE)
		paint_whole_image(window->img, WHITE);
	return (1);
}

int	destroy_handling(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}

int	motion_handling1(int x, int y, void *p)
{
	(void)p;
	ft_printf("mouse position: x= %d y= %d\n", x, y);
	return (1);
}

int	image_loop(void *data)
{
	static int	delay;
	t_window	*window;

	window = (t_window *)data;
	if (delay >= 100)
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->img->img_ptr, 0, 0);
		if ((unsigned int)window->img->color == WHITE)
			paint_whole_image(window->img, RED);
		else if ((unsigned int)window->img->color == RED)
			paint_whole_image(window->img, GREEN);
		else if ((unsigned int)window->img->color == GREEN)
			paint_whole_image(window->img, BLUE);
		else if ((unsigned int)window->img->color == BLUE)
			paint_whole_image(window->img, WHITE);
		delay = 0;
	}
	delay++;
	return (1);
}

int	main(void)
{
	void		*mlx_connection;
	t_window	win1;
	t_img_data	img1;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
	{
		perror("mlx_init() connection cannot establish");
		exit(EXIT_FAILURE);
	}

	win1.mlx_ptr = mlx_connection;
	win1.win_ptr = mlx_new_window(win1.mlx_ptr, WIDTH, HEIGHT, "window1");
	win1.height = HEIGHT;
	win1.width = WIDTH;
	if (win1.win_ptr == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		exit(EXIT_FAILURE);
	}
	if (create_image(mlx_connection, &img1, WIDTH, HEIGHT) == 0)
	{
		mlx_destroy_window(mlx_connection, win1.win_ptr);
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		exit(EXIT_FAILURE);
	}
	win1.img = &img1;
	paint_whole_image(&img1, WHITE);
	paint_whole_image(&img1, RED);
	mlx_key_hook(win1.win_ptr, &key_handling1, &win1);
	mlx_mouse_hook(win1.win_ptr, &mouse_handling1, &win1);
	mlx_hook(win1.win_ptr, DestroyNotify, 0, &destroy_handling, &win1);
	mlx_hook(win1.win_ptr, MotionNotify, PointerMotionMask, &motion_handling1, &win1);
	mlx_loop_hook(win1.mlx_ptr, &image_loop, &win1);
	mlx_loop(mlx_connection);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}
