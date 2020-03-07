/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:06:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:33:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "color.h"
#include "vertex.h"

t_vertex	*vertex_new(float *x, float *y, float *z, ...)
{
	t_vertex	*ret;
	va_list		ap;
	float		*w;
	t_color		*color;

	ret = (t_vertex *)malloc(sizeof(t_vertex));
	ret->x = *x;
	ret->y = *y;
	ret->z = *z;
	ret->w = 1;
	ret->color = color_new(255, 255, 255);
	va_start(ap, z);
	w = va_arg(ap, float *);
	if (!w)
		return (ret);
	ret->w = *w;
	color = va_arg(ap, t_color *);
	if (!color)
		return (ret);
	ft_memdel((void **)&(ret->color));
	ret->color = color;
	ret->new = vertex_new;
	va_end(ap);
	return (ret);
}
