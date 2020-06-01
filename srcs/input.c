/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:34:32 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 06:35:32 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

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

size_t	dots_in_line(char *line)
{
	char	*endptr;
	char	**elems;
	size_t	i;

	elems = ft_strsplit(line, ' ');
	i = 0;
	while (elems[i])
	{
		ft_strtol(elems[i], &endptr, 10);
		if (elems[i] == endptr)
			graceful(EINVAL, "Provide valid map, please.");
		ft_memdel((void**)(elems + i));
		i++;
	}
	ft_memdel((void**)&elems);
	return (i);
}

void	scan_file(t_fdf *fdf, char *filename)
{
	int		fd;
	int		res;
	char	*line;
	size_t	dots;

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, "Provide valid file argument, please.") : 0;
	while (get_next_line(fd, &line) > 0)
	{
		dots = dots_in_line(line);
		fdf->point_count += dots;
		if ((fdf->width != 0 && fdf->width != dots) || dots == 0)
			graceful(EINVAL, "Provide valid map, please.");
		fdf->width = dots;
		fdf->height++;
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	fdf->width == 0 ? graceful(EINVAL, "Provide valid map, please.") : 0;
	res = close(fd);
	res == -1 ? graceful(EINVAL, "Close failed!") : 0;
}

void	fill_data(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*line;
	char	**dots;
	t_i		i;

	fd = open(filename, O_RDONLY);
	fd == -1 ? graceful(EINVAL, "Provide valid file argument, please.") : 0;
	i.d = 0;
	i.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		dots = ft_strsplit(line, ' ');
		i.x = 0;
		while (dots[i.x])
		{
			i.z = ft_atoi(dots[i.x]);
			fdf->points[i.d] = vector_new(i.x, i.y, i.z, 1.f);
			ft_memdel((void**)dots + i.x);
			i.x++;
			i.d++;
		}
		i.y++;
		ft_memdel((void**)&dots);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	close(fd);
}

void	input(t_fdf *fdf, char *filename)
{
	check_file(filename);
	scan_file(fdf, filename);
	fdf->points = (t_vector_4 *)malloc(sizeof(t_vector_4) * fdf->point_count);
	fdf->points == 0 ? exit(ENOMEM) : 0;
	fill_data(fdf, filename);
}
