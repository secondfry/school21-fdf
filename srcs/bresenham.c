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

void	draw(t_fdf *fdf, t_bresenham *bh, int color)
{
	size_t	dot;
	float	z[2];

	dot = fdf->size_line_int * bh->y0 + bh->x0;
	if (bh->dx)
		z[0] = bh->z1 - bh->dz * (bh->x0 - bh->x1) / bh->dx * bh->sx;
	if (bh->dy)
		z[1] = bh->z1 - bh->dz * (bh->y1 - bh->y0) / bh->dy * bh->sy;
	bh->z0 = abs(bh->dx) > abs(bh->dy) ? z[0] : z[1];
	fdf->img_data[dot] = bh->z0 < fdf->z_buffer[dot] ? color : fdf->img_data[dot];
	fdf->z_buffer[dot] = bh->z0 < fdf->z_buffer[dot] ? bh->z0 : fdf->z_buffer[dot];
}

void	bresenham_init(t_bresenham *bh, t_fdf *fdf, float **dots, const size_t i[2])
{
	bh->x0 = (t_ushort)dots[i[0]][0];
	bh->y0 = (t_ushort)dots[i[0]][1];
	bh->x1 = (t_ushort)dots[i[1]][0];
	bh->y1 = (t_ushort)dots[i[1]][1];
	bh->dx = bh->x0 < bh->x1 ? bh->x1 - bh->x0 : bh->x0 - bh->x1;
	bh->sx = bh->x0 < bh->x1 ? 1 : -1;
	bh->dy = bh->y0 < bh->y1 ? bh->y0 - bh->y1 : bh->y1 - bh->y0;
	bh->sy = bh->y0 < bh->y1 ? 1 : -1;
	bh->err = bh->dx + bh->dy;
	bh->h0 = fdf->heights[i[0]];
	bh->h1 = fdf->heights[i[1]];
	bh->dh = bh->h0 - bh->h1;
	bh->z0 = dots[i[0]][2];
	bh->z1 = dots[i[1]][2];
	bh->dz = bh->z0 - bh->z1;
}

int		get_color(t_bresenham *bh)
{
	char	h[2];

	if (!bh->dh)
		return 0x777777 + 0x10101 * bh->h1;
	if (bh->dx)
		h[0] = bh->h1 - bh->dh * (bh->x0 - bh->x1) / bh->dx * bh->sx;
	if (bh->dy)
		h[1] = bh->h1 - bh->dh * (bh->y1 - bh->y0) / bh->dy * bh->sy;
	bh->h0 = abs(bh->dx) > abs(bh->dy) ? h[0] : h[1];
	return (0x777777 + 0x10101 * bh->h0);
}

void	bresenham(t_fdf *fdf, float **dots, size_t a, size_t b)
{
	t_bresenham	bh;
	short		e2;

	if (!dots[a] || !dots[b])
		return ;
	bresenham_init(&bh, fdf, dots, (size_t[2]){a, b});
	while (1)
	{
		draw(fdf, &bh, get_color(&bh));
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
