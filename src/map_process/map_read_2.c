/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:58:29 by srussame          #+#    #+#             */
/*   Updated: 2025/04/09 10:58:41 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_list_map_sub1(char *new_read, t_list **list)
{
	char	*trimmed;
	t_list	*new_list;

	trimmed = ft_strtrim(new_read, "\n");
	free(new_read);
	if (trimmed == NULL)
	{
		get_next_line(-1);
		perror("Error\n\nread_list_map()");
		return (ft_lstclear(list, &free_path_data), 0);
	}
	new_list = ft_lstnew(&trimmed[0]);
	if (new_list == NULL)
	{
		free(trimmed);
		get_next_line(-1);
		perror("Error\n\nread_list_map()");
		return (ft_lstclear(list, &free_path_data), 0);
	}
	ft_lstadd_back(list, new_list);
	return (1);
}

static int	read_list_map_sub2(char **new_read, int fd, t_list **list)
{
	while (*new_read != NULL && ft_strncmp(*new_read, "\n", 1) == 0)
	{
		free(*new_read);
		*new_read = get_next_line(fd);
	}
	while (*new_read != NULL && ft_strncmp(*new_read, "\n", 1) != 0)
	{
		if (read_list_map_sub1(*new_read, list) == 0)
			return (0);
		*new_read = get_next_line(fd);
	}
	return (1);
}

/* get a list of strings readed from the map file*/
t_list	*read_list_map(int fd)
{
	t_list	*list;
	char	*new_read;

	list = 0;
	new_read = get_next_line(fd);
	if (read_list_map_sub2(&new_read, fd, &list) == 0)
		return (NULL);
	if (new_read == NULL)
		return (list);
	while (new_read != NULL && ft_strncmp(new_read, "\n", 1) == 0)
	{
		free(new_read);
		new_read = get_next_line(fd);
	}
	if (new_read != NULL)
	{
		ft_strerr("Error\n: The map file should contain only one map and"
			" should not contain any letters beside the map\n\n");
		free(new_read);
		get_next_line(-1);
		ft_lstclear(&list, &free_path_data);
		return (NULL);
	}
	get_next_line(-1);
	return (list);
}
