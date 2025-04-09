/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:54:51 by srussame          #+#    #+#             */
/*   Updated: 2024/09/21 03:21:53 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	buffjoin(char **dest, char *src);
static int	go_read(int fd, t_gnl_data *gnl, char **leftover);
static int	go_read_loop(int fd, t_goread_data *gr, t_gnl_data *gnl);
static void	buffjoin_sub1(char **dest, char *src, t_buffjoin_data *bj);

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	t_gnl_data	gnl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (free_leftover(leftover), NULL);
	gnl.return_line = 0;
	gnl.cl_ret = check_leftover(&leftover[fd], &gnl);
	if (gnl.cl_ret == -1)
	{
		free(leftover[fd]);
		leftover[fd] = 0;
		return (0);
	}
	if (gnl.cl_ret == 2)
		return (gnl.return_line);
	if (go_read(fd, &gnl, &leftover[fd]) == 0)
	{
		free(gnl.read_buffer);
		if (gnl.cl_ret == 1)
			free(gnl.return_line);
		return (0);
	}
	free(gnl.read_buffer);
	return (gnl.return_line);
}

static int	go_read(int fd, t_gnl_data *gnl, char **leftover)
{
	t_goread_data	gr;

	gr.readcat = 0;
	gnl->read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!gnl->read_buffer)
		return (0);
	gr.read_ret = read(fd, gnl->read_buffer, BUFFER_SIZE);
	if (gr.read_ret <= 0)
	{
		if (gr.read_ret == -1)
			return (0);
		return (1);
	}
	if (go_read_loop(fd, &gr, gnl) == 0)
		return (0);
	if (buffjoin(&gnl->return_line, gr.readcat) == 0)
	{
		free(gr.readcat);
		return (0);
	}
	free(gr.readcat);
	return (put_leftover(&gr, leftover, gnl));
}

static int	go_read_loop(int fd, t_goread_data *gr, t_gnl_data *gnl)
{
	gnl->read_buffer[gr->read_ret] = 0;
	gr->checkline_ret = check_newline(gnl->read_buffer);
	while (gr->checkline_ret == BUFFER_SIZE)
	{
		if (buffjoin(&gr->readcat, gnl->read_buffer) == 0)
			return (0);
		gr->read_ret = read(fd, gnl->read_buffer, BUFFER_SIZE);
		gnl->read_buffer[gr->read_ret] = 0;
		gr->checkline_ret = check_newline(gnl->read_buffer);
	}
	if (buffjoin(&gr->readcat, gnl->read_buffer) == 0)
		return (0);
	return (1);
}

static int	buffjoin(char **dest, char *src)
{
	t_buffjoin_data	bj;

	bj.old_len = 0;
	while ((*dest) != 0 && (*dest)[bj.old_len] != 0)
		bj.old_len++;
	bj.new_len = 0;
	while (src && src[bj.new_len] != 0 && src[bj.new_len] != '\n')
		bj.new_len++;
	if (src[bj.new_len] == '\n')
		bj.new_len++;
	bj.new_len = bj.new_len + bj.old_len;
	bj.new_dest = (char *)malloc(bj.new_len + 1);
	if (!bj.new_dest)
	{
		if (*dest)
			free(*dest);
		return (0);
	}
	buffjoin_sub1(dest, src, &bj);
	return (1);
}

static void	buffjoin_sub1(char **dest, char *src, t_buffjoin_data *bj)
{
	bj->old_len = 0;
	bj->new_len = 0;
	while ((*dest) != 0 && (*dest)[bj->old_len] != 0)
		bj->new_dest[bj->new_len++] = (*dest)[bj->old_len++];
	bj->old_len = 0;
	while (src != 0 && src[bj->old_len] != '\n' && src[bj->old_len] != 0)
		bj->new_dest[bj->new_len++] = src[bj->old_len++];
	bj->new_dest[bj->new_len] = src[bj->old_len];
	if (src[bj->old_len] == '\n')
		bj->new_dest[++bj->new_len] = '\0';
	if (*dest != 0)
		free(*dest);
	*dest = bj->new_dest;
}

//#define FILE_NAME "testfile"
//#include <stdio.h>
//#include <fcntl.h>
//
//void	print_line(char *line)
//{
//	size_t	i;
//
//	i = 0;
//	if (line == 0)
//	{
//		write(1, "(null)\n", 7);
//		return ;
//	}
//	while (line[i] != '\n' && line[i] != 0)
//	{
//		write(1, &line[i], 1);
//		i++;
//	}
//	if (line[i] == '\n')
//		write(1, "\\n\n", 3);
//	if (line[i] == 0)
//		write(1, "\\0\n", 3);
//}
//
//int	main(void)
//{
//	char	*line;
//	int		fd;
//
//	fd = open(FILE_NAME, O_RDONLY);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
//	close(fd);
//}
