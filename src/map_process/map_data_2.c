/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:31:31 by srussame          #+#    #+#             */
/*   Updated: 2025/03/21 17:31:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	*new_map_info(char *file_name);

t_map_info	*new_map_info(char *file_name)
{
	t_map_info	*map_info;

	map_info = (t_map_info *)ft_calloc(1, sizeof(t_map_info));
	if (map_info == NULL)
	{
		perror("Error\nnew_map_info(): ");
		return (NULL);
	}
	if (get_map_data(file_name, &map_info) == 0)
	{
		free_map_info(&map_info);
		return (NULL);
	}
	map_check_path(&map_info);
	map_wall_check(&map_info);
	return (map_info);
}
