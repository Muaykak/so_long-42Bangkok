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

char		**get_map_char(char *filepath);

static int	map_check_extention(char *filepath);

char		**read_list_to_map_data(t_list **read_list);

/* Objective : read the map as format from the path given from argument
				RETURN as ** array of STRINGS **

				*** USE MALLOC OBVIOUSLY **
*/

char	**get_map_char(char *filepath)
{
	char	**map_data;
	t_list	*map_read;
	int		fd;

	if (filepath == NULL || map_check_extention(filepath) == 0)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n\nCAN\'T OPEN FILE");
		return (NULL);
	}
	map_read = read_list_map(fd);
	close(fd);
	if (map_read == NULL)
		return (NULL);
	map_data = read_list_to_map_data(&map_read);
	if (map_data == NULL)
		perror("\nError\nget_map_char()");
	return (map_data);
}

char	**read_list_to_map_data(t_list **read_list)
{
	size_t	length;
	t_list	*temp;
	char	**map_data;

	if (read_list == NULL || (*read_list) == NULL)
		return (NULL);
	length = 0;
	temp = *read_list;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	map_data = (char **)ft_calloc(length + 1, sizeof(char *));
	if (map_data == NULL)
		return (NULL);
	temp = *read_list;
	length = 0;
	while (temp != NULL)
	{
		map_data[length++] = (char *)(temp->content);
		temp = temp->next;
	}
	return (ft_lstclear(read_list, &free_collect), map_data);
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
		ft_printf("Error\n\nWRONG MAP filepath!\n");
		return (0);
	}
	if (ft_strncmp(&filepath[name_length - 4], ".ber", 4) != 0)
	{
		ft_printf("Error\n\nWRONG MAP filepath!\n");
		return (0);
	}
	return (1);
}
