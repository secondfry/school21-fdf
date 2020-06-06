/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:41:19 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:51:52 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

void	loop_calculate_matrix_world_rotation(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_ROTATION))
		return ;
	init_world_rotation(fdf);
	fdf->flags -= FLAG_INVALIDATE_WORLD_ROTATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}

void	loop_put_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	loop_before_next_update(t_fdf *fdf)
{
	mlx_do_sync(fdf->mlx);
	if (fdf->options & OPTION_ENABLE_ROTATION)
		fdf->flags |= FLAG_INVALIDATE_LOCAL_ROTATION;
}

void	loop_render_hud_1(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 20, 0xFFFFF,
		"Movement L/R: QE");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFF,
		"Movement F/B: WS");
	mlx_string_put(fdf->mlx, fdf->win, 10, 40, 0xFFFFF,
		"Rotation L/R: AD");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFF,
		"Model Rotation: R");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFF,
		"Camera Perspective: F");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFF,
		"Force Isometric: T");
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, 0xFFFFF,
		"Reset Rotation: G");
}

void	loop_render_hud_2(t_fdf *fdf)
{
	char *tmp;

	mlx_string_put(fdf->mlx, fdf->win, 10, 100, 0xFFFFF, "Camera Position:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFF, "X:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0xFFFFF, "Y:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 130, 0xFFFFF, "Z:");
	tmp = ft_itoa(fdf->camera_position[0]);
	mlx_string_put(fdf->mlx, fdf->win, 30, 110, 0xFFFFF, tmp);
	ft_memdel((void**)&tmp);
	tmp = ft_itoa(fdf->camera_position[1]);
	mlx_string_put(fdf->mlx, fdf->win, 30, 120, 0xFFFFF, tmp);
	ft_memdel((void**)&tmp);
	tmp = ft_itoa(fdf->camera_position[2]);
	mlx_string_put(fdf->mlx, fdf->win, 30, 130, 0xFFFFF, tmp);
	ft_memdel((void**)&tmp);
	mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0xFFFFF, "Rotating:");
	fdf->options & OPTION_ROTATION_X
		? mlx_string_put(fdf->mlx, fdf->win, 10, 160, 0xFFFFF, "X") : 0;
	fdf->options & OPTION_ROTATION_Y
		? mlx_string_put(fdf->mlx, fdf->win, 30, 160, 0xFFFFF, "Y") : 0;
	fdf->options & OPTION_ROTATION_Z
		? mlx_string_put(fdf->mlx, fdf->win, 50, 160, 0xFFFFF, "Z") : 0;
}
