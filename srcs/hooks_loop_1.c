/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:51:38 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

int		loop_destroy_hook(void)
{
	ft_putendl("Goodbye!");
	exit(0);
}

int		loop_hook(t_fdf *fdf)
{
	loop_calculate_matrix_local_normalization(fdf);
	loop_calculate_matrix_local_scale(fdf);
	loop_calculate_matrix_local_rotation(fdf);
	loop_calculate_matrix_world_translation(fdf);
	loop_calculate_matrix_world_rotation(fdf);
	loop_calculate_matrix_world_projection(fdf);
	loop_calculate_matrix_view(fdf);
	loop_fill_image(fdf);
	loop_put_image(fdf);
	loop_render_hud_1(fdf);
	loop_render_hud_2(fdf);
	loop_before_next_update(fdf);
	return (0);
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
	ft_memdel((void**)&fdf->matrix_view);
	tmp = matrix_new_identity();
	step(&tmp, fdf->matrix_world_projection);
	step(&tmp, fdf->matrix_world_rotation);
	step(&tmp, fdf->matrix_world_translation);
	step(&tmp, fdf->matrix_local_translation);
	step(&tmp, fdf->matrix_local_rotation);
	step(&tmp, fdf->matrix_local_scale);
	step(&tmp, fdf->matrix_local_normalization);
	fdf->matrix_view = tmp;
	fdf->flags -= FLAG_INVALIDATE_VIEW;
	fdf->flags |= FLAG_REDRAW;
}
