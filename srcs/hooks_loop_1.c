/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:40:26 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

int		loop_hook(t_fdf *fdf)
{
	loop_calculate_matrix_local_normalization(fdf);
	loop_calculate_matrix_local_scale(fdf);
	loop_calculate_matrix_world_translation(fdf);
	loop_calculate_matrix_local_rotation(fdf);
	loop_calculate_matrix_world_projection(fdf);
	loop_calculate_matrix_view(fdf);
	loop_fill_image(fdf);
	loop_render(fdf);
	return (0);
}

void	loop_calculate_matrix_local_normalization(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_NORMALIZATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_LOCAL_NORMALIZATION");
#endif
	init_local_normalization(fdf);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_NORMALIZATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_local_scale(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_SCALE))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_LOCAL_SCALE");
#endif
	init_local_scale(fdf);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_SCALE;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

#include <stdio.h>

void	loop_calculate_matrix_local_rotation(t_fdf *fdf)
{
	t_quaterion	quaternion;

	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_ROTATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_LOCAL_ROTATION");
#endif
	ft_memdel((void**)&fdf->matrix_local_rotation);
	quaternion = quaternion_new(fdf->frame++ * M_PI_F / 180.f, 0, 0);
//	quaternion = quaternion_new(5 * M_PI_F / 180.f, 0, 0);
//	quaternion = quaternion_new(35.264f * M_PI_2F / 90.f, M_PI_4F, 0); // isometric
	fdf->matrix_local_rotation = quaternion_to_matrix(quaternion);
	ft_memdel((void**)&quaternion);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_ROTATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_world_translation(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_TRANSLATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_WORLD_TRANSLATION");
#endif
	init_world_translation(fdf);
	fdf->flags -= FLAG_INVALIDATE_WORLD_TRANSLATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_world_projection(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_PROJECTION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_WORLD_PROJECTION");
#endif
//	ft_memdel((void**)&fdf->matrix_world_projection);
//	fdf->matrix_world_projection = matrix_new_projection(
//		fdf->matrix_world_projection_properties[0],
//		fdf->matrix_world_projection_properties[1],
//		fdf->matrix_world_projection_properties[2],
//		fdf->matrix_world_projection_properties[3]);
	fdf->flags -= FLAG_INVALIDATE_WORLD_PROJECTION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	step(t_matrix_4 *a, t_matrix_4 b)
{
	t_matrix_4 res;

	res = matrix_on_matrix(*a, b);
	ft_memdel((void**)a);
	*a = res;
}

void	loop_calculate_matrix_view(t_fdf *fdf)
{
	t_matrix_4	tmp;

	if (!(fdf->flags & FLAG_INVALIDATE_VIEW))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_VIEW");
#endif
	ft_memdel((void**)&fdf->matrix_view);
	tmp = matrix_new_identity();
//	step(&tmp, fdf->matrix_world_projection);
//	step(&tmp, fdf->matrix_world_rotation);
//	step(&tmp, fdf->matrix_world_translation);
//	step(&tmp, fdf->matrix_local_translation);
	step(&tmp, fdf->matrix_local_rotation);
	step(&tmp, fdf->matrix_local_scale);
	step(&tmp, fdf->matrix_local_normalization);
	fdf->matrix_view = tmp;
	fdf->flags -= FLAG_INVALIDATE_VIEW;
	fdf->flags |= FLAG_REDRAW;
}
