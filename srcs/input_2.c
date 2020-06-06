/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:34:32 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 22:05:19 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

size_t	dots_in_line(char *line, ssize_t *out)
{
	char	*endptr;
	char	**elems;
	size_t	i;
	ssize_t	h;
	ssize_t	h_max;

	h_max = 0;
	elems = ft_strsplit(line, ' ');
	i = 0;
	while (elems[i])
	{
		h = ft_strtol(elems[i], &endptr, 10);
		h_max = h > h_max ? h : h_max;
		if (elems[i] == endptr)
			graceful(EINVAL, "Provide valid map, please.");
		ft_memdel((void**)(elems + i));
		i++;
	}
	ft_memdel((void**)&elems);
	*out = h_max;
	return (i);
}

void	scan_file(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	size_t	dots;
	ssize_t	h[2];

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, "Provide valid file argument, please.") : 0;
	h[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		dots = dots_in_line(line, h);
		h[1] = h[0] > h[1] ? h[0] : h[1];
		fdf->point_count += dots;
		if ((fdf->cols != 0 && fdf->cols != dots) || dots == 0)
			graceful(EINVAL, "Provide valid map, please.");
		fdf->cols = dots;
		fdf->rows++;
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	fdf->cols == 0 ? graceful(EINVAL, "Provide valid map, please.") : 0;
	fd = close(fd);
	fd == -1 ? graceful(EINVAL, "Close failed!") : 0;
	fdf->height = h[1];
}

void	fill_line(t_fdf *fdf, char *line, t_i *i)
{
	char	**dots;

	dots = ft_strsplit(line, ' ');
	i->x = 0;
	while (dots[i->x])
	{
		i->z = ft_atoi(dots[i->x]);
		i->z_max = i->z_max > i->z ? i->z_max : i->z;
		fdf->points[i->d] = vector_new(i->x, -1.f * i->y, i->z, 1.f);
		fdf->heights[i->d] = 230 * i->z / fdf->height;
		ft_memdel((void**)dots + i->x);
		i->x++;
		i->d++;
	}
	i->y++;
	ft_memdel((void**)&dots);
	ft_memdel((void**)&line);
}

void	fill_data(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	t_i		i;

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, "Provide valid file argument, please.") : 0;
	ft_bzero(&i, sizeof(size_t) * 5);
	while (get_next_line(fd, &line) > 0)
		fill_line(fdf, line, &i);
	ft_memdel((void**)&line);
	close(fd);
	fdf->height = i.z_max;
}
