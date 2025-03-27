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

t_map_data			**get_empty_map_data(char **map_char);
static t_map_data	**get_empty_map_data_sub1(int map_height, int map_width,
						t_map_data **new_map_data);

/*

	THis function take an argument THE MAP PATHNAME  and 
	take the [char **] from get_map_char 
		which contain that map data in an array of strings

	this function will try to put in in formation from get_map_char
	and put in into [t_map_data] data type which contain 
	many useful attributes to use

*/
static t_map_data	**get_empty_map_data_sub1(int map_height, int map_width,
	t_map_data **new_map_data)
{
	int	temp;

	temp = 0;
	while (temp < map_height)
	{
		new_map_data[temp] = (t_map_data *)ft_calloc(map_width, sizeof(t_map_data));
		if (new_map_data[temp] == NULL)
		{
			perror("Error\nget_map_data(): ");
			while (temp - 1 >= 0)
			{
				free(new_map_data[temp - 1]);
				temp--;
			}
			free(new_map_data);
			return (0);
		}
		temp++;
	}
	return (new_map_data);
}

t_map_data	**get_empty_map_data(char **map_char)
{
	int			map_height;
	int			map_width;
	t_map_data	**new_map_data;

	if (map_char == NULL)
		return (0);
	map_height = 0;
	map_width = ft_strlen(map_char[0]);
	while (map_char[map_height] != NULL)
		map_height++;
	new_map_data = (t_map_data **)ft_calloc(map_height + 1, sizeof(t_map_data *));
	if (new_map_data == NULL)
	{
		perror("Error\nget_map_data(): ");
		return (0);
	}
	return (get_empty_map_data_sub1(map_height, map_width, new_map_data));
}
