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

void	free_map_data(t_map_data **map_data);
void	free_collect(void *collect);
void	free_map_char(char **map_char);

void	free_collect(void *collect)
{
	if (collect)
		free(collect);
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

void	free_map_data(t_map_data **map_data)
{
	if ((*map_data) == NULL)
		return ;
	if ((*map_data)->map_char != NULL)
		free_map_char((*map_data)->map_char);
	if ((*map_data)->collect_pos != NULL)
		ft_lstclear(&((*map_data)->collect_pos), &free_collect);
	free((*map_data));
}