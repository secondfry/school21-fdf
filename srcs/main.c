/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 17:20:13 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		t_vertex_4_print(t_vector_4 self);

t_vector_4	vector_new(float x, float y, float z, float w)
{
	t_vector_4	ret;

	ret = (float *)ft_memalloc(sizeof(float) * 4);
	ret[0] = x;
	ret[1] = y;
	ret[2] = z;
	ret[3] = w;
	return (ret);
}

int     main(int argc, char** argv) {
	void    *mlx;
	void    *win;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr("[main] mlx_init errored.");
		return (1);
	}

	win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		ft_putstr("[main] mlx_new_window errored.");
		ft_memdel((void**)&mlx);
		return (1);
	}

	void *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putstr("[main] mlx_new_image errored.");
		mlx_destroy_window(mlx, win);
		ft_memdel((void**)&mlx);
		return (1);
	}

	int bits_per_pixel = 0;
	int size_line = 0;
	int endianess = 0;
	int *data = (int *)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endianess);
	size_line /= 4;

	t_vector_4 points[] = {
		vector_new(0.0f, 0.0f, 0.0f, 1.0f),
		vector_new(10.0f, 0.0f, 0.0f, 1.0f),
		vector_new(0.0f, 10.0f, 0.0f, 1.0f),
		vector_new(10.0f, 10.0f, 0.0f, 1.0f),
		vector_new(0.0f, 0.0f, 10.0f, 1.0f),
		vector_new(10.0f, 0.0f, 10.0f, 1.0f),
		vector_new(0.0f, 10.0f, 10.0f, 1.0f),
		vector_new(10.0f, 10.0f, 10.0f, 1.0f),
	};

	// t_vector_4	camera = {0.0f, 0.0f, 10.0f, 1};
	t_matrix_4	trs = martix_new_translation(0, 0, -10);
	t_quaterion	rot_qua = quaternion_new(-45 * M_PI / 180, 0, -45 * M_PI / 180);
	t_matrix_4	rot_mat = quaternion_to_matrix(rot_qua);
	// t_matrix_4	rot_mat = matrix_new_rotation(0, 0, -45);
	t_matrix_4	projection = matrix_new_projection(90, 4/3, 0.5, 100);

	t_matrix_4	a = matrix_on_matrix(projection, rot_mat);
	t_matrix_4	b = matrix_on_matrix(a, trs);


	t_vector_4	zaloopa[100];
	for (size_t i = 0; i < 8; i++)
	{
		t_vector_4	tmp[10];

		tmp[0] = matrix_on_vector(trs, points[i]);
		tmp[1] = matrix_on_vector(rot_mat, tmp[0]);
		tmp[2] = matrix_on_vector(projection, tmp[1]);
		tmp[3] = (float *)ft_memalloc(sizeof(float) * 4);
		tmp[3][0] = tmp[2][0] + WIDTH / 2;
		tmp[3][1] = tmp[2][1] * (-1) + HEIGHT / 2;
		zaloopa[i] = tmp[2];

		t_vector_4	point = tmp[3];
#ifdef LOG_DEBUG
		t_vertex_4_print(points[i]);
		t_vertex_4_print(tmp[0]);
		t_vertex_4_print(tmp[1]);
		t_vertex_4_print(tmp[2]);
		t_vertex_4_print(tmp[3]);
#endif
		ft_memdel((void**)&tmp[0]);
		ft_memdel((void**)&tmp[1]);
		ft_memdel((void**)&tmp[2]);
		if (point[0] < 0 || point[0] > WIDTH) {
			ft_memdel((void**)&tmp[3]);
			ft_memdel((void**)&tmp);
			continue;
		}
		if (point[1] < 0 || point[1] >= HEIGHT) {
			ft_memdel((void**)&tmp[3]);
			ft_memdel((void**)&tmp);
			continue;
		}
		size_t x = point[0];
		size_t y = point[1];
#ifdef LOG_INFO
		printf("Result { x: %zu, y: %zu }\n", x, y);
#endif
		data[size_line * y + x] = 0x00FFFFFF;
		ft_memdel((void**)&tmp[3]);
		ft_memdel((void**)&tmp);
	}

	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);

	return (ft_atoi(argv[argc - 1]));
}

void		t_vertex_4_print(t_vector_4 self)
{
	printf("Point { x: %5.3f, y: %5.3f, z: %5.3f, w: %5.3f }\n", self[0], self[1], self[2], self[3]);
}
