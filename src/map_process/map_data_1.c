/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:33:31 by srussame          #+#    #+#             */
/*   Updated: 2025/03/18 11:33:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data	*get_map_data(char *filepath);

static void	map_data_player_pos(t_map_data **map_data);
static void	map_data_put_data(t_map_data **map_data);

/* THis function take an argument THE MAP PATHNAME  and 
	take the [char **] from get_map_char 
		which contain that map data in an array of strings
		
	this function will try to put in in formation from get_map_char
	and put in into [t_map_data] data type which contain 
	many useful attributes to use

*/

t_map_data	*get_map_data(char *filepath)
{
	t_map_data *new_map_data;
	char	**map_char;

	map_char = get_map_char(filepath);
	if (map_char == NULL)
		return (0);
	if (map_char_check(map_char) == 0)
		return (0);
	new_map_data = (t_map_data *)ft_calloc(1, sizeof(t_map_data));
	if (new_map_data == NULL)
	{
		perror("\nError\nget_map_data()");
		free(map_char);
		return (0);
	}
	new_map_data->map_char = map_char;
	map_data_put_data(&new_map_data);
	map_wall_check(&new_map_data);
	return (new_map_data);
}
static void	map_data_put_data(t_map_data **map_data)
{
	(*map_data)->map_width = ft_strlen(((*map_data)->map_char)[0]);
	while (((*map_data)->map_char)[(*map_data)->map_height] != NULL)
		(*map_data)->map_height++;
	map_data_player_pos(map_data);
}

static void	map_data_player_pos(t_map_data **map_data)
{
	if (map_data == NULL || (*map_data) == NULL)
		return ;
	while ((*map_data)->p_pos_y < (*map_data)->map_height)
	{
		(*map_data)->p_pos_x = 0;
		while ((*map_data)->p_pos_x < (*map_data)->map_width)
		{
			if (((*map_data)->map_char)[(*map_data)->p_pos_y][(*map_data)->p_pos_x] == 'P')
				return ;
			(*map_data)->p_pos_x++;
		}
		(*map_data)->p_pos_y++;
	}
	ft_printf("\nError\nno player position in the map\n\n");
	free_map_char((*map_data)->map_char);
	free((*map_data));
	(*map_data) = NULL;
	return ;
}
