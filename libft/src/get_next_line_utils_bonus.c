/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:55:21 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 20:55:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		check_newline(char *buffer);
static int	check_leftover_sub1(char **leftover, t_gnl_data *gnl, \
			t_check_leftover_data *cl);
int			put_leftover(t_goread_data *gr, char **leftover,
				t_gnl_data *gnl);

void	free_leftover(char **leftover)
{
	int	i;

	if (leftover == NULL)
		return ;
	i = OPEN_MAX - 1;
	while (i >= 0)
	{
		if (leftover[i] != NULL)
			free(leftover[i]);
		leftover[i] = NULL;
		i--;
	}
}

int	check_leftover(char **leftover, t_gnl_data *gnl)
{
	t_check_leftover_data	cl;

	if (!(*leftover))
		return (0);
	cl.old_l = 0;
	while ((*leftover)[cl.old_l] != '\0')
		cl.old_l++;
	if (check_newline(*leftover) == cl.old_l)
	{
		gnl->return_line = *leftover;
		*leftover = 0;
		return (1);
	}
	cl.new_l = cl.old_l - (check_newline(*leftover) + 1);
	if (cl.new_l == 0)
	{
		gnl->return_line = *leftover;
		*leftover = 0;
		return (2);
	}
	return (check_leftover_sub1(leftover, gnl, &cl));
}

static int	check_leftover_sub1(char **leftover, t_gnl_data *gnl, \
			t_check_leftover_data *cl)
{
	gnl->return_line = (char *)malloc(cl->old_l - cl->new_l + 1);
	if (!gnl->return_line)
		return (-1);
	cl->new_leftover = (char *)malloc(cl->new_l + 1);
	if (!cl->new_leftover)
		return (-1);
	cl->old_l = 0;
	cl->new_l = 0;
	while ((*leftover)[cl->old_l] != '\n')
		gnl->return_line[cl->new_l++] = (*leftover)[cl->old_l++];
	gnl->return_line[cl->new_l++] = (*leftover)[cl->old_l++];
	gnl->return_line[cl->new_l] = '\0';
	cl->new_l = 0;
	while ((*leftover)[cl->old_l] != 0)
		cl->new_leftover[cl->new_l++] = (*leftover)[cl->old_l++];
	cl->new_leftover[cl->new_l] = 0;
	free(*leftover);
	*leftover = cl->new_leftover;
	return (2);
}

int	put_leftover(t_goread_data *gr, char **leftover,
			t_gnl_data *gnl)
{
	t_putleft_data	pl;

	*leftover = 0;
	if (++gr->checkline_ret >= (size_t)gr->read_ret)
		return (1);
	pl.new_len = gr->read_ret - gr->checkline_ret;
	*leftover = (char *)malloc(pl.new_len + 1);
	if (*leftover == 0)
		return (0);
	pl.new_i = 0;
	while (pl.new_i < pl.new_len)
		(*leftover)[pl.new_i++] \
		= gnl->read_buffer[gr->checkline_ret++];
	(*leftover)[pl.new_i] = '\0';
	return (1);
}

size_t	check_newline(char *buffer)
{
	size_t	i;

	if (buffer == 0)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}
