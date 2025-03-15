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
	if (window->img != NULL)
		mlx_destroy_image(window->mlx_ptr, window->img->img_ptr);
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
	if (delay >= 10000)
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

int	main(int argc, char **argv)
{
	char	**map_data;

	if (argc != 2)
	{
		ft_printf("Error\n"
			"\nThis program takes one argument\nThe argument is the "
			"path to a map file\nto use. The map filename must be in "
			"format\n\n\"filename.ber\"\n\n");	
		exit(EXIT_FAILURE);
	}
	map_data = read_map(argv[1]);
	free(map_data);
	return (0);
}
