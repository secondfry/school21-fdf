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

size_t			dots_in_line(char *line, ssize_t *out)
{
	char	*endptr;
	char	**elems;
	size_t	i;
	ssize_t	h[3];

	h[0] = SSIZE_T_MIN;
	h[1] = SSIZE_T_MAX;
	elems = ft_strsplit(line, ' ');
	i = 0;
	while (elems[i])
	{
		h[2] = ft_strtol(elems[i], &endptr, 10);
		h[0] = h[2] > h[0] ? h[2] : h[0];
		h[1] = h[2] < h[1] ? h[2] : h[1];
		if (elems[i] == endptr)
			graceful(EINVAL, ERR_MAP_INVALID);
		ft_memdel((void**)(elems + i));
		i++;
	}
	ft_memdel((void**)&elems);
	*out = h[0];
	*(out + 1) = h[1];
	return (i);
}

static t_byte	is_invalid(t_fdf *fdf, size_t dots)
{
	t_byte	res;

	res = ((fdf->cols != 0 && fdf->cols != dots) || dots == 0) ? 1 : 0;
	fdf->cols = dots;
	return (res);
}

void			scan_file(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	size_t	dots;
	ssize_t	h[4];

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, ERR_OPEN) : 0;
	h[2] = SSIZE_T_MIN;
	h[3] = SSIZE_T_MAX;
	while (get_next_line(fd, &line) > 0)
	{
		dots = dots_in_line(line, h);
		h[2] = h[0] > h[2] ? h[0] : h[2];
		h[3] = h[1] < h[3] ? h[1] : h[3];
		fdf->point_count += dots;
		is_invalid(fdf, dots) ? graceful(EINVAL, ERR_MAP_INVALID) : 0;
		fdf->rows++;
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	fdf->cols == 0 ? graceful(EINVAL, ERR_MAP_INVALID) : 0;
	fd = close(fd);
	fd == -1 ? graceful(EINVAL, ERR_CLOSE) : 0;
	fdf->height = h[2] - h[3];
	fdf->floor = h[3];
}

void			fill_line(t_fdf *fdf, char *line, t_i *i)
{
	char	**dots;

	dots = ft_strsplit(line, ' ');
	i->x = 0;
	while (dots[i->x])
	{
		i->z = ft_atoi(dots[i->x]);
		fdf->points[i->d] = vector_new(i->x, -1.f * i->y, i->z, 1.f);
		fdf->heights[i->d] = fdf->height == 0
			? 230
			: 230 * (i->z - fdf->floor) / fdf->height;
		ft_memdel((void**)dots + i->x);
		i->x++;
		i->d++;
	}
	i->y++;
	ft_memdel((void**)&dots);
	ft_memdel((void**)&line);
}

void			fill_data(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	t_i		i;

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, ERR_OPEN) : 0;
	ft_bzero(&i, sizeof(size_t) * 5);
	while (get_next_line(fd, &line) > 0)
		fill_line(fdf, line, &i);
	ft_memdel((void**)&line);
	close(fd);
}
