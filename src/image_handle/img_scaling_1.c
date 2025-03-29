/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_scaling_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:53 by srussame          #+#    #+#             */
/*   Updated: 2025/03/24 16:35:55 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		put_scale_data(t_img_scale_data *scale_data, t_img_data *orig_img,
				t_img_data *new_img);
t_img_data	*img_scaling(t_img_data *orig_img, int x, int y, int op);
//void		img_scale_larger_put_color(t_img_data *new_img,
//				t_img_scale_data *scale_data);
//void		img_scale_small_put_color(t_img_data *new_img,
//				t_img_scale_data *scale_data);
void		img_scale_uniform_put_color(t_img_data *new_img,
				t_img_scale_data *scale_data);
void		img_scale_stretch_put_color(t_img_data *new_img,
				t_img_scale_data *scale_data);

// create a 'proportional'/'uniform' scaling img 
t_img_data	*img_scaling(t_img_data *orig_img, int x, int y, int op)
{
	t_img_data			*new_img;
	t_img_scale_data	scale_data;

	if (orig_img == NULL)
		return (NULL);
	if (x <= 0 || y <= 0)
	{
		ft_printf("Error\n\nimg_scaling(): invalid x, y value\n");
		return (NULL);
	}
	if (x == orig_img->img_width && y == orig_img->img_height)
		return (orig_img);
	new_img = create_image(orig_img->mlx_ptr, x, y);
	if (new_img == NULL)
		return (0);
	new_img->orig_img = orig_img;
	put_scale_data(&scale_data, orig_img, new_img);
	if (op == 0)
		img_scale_uniform_put_color(new_img, &scale_data);
	else
		img_scale_stretch_put_color(new_img, &scale_data);
	return (new_img);
}

void	img_scale_stretch_put_color(t_img_data *new_img, t_img_scale_data *scale_data)
{
	int		x;
	int		y;
	char	*new_pos;
	char	*old_pos;

	y = 0;
	scale_data->factor_x = 1.0 / scale_data->factor_x;
	scale_data->factor_y = 1.0 / scale_data->factor_y;
	while (y < new_img->img_height)
	{
		x = 0;
		while (x < new_img->img_width)
		{
			new_pos = new_img->addr
				+ ((y * new_img->size_line)
				+ (x * (new_img->bpp / 8)));
			old_pos = new_img->orig_img->addr + (((int)round((y)
				* scale_data->factor_y) * new_img->orig_img->size_line)
				+ ((int)round((x) * scale_data->factor_x)
				* (new_img->orig_img->bpp / 8)));
			*((unsigned int *)new_pos) = *((unsigned int *)old_pos);
			x++;
		}
		y++;
	}
}

void	img_scale_uniform_put_color(t_img_data *new_img, t_img_scale_data *scale_data)
{
	int		x;
	int		y;
	char	*new_pos;
	char	*old_pos;

	y = scale_data->offset_y;
	scale_data->factor_min = 1.0 / scale_data->factor_min;
	while (y + scale_data->offset_y < new_img->img_height)
	{
		x = scale_data->offset_x;
		while (x + scale_data->offset_x < new_img->img_width)
		{
			new_pos = new_img->addr
				+ ((y * new_img->size_line)
				+ (x * (new_img->bpp / 8)));
			old_pos = new_img->orig_img->addr + (((int)round((y - scale_data->offset_y)
				* scale_data->factor_min) * new_img->orig_img->size_line)
				+ ((int)round((x - scale_data->offset_x) * scale_data->factor_min)
				* (new_img->orig_img->bpp / 8)));
			*((unsigned int *)new_pos) = *((unsigned int *)old_pos);
			x++;
		}
		y++;
	}
}

//void	img_scale_small_put_color(t_img_data *new_img, t_img_scale_data *scale_data)
//{
//	int		x;
//	int		y;
//	char	*new_pos;
//	char	*old_pos;
//
//	y = 0;
//	while (y < new_img->orig_img->img_height)
//	{
//		x = 0;
//		while (x < new_img->orig_img->img_width)
//		{
//			old_pos = new_img->orig_img->addr
//				+ ((y * new_img->orig_img->size_line)
//				+ (x * (new_img->orig_img->bpp / 8)));
//			new_pos = new_img->addr + (((int)round((y + scale_data->offset_y)
//				* scale_data->factor_min) * new_img->size_line)
//				+ ((int)round((x + scale_data->offset_x) * scale_data->factor_min)
//				* (new_img->bpp / 8)));
//			*((unsigned int *)new_pos) = *((unsigned int *)old_pos);
//			x++;
//		}
//		y++;
//	}
//}

void	put_scale_data(t_img_scale_data *scale_data, t_img_data *orig_img,
			t_img_data *new_img)
{
	scale_data->factor_x = (double)new_img->img_width / orig_img->img_width;
	scale_data->factor_y = (double)new_img->img_height / orig_img->img_height;
	if (scale_data->factor_y < scale_data->factor_x)
		scale_data->factor_min = scale_data->factor_y;
	else
		scale_data->factor_min = scale_data->factor_x;
	scale_data->scale_width =
		(int)round(orig_img->img_width * scale_data->factor_min);
	scale_data->scale_height =
		(int)round(orig_img->img_height * scale_data->factor_min);
	scale_data->offset_x = (new_img->img_width - scale_data->scale_width) / 2;
	scale_data->offset_y = (new_img->img_height - scale_data->scale_height) / 2;
}
