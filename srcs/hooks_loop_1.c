/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/05/31 13:57:48 by oadhesiv         ###   ########.fr       */
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
		return;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_TRANSLATION");
#endif
	ft_memdel((void**)&fdf->matrix_translation);
	fdf->matrix_translation = matrix_new_translation(-1.f * fdf->width / 2.f, -1.f * fdf->height / 2.f, -100.f);
	fdf->options -= FLAG_INVALIDATE_TRANSLATION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_rotation(t_fdf *fdf)
{
	t_quaterion	quaternion;

	if (!(fdf->options & FLAG_INVALIDATE_ROTATION))
		return;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_ROTATION");
#endif
	ft_memdel((void**)&fdf->matrix_rotation);
	quaternion = quaternion_new(M_PI_F + fdf->i++ * M_PI_2F / 180.f, 0, 0);
//	quaternion = quaternion_new(M_PI_F, 0, 0);
	fdf->matrix_rotation = quaternion_to_matrix(quaternion);
	ft_memdel((void**)&quaternion);
	fdf->options -= FLAG_INVALIDATE_ROTATION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_projection(t_fdf *fdf)
{
	if (!(fdf->options & FLAG_INVALIDATE_PROJECTION))
		return;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_PROJECTION");
#endif
	ft_memdel((void**)&fdf->matrix_projection);
	fdf->matrix_projection = matrix_new_projection_3(
		fdf->matrix_projection_properties[0],
		fdf->matrix_projection_properties[1],
		fdf->matrix_projection_properties[2],
		fdf->matrix_projection_properties[3]
	);
	fdf->options -= FLAG_INVALIDATE_PROJECTION;
	fdf->options |= FLAG_INVALIDATE_VIEW;
}

void	loop_calculate_matrix_view(t_fdf *fdf)
{
	t_matrix_4	tmp;

	if (!(fdf->options & FLAG_INVALIDATE_VIEW))
		return;
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

void	draw(t_fdf *fdf, t_ushort x, t_ushort y, int color)
{
	size_t dot;

	dot = fdf->size_line_int * y + x;
	if (fdf->img_data[dot])
		return;
	fdf->img_data[dot] = color;
}

void	bresenham(t_fdf *fdf, t_vector_4 a, t_vector_4 b)
{
	if (!a || !b)
		return;
	t_ushort x0 = (t_ushort)a[0];
	t_ushort y0 = (t_ushort)a[1];
	t_ushort x1 = (t_ushort)b[0];
	t_ushort y1 = (t_ushort)b[1];
	short dx = x1 - x0 < 0 ? x0 - x1 : x1 - x0;
	char sx = x0 < x1 ? 1 : -1;
	short dy = y1 - y0 < 0 ? y1 - y0 : y0 - y1;
	char sy = y0 < y1 ? 1 : -1;
	short err = dx + dy;
	while (1)
	{
		draw(fdf, x0, y0, 0x00FF0000);
		if (x0 == x1 && y0 == y1)
			break;
		short e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

t_byte	is_valid(t_const_vector_4 dot)
{
	if (!dot)
		return (0);
	if (dot[3] > 0)
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

	if (!fdf->redraw)
		return;
	dots = (float**)malloc(sizeof(t_vector_4) * fdf->point_count);
	i = fdf->point_count;
	while (--i != 0ul - 1ul)
	{
		dots[i] = matrix_on_vector(fdf->matrix_view, fdf->points[i]);
		dots[i][0] = (dots[i][0] / dots[i][3] + 1) * 0.5f * WIDTH;
		dots[i][1] = (1 - (dots[i][1] / dots[i][3] + 1) * 0.5f) * HEIGHT;
		if (!is_valid(dots[i]))
			continue;
		if (i + 1 < fdf->point_count && i % fdf->width < (i + 1) % fdf->width
			&& is_valid(dots[i + 1]))
			bresenham(fdf, dots[i], dots[i + 1]);
		if (i + fdf->width < fdf->point_count && is_valid(dots[i + fdf->width]))
			bresenham(fdf, dots[i], dots[i + fdf->width]);
		dot = fdf->size_line_int * (t_ushort)(dots[i][1])
			+ (t_ushort)(dots[i][0]);
		fdf->img_data[dot] = 0x00FFFF00;
	}
	loop_fill_image_cleanup(fdf, dots);
}

void	loop_fill_image_cleanup(t_fdf *fdf, float** data)
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
	mlx_do_sync(fdf->mlx);
	ft_bzero(fdf->img_data, fdf->size_line_char * HEIGHT);
	fdf->options |= FLAG_INVALIDATE_ROTATION;
	fdf->redraw = 0;
}
