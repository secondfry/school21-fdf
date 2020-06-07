/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:50:12 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

void	loop_calculate_matrix_local_normalization(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_NORMALIZATION))
		return ;
	init_local_normalization(fdf);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_NORMALIZATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_local_scale(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_SCALE))
		return ;
	init_local_scale(fdf);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_SCALE;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_local_rotation(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_LOCAL_ROTATION))
		return ;
	init_local_rotation(fdf);
	fdf->flags -= FLAG_INVALIDATE_LOCAL_ROTATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_world_translation(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_TRANSLATION))
		return ;
	init_world_translation(fdf);
	fdf->flags -= FLAG_INVALIDATE_WORLD_TRANSLATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_world_projection(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_PROJECTION))
		return ;
	init_world_projection(fdf);
	fdf->flags -= FLAG_INVALIDATE_WORLD_PROJECTION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}
