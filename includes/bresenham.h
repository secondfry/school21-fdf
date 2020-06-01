/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 05:22:02 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 06:04:40 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "defines.h"

typedef struct	s_bresenham
{
	t_ushort	x0;
	t_ushort	y0;
	t_ushort	x1;
	t_ushort	y1;
	short		dx;
	short		dy;
	char		sx;
	char		sy;
	short		err;
}				t_bresenham;

void			draw(t_fdf *fdf, t_ushort x, t_ushort y, int color);
void			bresenham_init(t_bresenham *bh, t_const_vector_4 a,
					t_const_vector_4 b);
void			bresenham(t_fdf *fdf, t_vector_4 a, t_vector_4 b);

#endif
