/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:41:19 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 22:03:39 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_local_normalization(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_local_normalization);
	fdf->matrix_local_normalization = matrix_new_translation(
		-1.f * (float)(fdf->cols - 1) / 2.f,
		(float)(fdf->rows - 1) / 2.f,
		0);
}

void	init_local_scale(t_fdf *fdf)
{
	float	factor;

	ft_memdel((void**)&fdf->matrix_local_scale);
	if (fdf->options & OPTION_ENABLE_PERSPECTIVE)
	{
		factor = M_SQRT1_2_F * fminf(WIDTH, HEIGHT)
			/ fminf(fminf(fdf->cols, fdf->rows), fdf->height);
		fdf->matrix_local_scale = matrix_new_scale(factor, factor, factor);
	}
	else
	{
		factor = 1.f / fmaxf(fmaxf(fdf->cols, fdf->rows), fdf->height);
		fdf->matrix_local_scale = matrix_new_scale(
			factor,
			factor * WIDTH / HEIGHT,
			-1.f * factor);
	}
}

void	init_local_rotation(t_fdf *fdf)
{
	t_quaterion	quaternion;

	if (fdf->options & OPTION_ISOMETRIC)
	{
		ft_memdel((void**)&fdf->matrix_local_rotation);
		quaternion = quaternion_new(35.264f * M_PI_2F / 90.f, M_PI_4F, 0);
		fdf->matrix_local_rotation = quaternion_to_matrix(quaternion);
		ft_memdel((void**)&quaternion);
		fdf->options -= OPTION_ISOMETRIC;
		if (fdf->options & OPTION_ENABLE_ROTATION)
			fdf->options -= OPTION_ENABLE_ROTATION;
	}
	if (!(fdf->options & OPTION_ENABLE_ROTATION))
		return ;
	ft_memdel((void**)&fdf->matrix_local_rotation);
	quaternion = quaternion_new(fdf->frame[0] * M_PI_F / 180.f,
		fdf->frame[1] * M_PI_F / 180.f, fdf->frame[2] * M_PI_F / 180.f);
	fdf->options & OPTION_ROTATION_X ? fdf->frame[0]++ : 0;
	fdf->options & OPTION_ROTATION_Y ? fdf->frame[1]++ : 0;
	fdf->options & OPTION_ROTATION_Z ? fdf->frame[2]++ : 0;
	fdf->frame[0] = fdf->frame[0] % 360;
	fdf->frame[1] = fdf->frame[1] % 360;
	fdf->frame[2] = fdf->frame[2] % 360;
	fdf->matrix_local_rotation = quaternion_to_matrix(quaternion);
	ft_memdel((void**)&quaternion);
}

void	init_world_translation(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_world_translation);
	if (!(fdf->options & OPTION_ENABLE_PERSPECTIVE))
		fdf->matrix_world_translation = matrix_new_identity();
	else
		fdf->matrix_world_translation = matrix_new_translation(
			-1 * fdf->camera_position[0],
			-1 * fdf->camera_position[1],
			-1 * fdf->camera_position[2]);
}

void	init_world_projection(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_world_projection);
	if (!(fdf->options & OPTION_ENABLE_PERSPECTIVE))
		fdf->matrix_world_projection = matrix_new_identity();
	else
		fdf->matrix_world_projection = matrix_new_projection(
			fdf->matrix_world_projection_properties[0],
			fdf->matrix_world_projection_properties[1],
			fdf->matrix_world_projection_properties[2],
			fdf->matrix_world_projection_properties[3]);
}
