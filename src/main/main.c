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
	t_map_info	*map_info;
//	t_img_data	*scale_img;
//	t_img_data	*temp2;
	t_list		*temp;
	t_so_long	*so_long;
	int			x;
	int			y;
	void		*mlx_connection;

	if (argc != 2)
	{
		ft_printf("Error\n\nMust have 1 argument\nThe argument"
			" is filepath to a map file\n\n");
		exit(EXIT_FAILURE);
	}
	map_info = new_map_info(argv[1]);
	if (map_info == NULL)
		exit(EXIT_FAILURE);
	ft_printf("map:\n");
	y = 0;
	while (map_info->map_data != NULL && (map_info->map_data)[y] != NULL)
	{
		x = 0;
		while (x < map_info->map_width)
		{
			if (map_info->map_data[y][x].type == FLOOR)
				ft_printf("0");
			else if (map_info->map_data[y][x].type == WALL)
				ft_printf("1");
			else if (map_info->map_data[y][x].type == PLAYER)
				ft_printf("P");
			else if (map_info->map_data[y][x].type == COLLECT)
				ft_printf("C");
			else if (map_info->map_data[y][x].type == EXIT)
				ft_printf("E");
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
	ft_printf("map size: %dx%d\n", map_info->map_width, map_info->map_height);
	ft_printf("player_pos: %d, %d\n", map_info->player->x, map_info->player->y);
	ft_printf("exit_pos: %d, %d\n", map_info->exit->x, map_info->exit->y);
	temp = map_info->collects;
	while (temp != NULL)
	{
		ft_printf("collect_pos: %d, %d\n", ((t_map_data *)(temp->content))->x, ((t_map_data *)(temp->content))->y);
		temp = temp->next;
	}
	mlx_connection = mlx_init();
	so_long = create_so_long(mlx_connection, map_info);
	so_long->img_list = get_texture_list(so_long);
	if (so_long->img_list == NULL)
	{
		free_so_long(&so_long);
		return (0);
	}
	so_long->window = create_so_long_window(so_long, so_long->mlx_ptr);
	map_data_link_img(&so_long);
	map_first_paint(&so_long);
	paint_img_to_img(so_long->window->img, so_long->map_img, 0, 0);

	mlx_put_image_to_window(so_long->window->mlx_ptr, so_long->window->win_ptr, so_long->window->img->img_ptr, 0, 0);
	so_long_exit_hooks(so_long);
	mlx_loop(mlx_connection);
	return (0);
}
