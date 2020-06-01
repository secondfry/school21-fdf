/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 01:26:20 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	ft_ptr_check(fdf->mlx, "[main] mlx_init errored.", 0);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, TITLE);
	ft_ptr_check(fdf->win, "[main] mlx_new_window errored.", 1, fdf->mlx);
}

void		init_mlx_image(t_fdf *fdf)
{
	int bits_per_pixel;
	int size_line;
	int endianess;

	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
	{
		ft_putstr("[main] mlx_new_image errored.");
		mlx_destroy_window(fdf->mlx, fdf->win);
		ft_memdel(&(fdf->mlx));
		exit(ENOMEM);
	}
	fdf->img_data = (int *)mlx_get_data_addr(
		fdf->img, &bits_per_pixel, &size_line, &endianess);
	fdf->size_line_char = (size_t)size_line;
	fdf->size_line_int = (size_t)(size_line / 4);
}

void		init_pipeline(t_fdf *fdf)
{
	fdf->matrix_translation = matrix_new_identity();
	fdf->matrix_rotation = matrix_new_identity();
	fdf->matrix_projection = matrix_new_identity();
	fdf->matrix_view = matrix_new_identity();
	fdf->options = FLAG_INVALIDATE_TRANSLATION | FLAG_INVALIDATE_ROTATION
				  | FLAG_INVALIDATE_PROJECTION;
	fdf->matrix_projection_properties = vector_new(
		90.0f, WIDTH / (float) HEIGHT, 0.1f, 100.0f);
}

#include <fcntl.h>
#include "get_next_line.h"

void		input(t_fdf *fdf, char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *data = 0;
	char *saver = 0;
	char *endptr;
	size_t width = 0;
	while (get_next_line(fd, &data) > 0) {
		saver = data;
		char **elems = ft_strsplit(data, ' ');
		size_t i = 0;
		while (elems[i]) {
			ft_strtol(elems[i], &endptr, 10);
			if (elems[i] == endptr)
			{
				ft_putstr("loshok na pososhok\n");
				exit(EINVAL);
			}
			fdf->point_count++;
			i++;
		}

		if (width != 0 && width != i)
		{
			ft_putstr("loshok na pososhok\n");
			exit(EINVAL);
		}
		width = i;

		ft_memdel((void**)&saver);
	}

	close(fd);
	// exit(0);
	fdf->points = (t_vector_4 *)malloc(sizeof(t_vector_4) * fdf->point_count);
	fdf->width = width;
	fdf->height = fdf->point_count / fdf->width;
	fd = open(filename, O_RDONLY);
	data = 0;
	size_t counter_dot = 0;
	size_t counter_line = 0;
	while (get_next_line(fd, &data) > 0) {
		char **arr = ft_strsplit(data, ' ');
		size_t counter_column = 0;
		while (arr[counter_column]) {
			int height = ft_atoi(arr[counter_column]);
			fdf->points[counter_dot] = (t_vector_4)malloc(sizeof(float) * 4);
			fdf->points[counter_dot][0] = counter_column;
			fdf->points[counter_dot][1] = counter_line;
			fdf->points[counter_dot][2] = (float)height;
			fdf->points[counter_dot][3] = 1.f;
			ft_memdel((void**)(arr + counter_column));
			counter_column++;
			counter_dot++;
		}
		counter_line++;
		ft_memdel((void**)&data);
	}
	fdf->height = counter_line;
	close(fd);
}

int			main(int argc, char** argv)
{
	t_fdf	fdf;

	if (argc < 2) {
		return (EINVAL);
	}
	fdf.point_count = 0;
	input(&fdf, argv[argc - 1]);
//	return (0);
	init_mlx(&fdf);
	init_mlx_image(&fdf);
	init_pipeline(&fdf);
//	init_teapot(&fdf);
	fdf.redraw = 1;
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (ft_atoi(argv[argc - 1]));
}
