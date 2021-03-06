/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 05:22:02 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:46:11 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "defines.h"

typedef struct	s_bresenham
{
	t_ushort	x0;
	t_ushort	y0;
	t_byte		h0;
	t_ushort	x1;
	t_ushort	y1;
	t_byte		h1;
	short		dx;
	short		dy;
	short		dh;
	char		sx;
	char		sy;
	short		err;
}				t_bresenham;

void			draw(t_fdf *fdf, t_ushort x, t_ushort y, int color);
void			bresenham_init(
	t_bresenham *bh,
	t_fdf *fdf,
	float **dots,
	const size_t *i);
void			bresenham(t_fdf *fdf, float **dots, size_t a, size_t b);

#endif
