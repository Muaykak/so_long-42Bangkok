/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:40:51 by srussame          #+#    #+#             */
/*   Updated: 2025/03/26 16:40:53 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_addback(t_img_data **img_lst, t_img_data *new_img)
{
	t_img_data	*img_last;

	if (img_lst == NULL)
		return ;
	if (*img_lst == NULL && new_img != NULL)
	{
		*img_lst = new_img;
		(*img_lst)->first = new_img;
	}
	else if (*img_lst != NULL && new_img != NULL)
	{
		img_last = *img_lst;
		new_img->first = (*img_lst)->first;
		while (img_last->next != NULL)
			img_last = img_last->next;
		img_last->next = new_img;
	}
}

int	check_canvas_boundary(t_img_data *img_canvas, int x, int y)
{
	if (img_canvas == NULL)
		return (0);
	if (x < 0 || x > img_canvas->img_width 
		|| y < 0 || y > img_canvas->img_height)
		return (0);
	return (1);
}

void	paint_i_to_i_get_xy(int *xy_offset, int offset_x, int offset_y)
{
	if (offset_x  <= 0)
	{
		xy_offset[0] = 0;
		xy_offset[2] = abs(offset_x);
	}
	else if (offset_x > 0)
	{
		xy_offset[0] = offset_x;
		xy_offset[2] = -1 * offset_x;
	}
	if (offset_y  <= 0)
	{
		xy_offset[1] = 0;
		xy_offset[3] = abs(offset_y);
	}
	else if (xy_offset[3] > 0)
	{
		xy_offset[1] = offset_y;
		xy_offset[3] = -1 * offset_y;
	}
}

void	paint_img_to_img(t_img_data *img_c, t_img_data *img_p,
			int offset_x, int offset_y)
{
	int		xy[4];
	char	*c_pos;
	char	*p_pos;
	int		x;
	int		y;

	paint_i_to_i_get_xy(xy, offset_x, offset_y);
	y = xy[1];
	while (y < img_c->img_height && y + xy[3] < img_p->img_height)
	{
		x = xy[0];
		while (x < img_c->img_width && x + xy[2] < img_p->img_width)
		{
				c_pos = img_c->addr + (((y) * img_c
					->size_line) + ((x) * (img_c->bpp / 8)));
				p_pos = img_p->addr + (((y + xy[3]) * img_p
					->size_line) + ((x + xy[2]) * (img_p->bpp / 8)));
				if ((*((unsigned int *)p_pos) & 0x00FFFFFF) != 0x000000)
					*((unsigned int *)c_pos) = *((unsigned int *)p_pos);
			x++;
		}
		y++;
	}
}
