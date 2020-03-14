/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 00:00:05 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef float	*t_matrix_4;
typedef float	*t_vector_4;
typedef float	*t_quaterion;

void		t_vertex_4_print(t_vector_4 self);

/*
** http://www.opengl-tutorial.org/assets/faq_quaternions/index.html
*/

t_matrix_4	matrix_new_identity()
{
	t_matrix_4	ret;

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = ret[5] = ret[10] = ret[15] = 1;
	return (ret);
}

t_matrix_4	martix_new_translation(float x, float y, float z)
{
	t_matrix_4	ret;

	ret = matrix_new_identity();
	ret[3] = x;
	ret[7] = y;
	ret[11] = z;
	return (ret);
}

t_matrix_4	matrix_new_scale(float factor_x, float factor_y, float factor_z)
{
	t_matrix_4  ret;

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = factor_x;
	ret[5] = factor_y;
	ret[10] = factor_z;
	ret[15] = 1;
	return (ret);
}

t_matrix_4	matrix_new_rotation(float angle_x, float angle_y, float angle_z)
{
	t_matrix_4  ret;
	float       h[8];

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	h[0] = cos(angle_x);
	h[1] = sin(angle_x);
	h[2] = cos(angle_y);
	h[3] = sin(angle_y);
	h[4] = cos(angle_z);
	h[5] = sin(angle_z);
	h[6] = h[0] * h[3];
	h[7] = h[1] * h[3];
	ret[0] = h[2] * h[4];
	ret[1] = -h[2] * h[5];
	ret[2] = h[3];
	ret[4] = h[7] * h[4] + h[0] * h[5];
	ret[5] = -h[7] * h[5] + h[0] * h[4];
	ret[6] = -h[1] * h[2];
	ret[8] = -h[6] * h[4] + h[1] * h[5];
	ret[9] = h[6] * h[5] + h[1] * h[4];
	ret[10] = h[0] * h[2];
	ret[3] = ret[7] = ret[11] = ret[12] = ret[13] = ret[14]
		= 0;
	ret[15] = 1;
	return (ret);
}

t_quaterion	quaternion_new(float angle_x, float angle_y, float angle_z)
{
	t_quaterion	ret;
	float		h[8];

	h[7] = sin(angle_x * 0.5F);
	h[6] = cos(angle_x * 0.5F);
	h[5] = sin(angle_y * 0.5F);
	h[4] = cos(angle_y * 0.5F);
	h[3] = sin(angle_z * 0.5F);
	h[2] = cos(angle_z * 0.5F);
	h[1] = h[6] * h[4];
	h[0] = h[7] * h[5];
	ret = (float *)ft_memalloc(sizeof(float) * 4);
	ret[0] = h[3] * h[1] - h[2] * h[0];
	ret[1] = h[2] * h[7] * h[4] + h[3] * h[6] * h[5];
	ret[2] = h[2] * h[6] * h[5] - h[3] * h[7] * h[4];
	ret[3] = h[2] * h[1] + h[3] * h[0];
	return (ret);
}

t_matrix_4	quaternion_to_matrix(t_quaterion self)
{
	t_matrix_4	ret;
	float       h[9];

	h[8] = self[0] * self[0];
    h[7] = self[0] * self[1];
    h[6] = self[0] * self[2];
    h[5] = self[0] * self[3];
    h[4] = self[1] * self[1];
    h[3] = self[1] * self[2];
    h[2] = self[1] * self[3];
    h[1] = self[2] * self[2];
    h[0] = self[2] * self[3];
	ret = (float *)ft_memalloc(sizeof(float) * 16);
    ret[0] = 1 - 2 * ( h[4] + h[1] );
    ret[4] =     2 * ( h[7] - h[0] );
    ret[8] =     2 * ( h[6] + h[2] );
    ret[1] =     2 * ( h[7] + h[0] );
    ret[5] = 1 - 2 * ( h[8] + h[1] );
    ret[9] =     2 * ( h[3] - h[5] );
    ret[2] =     2 * ( h[6] - h[2] );
    ret[6] =     2 * ( h[3] + h[5] );
    ret[10] = 1 - 2 * ( h[8] + h[4] );
    ret[15] = 1;
    return (ret);
}

t_matrix_4	matrix_new_projection(float fov, float ratio, float near, float far)
{
	t_matrix_4  ret;
	float		s;

    s = 1 / tan(fov / 2 * M_PI / 180);
	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = s / ratio;
	ret[5] = s;
	ret[10] = -1 * (far + near) / (far - near);
	ret[11] = -1 * 2 * far * near / (far - near);
	ret[14] = -1;
	ret[15] = 1;
	return (ret);
}

t_vector_4	matrix_on_vector(t_matrix_4 _m, t_vector_4 _v)
{
	t_vector_4	ret;

	ret = (float *)ft_memalloc(sizeof(float) * 4);
	ret[0] = _m[0] * _v[0] + _m[1] * _v[1] + _m[2] * _v[2] + _m[3] * _v[3];
	ret[1] = _m[4] * _v[0] + _m[5] * _v[1] + _m[6] * _v[2] + _m[7] * _v[3];
	ret[2] = _m[8] * _v[0] + _m[9] * _v[1] + _m[10] * _v[2] + _m[11] * _v[3];
	ret[3] = _m[12] * _v[0]
		+ _m[13] * _v[1]
		+ _m[14] * _v[2]
		+ _m[15] * _v[3];
	return (ret);
}

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

	int bpp = 0;
	int sl = 0;
	int e = 0;
	int *data = (int *)mlx_get_data_addr(img, &bpp, &sl, &e);

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
		t_vertex_4_print(points[i]);
		t_vertex_4_print(tmp[0]);
		t_vertex_4_print(tmp[1]);
		t_vertex_4_print(tmp[2]);
		t_vertex_4_print(tmp[3]);
		ft_memdel((void**)&tmp[0]);
		ft_memdel((void**)&tmp[1]);
		ft_memdel((void**)&tmp[2]);
		printf("\n");
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
		data[WIDTH * (size_t)(point[1]) + (size_t)(point[0])] = 0x00FFFFFF;
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
