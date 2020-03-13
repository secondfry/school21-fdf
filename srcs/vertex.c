/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:06:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 21:12:06 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (args < 1)
		return (ret);
	va_start(ap, z);
	w = va_arg(ap, double);
	ret->w = w;
	if (args < 2)
	{
		va_end(ap);
		return (ret);
	}
	color = va_arg(ap, t_color *);
	ft_memdel((void **)&(ret->color));
	ret->color = color;
	va_end(ap);
	return (ret);
}

void		vertex_print(t_vertex *self)
{
	ft_putstr("Vertex ");
	ft_putstr(ft_ltoa_hex_static((t_ulong)self));
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
	ft_putstr("}");
}
