/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:41:19 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 22:02:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_world_rotation(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_world_rotation);
	fdf->camera_rotation[0] = fmodf(fdf->camera_rotation[0], 360.f);
	fdf->camera_rotation[1] = fmodf(fdf->camera_rotation[1], 360.f);
	fdf->camera_rotation[2] = fmodf(fdf->camera_rotation[2], 360.f);
	fdf->matrix_world_rotation = matrix_new_rotation(
		fdf->camera_rotation[0],
		fdf->camera_rotation[1],
		fdf->camera_rotation[2]);
}

void	init_local_rotation_isometric(t_fdf *fdf)
{
	t_quaterion	quaternion;

	ft_memdel((void**)&fdf->matrix_local_rotation);
	quaternion = quaternion_new(35.264f * M_PI_2F / 90.f, M_PI_4F, 0);
	fdf->matrix_local_rotation = quaternion_to_matrix(quaternion);
	ft_memdel((void**)&quaternion);
	fdf->options -= OPTION_ISOMETRIC;
	if (fdf->options & OPTION_ENABLE_ROTATION)
		fdf->options -= OPTION_ENABLE_ROTATION;
}
