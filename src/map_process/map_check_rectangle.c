/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:24:29 by srussame          #+#    #+#             */
/*   Updated: 2025/03/17 23:24:31 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_rectangle(char **map)
{
	size_t	line_size;
	int		i;
	
	i = 1;
	line_size = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != line_size)
		{
			ft_printf("The map must has rectangle shape\n");
			free_map_char(map);
			return (0);
		}
		i++;
	}
	return (1);
}
