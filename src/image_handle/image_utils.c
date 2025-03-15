/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:20:53 by srussame          #+#    #+#             */
/*   Updated: 2025/03/14 18:20:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_color(t_img_data *img, int color);
int	put_pixel_img(t_img_data *img, int x, int y, int color);
t_img_data	*create_image(void *mlx_ptr, int x, int y);
t_img_data	*create_xpm_img(void *mlx_ptr, char *filename);

t_img_data	*create_image(void *mlx_ptr, int x, int y)
{
	int	a;
	t_img_data	*new_img;

	
	new_img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	if (new_img == NULL)
		return (0);
	new_img->img_ptr = mlx_new_image(mlx_ptr, x, y);
	if (new_img->img_ptr == NULL)
	{
		free(new_img);
		return (0);
	}
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		new_img->local_endian = 1;
	else
		new_img->local_endian = 0;
	new_img->mlx_ptr = mlx_ptr;
	new_img->addr = mlx_get_data_addr(new_img->img_ptr, &new_img->bpp,
		&new_img->size_line, &new_img->endian);
	new_img->img_height = y;
	new_img->img_width = x;
	return (new_img);
}

t_img_data	*create_xpm_img(void *mlx_ptr, char *filename)
{
	int			a;
	t_img_data	*img;

	img = (t_img_data *)calloc(1, sizeof(t_img_data));
	if (img == NULL)
		return (0);
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename,
		&img->img_width, &img->img_height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (0);
	}
	if (((unsigned char *)&a)[0] == 0x11)
		img->local_endian = 1;
	else
		img->local_endian = 0;
	img->mlx_ptr = mlx_ptr;
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian);
	return (img);
}

int	put_pixel_img(t_img_data *img, int x, int y, int color)
{
	char	*target;

	if (x > img->img_width || y > img->img_height)
		return (0);
	target = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
	*((unsigned int *)target) = get_img_color(img, color);
	return (1);
}

int	get_img_color(t_img_data *img, int color)
{
	int	correct_color;
	int	invert_bits;

	correct_color = mlx_get_color_value(img->mlx_ptr, color);
	if (img->local_endian == img->endian)
		return (correct_color);
	((unsigned char *)&invert_bits)[0] = ((unsigned char *)&correct_color)[3];
	((unsigned char *)&invert_bits)[1] = ((unsigned char *)&correct_color)[2];
	((unsigned char *)&invert_bits)[2] = ((unsigned char *)&correct_color)[1];
	((unsigned char *)&invert_bits)[3] = ((unsigned char *)&correct_color)[0];
	return (invert_bits);
}
