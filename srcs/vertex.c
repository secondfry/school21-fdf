/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:06:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 20:47:53 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "color.h"
#include "vertex.h"

t_vertex	*vertex_new(size_t args, double x, double y, double z, ...)
{
	t_vertex	*ret;
	va_list		ap;
	double		w;
	t_color		*color;

	ret = (t_vertex *)malloc(sizeof(t_vertex));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->w = 1;
	ret->color = color_new(255, 255, 255);
	if (args < 4)
		return (ret);
	va_start(ap, z);
	w = va_arg(ap, double);
	ret->w = w;
	if (args < 5)
	{
		va_end(ap);
		return (ret);
	}
	color = va_arg(ap, t_color *);
	ft_putnbr((long) color);
	ft_memdel((void **)&(ret->color));
	ret->color = color;
	va_end(ap);
	return (ret);
}

void	vertex_print(t_vertex *self)
{
	ft_putstr("Vertex ");
	ft_putlong((long)self);
	ft_putstr(" { x: ");
	ft_putnbr(self->x);
	ft_putstr(", y: ");
	ft_putnbr(self->y);
	ft_putstr(", z: ");
	ft_putnbr(self->z);
	ft_putstr(", w: ");
	ft_putnbr(self->w);
	ft_putstr(", color: ");
	color_print(self->color);
	ft_putstr(" }\n");
}
