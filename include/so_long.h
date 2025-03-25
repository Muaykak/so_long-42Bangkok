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
# include <limits.h>
# include <math.h>
# include <fcntl.h>

# define HEIGHT 400
# define WIDTH 400

# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define WHITE 0xFFFFFFFF

# ifndef SOLONG_MIN_WINDOW_SIZE
#  define SOLONG_MIN_WINDOW_SIZE 100
# endif

# ifndef SOLONG_MIN_GRID_SIZE
#  define SOLONG_MIN_GRID_SIZE 32
# endif

# define IMAGE_PATH "assets/image/out.xpm"

enum	e_object_type
{
	EMPTY,
	BACKGROUND,
	FLOOR,
	WALL,
	PLAYER,
	EXIT,
	COLLECT
};

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
	struct s_img_data	*orig_img;
	enum e_object_type	obj_type;
}				t_img_data;

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
	enum	e_object_type	type;
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

typedef struct	s_img_scale_data
{
	double	factor_x;
	double	factor_y;
	double	factor_min;
	int	scale_width;
	int	scale_height;
	int	offset_x;
	int	offset_y;
}				t_img_scale_data;

typedef struct	s_so_long
{
	t_map_info		*map_info;
	t_list			*img_list;	
	int				grid_size;
	int				canvas_x;
	unsigned int	num_moves;
}				t_so_long;

typedef struct	s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	t_so_long		*so_long_info;
	t_img_data		*img;
}				t_window;

/* ***************** IMAGE HANDLING ********************* */
int	put_pixel_img(t_img_data *img, int x, int y, int color);
int	get_img_color(t_img_data *img, int color);
int	get_pixel_color(t_img_data *img, int x, int y);

t_img_data	*create_image(void *mlx_ptr, int x, int y); //use malloc
t_img_data	*create_xpm_img(void *mlx_ptr, char *filepath); //use malloc
t_img_data	*create_xpm_image_scale(void *mlx_ptr,
				char *filename, int x, int y);

// Image Scaling
t_img_data	*img_scaling(t_img_data *orig_img, int x, int y);

/* ****************************************************** */

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

int		map_wall_check(t_map_info **map_info);

int		map_check_path(t_map_info **map_info);
void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y);
int		map_check_path_data(t_list **path_data, int path_x, int path_y);

/* *********************************************** */

/* Hooks Handling */
void	so_long_exit_hooks(t_window *so_long_win);

/* Utility Function */
void	free_map_char(char ***map_char);
void	free_collect(void *collect);
void	free_map_data(t_map_data ***map_data);
void	free_map_info(t_map_info **map_info);
void	free_path_data(void *path_data);

#endif