/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_scaling_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:05:28 by srussame          #+#    #+#             */
/*   Updated: 2025/03/24 20:05:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// create xpm image with respective image size x,y

t_img_data	*create_xpm_image_scale(void *mlx_ptr, char *filename, int x, int y)
{
	t_img_data	*orig_img;
	t_img_data	*scale_img;

	orig_img = create_xpm_img(mlx_ptr, filename);
	if (orig_img == NULL)
		return (NULL);
	scale_img = img_scaling(orig_img, x, y, 0);
	if (scale_img == NULL)
		return (NULL);
	return (scale_img);
}
