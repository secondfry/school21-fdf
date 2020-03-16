/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 01:04:37 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/16 04:06:33 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_factory.h"

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

t_matrix_4	matrix_new_translation(float x, float y, float z)
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
	t_matrix_4	ret;

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = factor_x;
	ret[5] = factor_y;
	ret[10] = factor_z;
	ret[15] = 1;
	return (ret);
}

t_matrix_4	matrix_new_rotation(float angle_x, float angle_y, float angle_z)
{
	t_matrix_4	ret;
	float		h[8];

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

#include <stdio.h>

t_matrix_4	matrix_new_projection(float fov_x, float fov_y, float near, float far)
{
	t_matrix_4	ret;
	float		sx;
	float		sy;

	printf("%f, %f, %f, %f\n", fov_x, fov_y, near, far);
	sx = 1 / tan(fov_x / 2 * M_PI / 180);
	sy = 1 / tan(fov_y / 2 * M_PI / 180);
	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = sx;
	ret[5] = sy;
	ret[10] = -1 * far / (far - near);
	ret[11] = -1 * far * near / (far - near);
	ret[14] = -1;
	ret[15] = 0;
	return (ret);
}

t_matrix_4	matrix_new_projection_2(float width, float height, float near, float far)
{
	t_matrix_4	ret;

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = 2 * near / width;
	// ret[0] = 1;
	ret[5] = 2 * near / height;
	// ret[5] = 1;
	ret[10] = -1 * (far + near) / (far - near);
	ret[14] = -1;
	ret[11] = -1 * 2 * far * near / (far - near);
	ret[15] = 0;
	return (ret);
}

// THIS ONE WORKS BLUYAT
t_matrix_4	matrix_new_projection_3(float fov, float ratio, float near, float far)
{
	t_matrix_4	ret;
	float scale = tan(fov * 0.5 * M_PI / 180) * near;
	float width = 2 * ratio * scale;
	float height = 2 * scale;

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = 2 * near / width;
	ret[5] = 2 * near / height;
	ret[10] = -1 * (far + near) / (far - near);
	ret[14] = -1;
	ret[11] = -2 * far * near / (far - near);
	ret[15] = 0;
	return (ret);
}

t_matrix_4	matrix_new_projection_4(float fov, float ratio, float near, float far)
{
	t_matrix_4	ret;
	float scale = 1 / tan(fov * 0.5 * M_PI / 180);

	ret = (float *)ft_memalloc(sizeof(float) * 16);
	ret[0] = scale;
	ret[5] = scale;
	ret[10] = -1 * far / (far - near);
	ret[11] = -1;
	ret[14] = -1 * far * near / (far - near);
	ret[15] = 0;
	return (ret);
}
