/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:38:17 by srussame          #+#    #+#             */
/*   Updated: 2025/03/15 15:38:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_extention(char *filepath);

/* Objective : read the map as format from the path given from argument
				RETURN as ** array of STRINGS **

				*** USE MALLOC OBVIOUSLY **
*/

char	**read_map(char *filepath)
{
	char	**map_data;
	int		fd;

	if (filepath == 0 || map_check_extention(filepath) == 0)
		exit(EXIT_FAILURE);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("\nCAN\'T OPEN FILE");
		return (0);
	}
	map_data = (char **)ft_calloc(7, sizeof(char *));
	if (map_data == NULL)
		return (0);
	return (map_data);
}

/* Check if the mapfile has the correct extension ('.ber') */

int	map_check_extention(char *filepath)
{
	size_t	name_length;

	if (filepath == NULL)
		return (0);
	name_length = ft_strlen(filepath);
	if (name_length < 5)
	{
		ft_printf("\nWRONG MAP filepath!\n");
		return (0);
	}
	if (ft_strncmp(&filepath[name_length - 4], ".ber", 4) != 0)
	{
		ft_printf("\nWRONG MAP filepath!\n");
		return (0);
	}
	return (1);
}
