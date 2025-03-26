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

void	paint_img_to_img(t_img_data *img_canvas, t_img_data *img_paint,
			int offset_x, int offset_y)
{
	int	x;
	int	y;
	char	*canvas_pos;
	char	*paint_pos;

	y = 0;
	while (y < img_paint->img_height)
	{
		x = 0;
		while (x < img_paint->img_width)
		{
			if (check_canvas_boundary(img_canvas,
				x + offset_x, y + offset_y) == 1)
			{
				canvas_pos = img_canvas->addr + (((y + offset_y) * img_canvas
					->size_line) + ((x + offset_x) * (img_canvas->bpp / 8)));
				paint_pos = img_paint->addr + ((y * img_paint->size_line)
					+ (x * (img_paint->bpp / 8)));
				if (*((unsigned int *)paint_pos) != 0xFF000000)
					*((unsigned int *)canvas_pos) = *((unsigned int *)paint_pos);
			}
			x++;
		}
		y++;
	}
}
