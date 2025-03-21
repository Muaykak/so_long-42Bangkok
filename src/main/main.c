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
	{
		mlx_destroy_image(window->mlx_ptr, window->img->img_ptr);
		free(window->img);
	}
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
	t_map_data	*map_data;
	int		i;
	t_window	win1;
	t_img_data	*img1;
	t_list		*temp;
	void		*mlx_connection;
	int			res_x;
	int			res_y;

	if (argc != 2)
	{
		ft_printf("Error\n\nMust have 1 argument\nThe argument"
			" is filepath to a map file\n\n");
		exit(EXIT_FAILURE);
	}
	map_data = get_map_data(argv[1]);
	if (map_data == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while ((map_data->map_char) != NULL && (map_data->map_char)[i] != NULL)
	{
		printf("map row[%i]: %s\n", i + 1, (map_data->map_char)[i]);
		i++;
	}
	printf("\n\n");
	ft_printf("map size: %dx%d\n", map_data->map_width, map_data->map_height);
	ft_printf("player_pos: %d, %d\n", map_data->player.x, map_data->player.y);
	ft_printf("exit_pos: %d, %d\n", map_data->exit.x, map_data->exit.y);
	temp = map_data->collect_pos;
	while (temp != NULL)
	{
		ft_printf("collect_pos: %d, %d\n", ((t_map_object *)(temp->content))->x, ((t_map_object *)(temp->content))->y);
		temp = temp->next;
	}
	if (map_check_path(&map_data) == 0)
	{
		ft_printf("Error\n: No valid path to complete the game\n");
		exit(EXIT_FAILURE);
	}
	free_map_data(&map_data);
	mlx_connection = mlx_init();
	mlx_get_screen_size(mlx_connection, &res_x, &res_y);
	ft_printf("the current display resolution width: %d, Height: %d\n", res_x, res_y);
	img1 = create_xpm_img(mlx_connection, IMAGE_PATH);
	win1.win_ptr = mlx_new_window(mlx_connection, img1->img_width, img1->img_height, "test");
	win1.mlx_ptr = mlx_connection;
	win1.width = img1->img_width;
	win1.height = img1->img_height;
	win1.img = img1;
	mlx_put_image_to_window(mlx_connection, win1.win_ptr, img1->img_ptr, 0, 0);
	mlx_hook(win1.win_ptr, DestroyNotify, 0, &destroy_handling, &win1);
	mlx_loop(mlx_connection);
	if (argc != 2)
	{
		ft_printf("Error\n"
			"\nThis program takes one argument\nThe argument is the "
			"path to a map file\nto use. The map filename must be in "
			"format\n\n\"filename.ber\"\n\n");	
		exit(EXIT_FAILURE);
	}
	return (0);
}
