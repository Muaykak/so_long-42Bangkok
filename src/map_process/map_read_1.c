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

char			**get_map_char(char *filepath);

static char		*read_map(int fd);
static int		map_check_extention(char *filepath);
static char		*map_read_check(char *new_cat, char *str, int fd);
static char		*read_map_sub1(char *new_cat, char *str);

/* Objective : read the map as format from the path given from argument
				RETURN as ** array of STRINGS **

				*** USE MALLOC OBVIOUSLY **
*/

char	**get_map_char(char *filepath)
{
	char	**map_data;
	char	*map_read;
	int		fd;

	if (filepath == NULL || map_check_extention(filepath) == 0)
		exit(EXIT_FAILURE);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("\nCAN\'T OPEN FILE");
		return (NULL);
	}
	map_read = read_map(fd);
	close(fd);
	if (map_read == NULL)
		return (NULL);
	map_data = ft_split(map_read, '\n');
	if (map_data == NULL)
		perror("\nError\nget_map_char()");
	free(map_read);
	return (map_data);
}

/* get the concated string that separated by newline '\n' */
/* use MALLOC */
char	*read_map(int fd)
{
	char	*str;
	char	*temp;
	char	*new_cat;	

	new_cat = 0;
	str = get_next_line(fd);
	while (str != NULL && ft_strncmp(str, "\n", 1) == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str != NULL && ft_strncmp(str, "\n", 1) != 0)
	{
		temp = ft_strjoin(new_cat, str);
		if (temp == NULL)
			return (read_map_sub1(new_cat, str));
		if (new_cat != NULL)
			free(new_cat);
		free(str);
		new_cat = temp;
		str = get_next_line(fd);
	}
	return (map_read_check(new_cat, str, fd));
}

static char	*read_map_sub1(char *new_cat, char *str)
{
	if (new_cat)
		free(new_cat);
	if (str)
		free(str);
	perror("\nError\nread_map()");
	return (NULL);
}

char	*map_read_check(char *new_cat, char *str, int fd)
{
	if (str == NULL)
		return (new_cat);
	while (str != NULL && ft_strncmp(str, "\n", 1) == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (str != NULL)
	{
		ft_printf("Error\n: The map file should contain only one map and"
			" should not contain any letters beside the map\n\n");
		if (new_cat)
			free(new_cat);
		new_cat = NULL;
	}
	return (new_cat);
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
