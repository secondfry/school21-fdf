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
	loop_calculate_matrix_translation(fdf);
	loop_calculate_matrix_rotation(fdf);
	loop_calculate_matrix_projection(fdf);
	loop_calculate_matrix_view(fdf);
	loop_fill_image(fdf);
	loop_render(fdf);
	return (0);
}

void	loop_calculate_matrix_translation(t_fdf *fdf)
{
	if (!(fdf->options & FLAG_INVALIDATE_TRANSLATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_TRANSLATION");
#endif
	ft_memdel((void**)&fdf->matrix_translation);
	fdf->matrix_translation = matrix_new_translation(
		-1.f * fdf->width / 2.f, -1.f * fdf->height / 2.f, -100.f);
	fdf->options -= FLAG_INVALIDATE_TRANSLATION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_rotation(t_fdf *fdf)
{
	t_quaterion	quaternion;

	if (!(fdf->options & FLAG_INVALIDATE_ROTATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_ROTATION");
#endif
	ft_memdel((void**)&fdf->matrix_rotation);
	quaternion = quaternion_new(M_PI_F + fdf->i++ * M_PI_2F / 180.f, 0, 0);
	fdf->matrix_rotation = quaternion_to_matrix(quaternion);
	ft_memdel((void**)&quaternion);
	fdf->options -= FLAG_INVALIDATE_ROTATION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_projection(t_fdf *fdf)
{
	if (!(fdf->options & FLAG_INVALIDATE_PROJECTION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_PROJECTION");
#endif
	ft_memdel((void**)&fdf->matrix_projection);
	fdf->matrix_projection = matrix_new_projection(
		fdf->matrix_projection_properties[0],
		fdf->matrix_projection_properties[1],
		fdf->matrix_projection_properties[2],
		fdf->matrix_projection_properties[3]);
	fdf->options -= FLAG_INVALIDATE_PROJECTION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_view(t_fdf *fdf)
{
	t_matrix_4	tmp;

	if (!(fdf->options & FLAG_INVALIDATE_VIEW))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_VIEW");
#endif
	ft_memdel((void**)&fdf->matrix_view);
	tmp = matrix_on_matrix(fdf->matrix_projection, fdf->matrix_rotation);
	fdf->matrix_view = matrix_on_matrix(tmp, fdf->matrix_translation);
	ft_memdel((void**)&tmp);
	fdf->options -= FLAG_INVALIDATE_VIEW;
	fdf->redraw = 1;
}
