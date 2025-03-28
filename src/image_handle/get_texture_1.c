/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:58 by srussame          #+#    #+#             */
/*   Updated: 2025/03/26 14:32:59 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char		*cat_texture_filename(char *texture_path, int num);
t_img_data	*get_texture(t_so_long *so_long, char *texture_path, int x, int y);
void		img_type_specify(char *texture_path, t_img_data *img);

/* return an t_img_data of the texture of one object type */
t_img_data	*get_texture(t_so_long *so_long, char *texture_path, int x, int y)
{
	int			num;
	char		*cat_filename;
	t_img_data	*temp;
	t_img_data	*new_img;

	if (texture_path == NULL)
		return (NULL);
	num = 1;
	cat_filename = cat_texture_filename(texture_path, num);
	if (cat_filename == NULL)
		return (NULL);
	temp = create_xpm_image_scale(so_long->mlx_ptr, cat_filename, x, y);
	new_img = NULL;
	while (temp != NULL)
	{
		img_type_specify(texture_path, temp);
		img_addback(&new_img, temp);
		free(cat_filename);
		cat_filename = cat_texture_filename(texture_path, ++num);
		if (cat_filename == NULL)
		{
			free_img_data(new_img);
			return (NULL);
		}
		temp = create_xpm_image_scale(so_long->mlx_ptr, cat_filename, x, y);
	}
	free(cat_filename);
	if (temp == NULL && new_img == NULL)
	{
		perror("Error\n\nget_texture(): ");
		return (NULL);
	}
	return (new_img);
}

void	img_type_specify(char *texture_path, t_img_data *img)
{
	if (ft_strncmp(SOLONG_BACKGROUND_XPM, texture_path,
		ft_strlen(SOLONG_BACKGROUND_XPM)) == 0)
		img->obj_type = BACKGROUND;
	else if (ft_strncmp(SOLONG_FLOOR_XPM, texture_path,
		ft_strlen(SOLONG_FLOOR_XPM)) == 0)
		img->obj_type = FLOOR;
	else if (ft_strncmp(SOLONG_WALL_XPM, texture_path,
		ft_strlen(SOLONG_WALL_XPM)) == 0)
		img->obj_type = WALL;
	else if (ft_strncmp(SOLONG_PLAYER_XPM, texture_path,
		ft_strlen(SOLONG_PLAYER_XPM)) == 0)
		img->obj_type = PLAYER;
	else if (ft_strncmp(SOLONG_EXIT_XPM, texture_path,
		ft_strlen(SOLONG_EXIT_XPM)) == 0)
		img->obj_type = EXIT;
	else if (ft_strncmp(SOLONG_COLLECT_XPM, texture_path,
		ft_strlen(SOLONG_COLLECT_XPM)) == 0)
		img->obj_type = COLLECT;
}

char	*cat_texture_filename(char *texture_path, int num)
{
	char	*old_cat;
	char	*new_cat;
	char	*numchar;

	numchar = ft_itoa(abs(num));
	if (numchar == NULL)
	{
		perror("Error\n\ncat_texture_filename(): ");
		return (NULL);
	}
	old_cat = ft_strjoin(texture_path, numchar);
	if (old_cat == NULL)
	{
		free(numchar);
		perror("Error\n\ncat_texture_filename(): ");
		return (NULL);
	}
	new_cat = ft_strjoin(old_cat, SOLONG_IMAGE_EXTENSION);
	free(old_cat);
	free(numchar);
	if (new_cat == NULL)
		perror("Error\n\ncat_texture_filename(): ");
	return (new_cat);
}
