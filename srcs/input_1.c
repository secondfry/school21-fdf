/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:34:32 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 22:05:10 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	input(t_fdf *fdf, char *filename)
{
	check_file(filename);
	scan_file(fdf, filename);
	fdf->points = (t_vector_4 *)malloc(sizeof(t_vector_4) * fdf->point_count);
	fdf->points == 0 ? exit(ENOMEM) : 0;
	fdf->heights = (t_byte *)malloc(sizeof(t_byte) * fdf->point_count);
	fdf->heights == 0 ? exit(ENOMEM) : 0;
	fill_data(fdf, filename);
}

void	check_file(char *filename)
{
	int		fd;
	ssize_t	res;

	fd = open(filename, O_RDWR);
	fd == -1 ? graceful(EINVAL, "Provide valid file argument, please.") : 0;
	res = close(fd);
	res == -1 ? graceful(EINVAL, "Close failed!") : 0;
	fd = open(filename, O_RDONLY);
	res = read(fd, 0, 0);
	res == -1 ? graceful(EINVAL, "Read failed!") : 0;
	res = close(fd);
	res == -1 ? graceful(EINVAL, "Close failed!") : 0;
}
