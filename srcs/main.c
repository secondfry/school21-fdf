/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/14 21:14:08 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef float	t_matrix_4[16];
typedef float	t_quaterion[4];

/*
** http://www.opengl-tutorial.org/assets/faq_quaternions/index.html
*/

float		*matrix_new_identity()
{
	t_matrix_4  *ret;

	ret = (t_matrix_4 *)ft_memalloc(sizeof(t_matrix_4));
	mat[0] = mat[5] = mat[10] = mat[15] = 1;
	return (ret);
}

float		*martix_new_translation(float x, float y, float z)
{
	t_matrix_4	*ret;

	ret = matrix_new_identity();
	ret[3] = x;
	ret[7] = y;
	ret[11] = z;
	return (ret);
}

float		*matrix_new_scale(float factor_x, float factor_y, float factor_z)
{
	t_matrix_4  *ret;

	ret = (t_matrix_4 *)ft_memalloc(sizeof(t_matrix_4));
	mat[0] = factor_x;
	mat[5] = factor_y;
	mat[10] = factor_z;
	mat[15] = 1;
	return (ret);
}

float		*matrix_new_rotation(float angle_x, float angle_y, float angle_z)
{
	t_matrix_4  *ret;
	float       h[8];

	ret = (t_matrix_4 *)ft_memalloc(sizeof(t_matrix_4));
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
	ret[3] = ret[7] = ret[11] = ret[12] = ret[13] = ret[14] = 0;
	ret[15] = 1;
	return (ret);
}

float		*quaternion_new(float angle_x, float angle_y, float angle_z)
{
	t_quaterion	*ret;
	float		h[8];

	h[7] = sin(angle_x * 0.5F);
	h[6] = cos(angle_x * 0.5F);
	h[5] = sin(angle_y * 0.5F);
	h[4] = cos(angle_y * 0.5F);
	h[3] = sin(angle_z * 0.5F);
	h[2] = cos(angle_z * 0.5F);
	h[1] = h[6] * h[4];
	h[0] = h[7] * h[5];
	ret = (t_quaterion *)ft_memalloc(sizeof(t_quaterion));
	ret[0] = h[3] * h[1] - h[2] * h[0];
	ret[1] = h[2] * h[7] * h[4] + h[3] * h[6] * h[5];
	ret[2] = h[2] * h[6] * h[5] - h[3] * h[7] * h[4];
	ret[3] = h[2] * h[1] + h[3] * h[0];
}

t_matrix_4	*quaternion_to_matrix(t_quaterion *self)
{
	t_matrix_4	*ret;

	h[8] = self[0] * self[0];
    h[7] = self[0] * self[1];
    h[6] = self[0] * self[2];
    h[5] = self[0] * self[3];
    h[4] = self[1] * self[1];
    h[3] = self[1] * self[2];
    h[2] = self[1] * self[3];
    h[1] = self[2] * self[2];
    h[0] = self[2] * self[3];
	ret = (t_matrix_4 *)ft_memalloc(sizeof(t_matrix_4));
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

float		*matrix_new_projection(float fov, float ratio, float near, float far)
{
	t_matrix_4  *ret;
	float		h[10];

    h[0] = 1 / tan(h[1] / 2 * M_PI / 180);
	ret = (t_matrix_4 *)ft_memalloc(sizeof(t_matrix_4));
	ret[0] = h[0] / ratio;
	ret[5] = h[0];
	ret[10] = -1 * (far + near) / (far - near);
	ret[11] = -1 * 2 * far * near / (far - near);
	ret[14] = -1;
	ret[15] = 1;
	return (ret);
}

t_point 	*point_new(size_t x, size_t y, size_t height)
{
	t_point *ret;

	ret = (t_point *)malloc(sizeof(t_point));
	if (!ret)
		return (ret);
	ret->x = x;
	ret->y = y;
	ret->z = height;
	ret->xr = x;
	ret->yr = y;
	ret->zr = height;
	point_calc(ret, 0, 0, 0);
	return (ret);
}

#ifdef _STDIO_H_
void    point_print(t_point *self)
{
	printf(
		"Point {\n x: %7zu, y: %7zu, z: %7zu,\n xr: %6.3f, yr: %6.3f, zr: %6.3f\n xs: %6d, ys: %6d\n}\n",
		self->x,
		self->y,
		self->z,
		self->xr,
		self->yr,
		self->zr,
		self->screen_x,
		self->screen_y
	);
}
#endif

short   point_calc_helper(float a, float b, float c)
{
	return ((a - b) * c + b);
}

void    point_calc(t_point *point, float x, float y, float z)
{
	float   factor;

	factor = (point->zr - z) / point->zr;
	point->screen_x = point_calc_helper(point->xr, x, factor) + WIDTH / 2;
	point->screen_y = point_calc_helper(point->yr, y, factor) * (-1) + HEIGHT / 2;
}

void    rotate_x(t_point *point, float angle)
{
	float cosRot = cos(angle * M_PI / 180);
	float sinRot = sin(angle * M_PI / 180);
	point->yr = cosRot * point->yr - sinRot * point->zr;
	point->zr = sinRot * point->yr + cosRot * point->zr;
}

void    rotate_y(t_point *point, float angle)
{
	float cosRot = cos(angle * M_PI / 180);
	float sinRot = sin(angle * M_PI / 180);
	point->xr = cosRot * point->xr + sinRot * point->zr;
	point->zr = -sinRot * point->xr + cosRot * point->zr;
}

void    rotate_z(t_point *point, float angle)
{
	float cosRot = cos(angle * M_PI / 180);
	float sinRot = sin(angle * M_PI / 180);
	point->xr = cosRot * point->xr - sinRot * point->yr;
	point->yr = sinRot * point->xr + cosRot * point->yr;
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

	t_point *points[] = {
		point_new(0, 0, 0),
		point_new(1, 0, 0),
		point_new(2, 0, 0),
		point_new(0, 1, 0),
		point_new(1, 1, 10),
		point_new(2, 1, 0),
		point_new(0, 2, 0),
		point_new(1, 2, 0),
		point_new(2, 2, 0)
	};

	for (size_t i = 0; i < 9; i++)
	{
		// rotate_x(points[i], 30);
		point_calc(points[i], 1, 1, -10);
#ifdef _STDIO_H_
		point_print(points[i]);
#endif
	}




	mlx_loop(mlx);

	return (ft_atoi(argv[argc - 1]));
}
