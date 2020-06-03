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

void	move_camera(t_fdf *fdf, int keycode)
{
	if (!(fdf->options & OPTION_ENABLE_PERSPECTIVE))
		return ;
	fdf->flags |= FLAG_INVALIDATE_WORLD_TRANSLATION;
	keycode == KEY_W ? fdf->camera_position[2] -= 10.f : 0;
	keycode == KEY_S ? fdf->camera_position[2] += 10.f : 0;
	keycode == KEY_Q ? fdf->camera_position[0] -= 10.f : 0;
	keycode == KEY_E ? fdf->camera_position[0] += 10.f : 0;
}

void	rotate_camera(t_fdf *fdf, int keycode)
{
	fdf->flags |= FLAG_INVALIDATE_WORLD_ROTATION;
	keycode == KEY_A ? fdf->camera_rotation[1] -= 0.5f : 0;
	keycode == KEY_D ? fdf->camera_rotation[1] += 0.5f : 0;
}

void	toggle_perspective(t_fdf *fdf)
{
	fdf->options ^= OPTION_ENABLE_PERSPECTIVE;
	fdf->flags |= FLAG_INVALIDATE_LOCAL_SCALE | FLAG_INVALIDATE_WORLD_TRANSLATION
		| FLAG_INVALIDATE_WORLD_PROJECTION | FLAG_REDRAW;
}

void	force_isometric(t_fdf *fdf)
{
	fdf->options |= OPTION_ISOMETRIC;
	fdf->flags |= FLAG_INVALIDATE_LOCAL_ROTATION;
}

int		loop_key_hook(int keycode, t_fdf *fdf)
{
	keycode == KEY_ESC ? loop_destroy_hook(fdf) : 0;
	keycode == KEY_W ? move_camera(fdf, keycode) : 0;
	keycode == KEY_S ? move_camera(fdf, keycode) : 0;
	keycode == KEY_Q ? move_camera(fdf, keycode) : 0;
	keycode == KEY_E ? move_camera(fdf, keycode) : 0;
	keycode == KEY_A ? rotate_camera(fdf, keycode) : 0;
	keycode == KEY_D ? rotate_camera(fdf, keycode) : 0;
	keycode == KEY_R ? fdf->options ^= OPTION_ENABLE_ROTATION : 0;
	keycode == KEY_F ? toggle_perspective(fdf) : 0;
	keycode == KEY_T ? force_isometric(fdf) : 0;
	keycode == KEY_Z ? fdf->options ^= OPTION_ROTATION_X : 0;
	keycode == KEY_X ? fdf->options ^= OPTION_ROTATION_Y : 0;
	keycode == KEY_C ? fdf->options ^= OPTION_ROTATION_Z : 0;
	return (0);
}

int		loop_destroy_hook()
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
	loop_render(fdf);
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
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_VIEW");
#endif
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
