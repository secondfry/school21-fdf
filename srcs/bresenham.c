/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 05:27:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:44:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

void	draw(t_fdf *fdf, t_ushort x, t_ushort y, int color)
{
	size_t dot;

	dot = fdf->size_line_int * y + x;
	if (fdf->img_data[dot])
		return ;
	fdf->img_data[dot] = color;
}

void	bresenham_init(t_bresenham *bh, t_const_vector_4 a, t_const_vector_4 b)
{
	bh->x0 = (t_ushort)a[0];
	bh->y0 = (t_ushort)a[1];
	bh->x1 = (t_ushort)b[0];
	bh->y1 = (t_ushort)b[1];
	bh->dx = bh->x0 < bh->x1 ? bh->x1 - bh->x0 : bh->x0 - bh->x1;
	bh->sx = bh->x0 < bh->x1 ? 1 : -1;
	bh->dy = bh->y0 < bh->y1 ? bh->y0 - bh->y1 : bh->y1 - bh->y0;
	bh->sy = bh->y0 < bh->y1 ? 1 : -1;
	bh->err = bh->dx + bh->dy;
}

void	bresenham(t_fdf *fdf, t_vector_4 a, t_vector_4 b)
{
	t_bresenham	bh;
	short		e2;

	if (!a || !b)
		return ;
	bresenham_init(&bh, a, b);
	while (1)
	{
		draw(fdf, bh.x0, bh.y0, 0x00FF0000);
		if (bh.x0 == bh.x1 && bh.y0 == bh.y1)
			break ;
		e2 = 2 * bh.err;
		if (e2 >= bh.dy)
		{
			bh.err += bh.dy;
			bh.x0 += bh.sx;
		}
		if (e2 <= bh.dx)
		{
			bh.err += bh.dx;
			bh.y0 += bh.sy;
		}
	}
}
