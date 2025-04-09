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

static void	main_sub1(t_so_long **so_long, void *mlx_connection)
{
	(*so_long)->window = create_so_long_window((*so_long),
			(*so_long)->mlx_ptr);
	map_data_link_img(so_long);
	paint_map_to_window(*so_long);
	so_long_exit_hooks(*so_long);
	mlx_loop(mlx_connection);
}

int	main(int argc, char **argv)
{
	t_map_info	*map_info;
	t_so_long	*so_long;
	void		*mlx_connection;

	if (argc != 2)
	{
		ft_strerr("Error\n\nMust have 1 argument\nThe argument"
			" is filepath to a map file\n\n");
		exit(EXIT_FAILURE);
	}
	map_info = new_map_info(argv[1]);
	if (map_info == NULL)
		exit(EXIT_FAILURE);
	mlx_connection = mlx_init();
	so_long = create_so_long(mlx_connection, map_info);
	so_long->img_list = get_texture_list(so_long);
	if (so_long->img_list == NULL)
	{
		free_so_long(&so_long);
		exit(EXIT_FAILURE);
	}
	main_sub1(&so_long, mlx_connection);
	return (0);
}
