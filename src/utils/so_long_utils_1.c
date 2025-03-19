/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:48:42 by srussame          #+#    #+#             */
/*   Updated: 2025/03/17 23:48:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_collect(void *collect)
{
	t_map_object *data;

	data = (t_map_object *)collect;
	if (data)
		free(data);
}

void	free_map_char(char **map_char)
{
	int i;

	if (map_char == NULL)
		return ;
	i = 0;
	while (map_char[i] != NULL)
		i++;
	while (i >= 0)
		free(map_char[i--]);
	if (map_char)
		free(map_char);
	return ;
}
