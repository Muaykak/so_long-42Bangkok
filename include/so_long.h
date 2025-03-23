/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:21:18 by srussame          #+#    #+#             */
/*   Updated: 2025/03/14 13:21:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define HEIGHT 400
# define WIDTH 400

# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define WHITE 0xFFFFFFFF

# define IMAGE_PATH "assets/image/out.xpm"

typedef	struct	s_img_data
{
	void				*img_ptr;
	void				*mlx_ptr;
	char				*addr;
	int					bpp;
	int					size_line;
	int					endian;
	int					local_endian;
	int					img_width;
	int					img_height;
	int					color;
	struct s_img_data	*next;
	struct s_img_data	*first;
}				t_img_data;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_img_data	*img;
}				t_window;

typedef struct s_map_object
{
	int		x;
	int		y;
	int		status;
}				t_map_object;

typedef struct	s_map_data
{
	int		x;
	int		y;
	enum	e_object_type
	{
		EMPTY,
		WALL,
		PLAYER,
		EXIT,
		COLLECT
	}		type;
	enum	e_object_status
	{
		FALSE,
		TRUE
	}		status;
	struct	s_img_coordinate
	{
		int	x;
		int	y;
	}		img_link_coor;	
	t_img_data	*object_img;
}				t_map_data;

typedef	struct	s_map_info
{
	t_map_data		**map_data;
	int				map_height;
	int				map_width;
	t_map_data		*player;
	t_map_data		*exit;	
	t_list			*collects;
	t_map_data		*path_dest;
	t_list			*path_data;
}				t_map_info;

typedef struct	s_map_path
{
	int	x;
	int	y;
}				t_map_path;


int	put_pixel_img(t_img_data *img, int x, int y, int color);
int	get_img_color(t_img_data *img, int color);

t_img_data	*create_image(void *mlx_ptr, int x, int y); //use malloc
t_img_data	*create_xpm_img(void *mlx_ptr, char *filepath); //use malloc

/* ************** . Map processing . ************* */
char		**get_map_char(char *filepath); //use malloc
int			get_map_data(char *filepath, t_map_info **map_info);
t_map_data	**get_empty_map_data(char **map_data);
t_map_info	*new_map_info(char *file_name);

// Map_check
int		map_char_check(char **map_char);
int		map_check_rectangle(char **map);
int		map_check_component(char **map_char);
int		map_check_minimum(char **map_char);

int		map_wall_check(t_map_data **map_data);

int		map_check_path(t_map_info **map_info);
void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y);
int		map_check_path_data(t_list **path_data, int path_x, int path_y);

/* *********************************************** */

/* Utility Function */
void	free_map_char(char ***map_char);
void	free_collect(void *collect);
void	free_map_data(t_map_data ***map_data);
void	free_map_info(t_map_info **map_info);
void	free_path_data(void *path_data);

#endif