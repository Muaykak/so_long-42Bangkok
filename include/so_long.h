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

# define HEIGHT 400
# define WIDTH 400

# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define WHITE 0xFFFFFFFF

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

int	put_pixel_img(t_img_data *img, int x, int y, int color);
int	get_img_color(t_img_data *img, int color);
int	create_image(void *mlx_ptr,t_img_data *img, int x, int y);

#endif