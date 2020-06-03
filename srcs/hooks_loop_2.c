/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:43:37 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

t_byte	is_valid(t_const_vector_4 dot)
{
	if (!dot)
		return (0);
	if (dot[3] < 0)
		return (0);
	if (dot[0] < 0 || dot[0] >= WIDTH || dot[1] < 0 || dot[1] >= HEIGHT)
		return (0);
	return (1);
}

void	loop_fill_image(t_fdf *fdf)
{
	size_t	i;
	size_t	dot;
	float	**dots;

	if (!(fdf->flags & FLAG_REDRAW))
		return ;
	ft_bzero(fdf->img_data, fdf->size_line_char * HEIGHT);
	dots = (float**)malloc(sizeof(t_vector_4) * fdf->point_count);
	dots == 0 ? exit(ENOMEM) : 0;
	i = fdf->point_count;
	while (--i != 0ul - 1ul)
	{
		dots[i] = matrix_on_vector(fdf->matrix_view, fdf->points[i]);
		dots[i][0] = (dots[i][0] / dots[i][3] + 1) * 0.5f * WIDTH;
		dots[i][1] = (1 - (dots[i][1] / dots[i][3] + 1) * 0.5f) * HEIGHT;
		if (!is_valid(dots[i]))
			continue;
		bresenham_check(fdf, dots, i);
		dot = fdf->size_line_int * (t_ushort)(dots[i][1])
			+ (t_ushort)(dots[i][0]);
		fdf->img_data[dot] = fdf->img_data[dot] >
			(0x00777777 + 0x10101 * fdf->heights[i]) ? fdf->img_data[dot]
			: 0x00777777 + 0x10101 * fdf->heights[i];
	}
	loop_fill_image_cleanup(fdf, dots);
}

void	bresenham_check(t_fdf *fdf, float **dots, size_t counter)
{
	if (counter + 1 < fdf->point_count
		&& counter % fdf->cols < (counter + 1) % fdf->cols
		&& is_valid(dots[counter + 1]))
		bresenham(fdf, dots, counter, counter + 1);
	if (counter + fdf->cols < fdf->point_count
		&& is_valid(dots[counter + fdf->cols]))
		bresenham(fdf, dots, counter, counter + fdf->cols);
}

void	loop_fill_image_cleanup(t_fdf *fdf, float **data)
{
	size_t	i;

	i = fdf->point_count;
	while (--i != 0ul - 1ul)
		ft_memdel((void**)&data[i]);
	ft_memdel((void**)&data);
}

void	loop_render(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 10, 20, 0xFFFFF, "Movement L/R: QE");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFF, "Movement F/B: WS");
	mlx_string_put(fdf->mlx, fdf->win, 10, 40, 0xFFFFF, "Rotation L/R: AD");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFF, "Model Rotation: R");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFF, "Camera Perspective: F");
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, 0xFFFFF, "Camera Position:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFF, "X:");
	mlx_string_put(fdf->mlx, fdf->win, 30, 90, 0xFFFFF, ft_itoa(fdf->camera_position[0]));
	mlx_string_put(fdf->mlx, fdf->win, 10, 100, 0xFFFFF, "Y:");
	mlx_string_put(fdf->mlx, fdf->win, 30, 100, 0xFFFFF, ft_itoa(fdf->camera_position[1]));
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFF, "Z:");
	mlx_string_put(fdf->mlx, fdf->win, 30, 110, 0xFFFFF, ft_itoa(fdf->camera_position[2]));
	mlx_do_sync(fdf->mlx);
	if (fdf->options & OPTION_ENABLE_ROTATION)
		fdf->flags |= FLAG_INVALIDATE_LOCAL_ROTATION;
}
