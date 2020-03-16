/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/16 04:07:56 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_loop.h"

#include <stdio.h>

int		loop_hook(t_fdf *fdf)
{
	loop_calculate_matrix_translation(fdf);
	loop_calculate_matrix_rotation(fdf);
	loop_calculate_matrix_projection(fdf);
	loop_calculate_matrix_view(fdf);
	loop_render(fdf);
	fdf->options |= FLAG_INVALIDATE_ROTATION;
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
	fdf->matrix_translation = matrix_new_translation(0, -10, -20);
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
	quaternion = quaternion_new(fdf->i++ * M_PI / 180, 0, 0);
	// quaternion = quaternion_new(0, 0, 0);
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
}

void	draw(t_fdf *fdf, unsigned short x, unsigned short y, int color)
{
	fdf->img_data[fdf->size_line_int * y + x] = color;
}

void	bresenham2(t_fdf *fdf, t_vector_4 a, t_vector_4 b)
{
	unsigned short x0 = (unsigned short)a[0];
	unsigned short y0 = (unsigned short)a[1];
	unsigned short x1 = (unsigned short)b[0];
	unsigned short y1 = (unsigned short)b[1];
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

void	loop_render(t_fdf *fdf)
{
	ft_bzero(fdf->img_data, fdf->size_line_char * HEIGHT);

	t_vector_4	result[fdf->point_count];
	for (size_t i = 0; i < fdf->point_count; i++)
	{
		// t_vector_4 tmp0 = matrix_on_vector(fdf->matrix_translation, fdf->points[i]);
		// t_vector_4 tmp1 = matrix_on_vector(fdf->matrix_rotation, tmp0);
		// t_vector_4 tmp2 = matrix_on_vector(fdf->matrix_projection, tmp1);
		result[i] = matrix_on_vector(fdf->matrix_view, fdf->points[i]);
// #ifdef LOG_DEBUG
		// t_vertex_4_print(tmp2);
		// t_vertex_4_print(result[i]);
		// ft_putchar('\n');
// #endif
		if (result[i][3] != 1)
		{
			result[i][0] /= result[i][3];
			result[i][1] /= result[i][3];
			result[i][2] /= result[i][3];
			t_vertex_4_print(result[i]);
		}
		// if (result[i][0] < -1 || result[i][0] > 1 || result[i][1] < -1 || result[i][1] > 1)
		// {
		// 	result[i][0] = -1;
		// 	result[i][1] = 1;
		// }
		result[i][0] = (result[i][0] + 1) * 0.5 * WIDTH;
		result[i][1] = (1 - (result[i][1] + 1) * 0.5) * HEIGHT;
		// t_vertex_4_print(result[i]);
		// ft_putchar('\n');
		// result[i][0] = result[i][0] + WIDTH / 2;
		// result[i][1] = result[i][1] * (-1) + HEIGHT / 2;
	}

	ft_putendl("zaebis\n");

	for (size_t i = 0; i < fdf->point_count; i++)
	{
		if (result[i][0] < 1 || result[i][0] > WIDTH) {
			ft_memdel((void**)&result[i]);
			continue;
		}
		if (result[i][1] < 1 || result[i][1] >= HEIGHT) {
			ft_memdel((void**)&result[i]);
			continue;
		}
		// if (result[i][2] < 0 || result[i][2] > 1) {
		// 	ft_memdel((void**)&result[i]);
		// 	continue;
		// }
		// for (t_byte j = i + 1; j < fdf->point_count; j++)
		// {
		// 	// if (
		// 	// 	result[j][0] < 1 || result[j][0] > WIDTH
		// 	// 	|| result[j][1] < 1 || result[j][1] >= HEIGHT
		// 	// ) {
		// 	// 	continue;
		// 	// }
		// 	if (result[i][0] > result[j][0])
		// 	{
		// 		bresenham2(fdf, result[j], result[i]);
		// 	}
		// 	else
		// 	{
		// 		bresenham2(fdf, result[i], result[j]);
		// 	}
		// }

#ifdef LOG_INFO
		printf("Result { x: %zu, y: %zu }\n", (unsigned short)(result[i][0]), (unsigned short)(result[i][1]));
#endif
		unsigned char blue = 1 * fdf->i;
		fdf->img_data[fdf->size_line_int * (unsigned short)(result[i][1]) + (unsigned short)(result[i][0])] = 0x00FFFF00 + blue;
		ft_memdel((void**)&result[i]);
	}

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
