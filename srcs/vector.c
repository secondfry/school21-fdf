/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:11:58 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 22:10:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "vector.h"

t_vector	*vector_new(size_t args, t_vertex *dest, ...)
{
	t_vector	*ret;
	va_list		ap;
	t_vertex	*orig;


	ret = (t_vector *)malloc(sizeof(t_vector));

	ret->dest = vertex_copy(dest);
	ret->orig = vertex_new(1, 0, 0, 0, 1);
	if (args < 1)
		return (ret);
	va_start(ap, dest);
	orig = va_arg(ap, t_vertex *);
	vertex_free(ret->orig);
	ret->orig = vertex_copy(orig);
	va_end(ap);
	return (ret);
}

double		vector_magnitude(t_vector *self)
{
	double lenx;
	double leny;
	double lenz;
	double lenw;

	lenx = self->dest->x - self->orig->x;
	leny = self->dest->y - self->orig->y;
	lenz = self->dest->z - self->orig->z;
	lenw = self->dest->w - self->orig->w;
	return sqrt(lenx * lenx + leny * leny + lenz * lenz + lenw * lenw);
}

t_vector	*vector_base(t_vector *self)
{
	double newx;
	double newy;
	double newz;
	double neww;

	newx = self->dest->x - self->orig->x;
	newy = self->dest->y - self->orig->y;
	newz = self->dest->z - self->orig->z;
	neww = self->dest->w - self->orig->w;
	return vector_new(
		1,
		vertex_new(2, newx, newy, newz, neww, self->dest->color),
		vertex_new(2, 0.0, 0.0, 0.0, 1.0, self->orig->color)
	);
}

t_vector	*vector_normalize(t_vector *self)
{
	double		size;
	t_vector	*base;
	t_vector	*ret;

	base = vector_base(self);
	size = vector_magnitude(self);
	ret = vector_new(
		1,
		vertex_new(
			2,
			base->dest->x / size,
			base->dest->y / size,
			base->dest->z / size,
			base->dest->w / size,
			self->dest->color
		),
		vertex_new(2, 0.0, 0.0, 0.0, 1.0, self->orig->color)
	);
	vector_free(base);
	return (ret);
}

t_vector	*vector_add(t_vector *self, t_vector *other)
{
	t_vector	*norm;
	t_vector	*ret;

	norm = vector_normalize(other);
	ret = vector_new(
		1,
		vertex_new(
			2,
			self->dest->x + norm->dest->x,
			self->dest->y + norm->dest->y,
			self->dest->z + norm->dest->z,
			self->dest->w + norm->dest->w,
			self->dest->color
		),
		vertex_new(2, 0.0, 0.0, 0.0, 1.0, self->orig->color)
	);
	vector_free(norm);
	return (ret);
}

t_vector	*vector_sub(t_vector *self, t_vector *other)
{
	t_vector	*opposite;
	t_vector	*ret;

	opposite = vector_opposite(other);
	ret = vector_add(self, opposite);
	vector_free(opposite);
	return (ret);
}

t_vector	*vector_opposite(t_vector *self)
{
	return vector_scalar_product(self, -1);
}

t_vector	*vector_scalar_product(t_vector *self, double factor)
{
	return vector_new(
		1,
		vertex_new(
			2,
			self->dest->x * factor,
			self->dest->y * factor,
			self->dest->z * factor,
			self->dest->w * factor,
			self->dest->color
		),
		vertex_new(
			2,
			self->orig->x * factor,
			self->orig->y * factor,
			self->orig->z * factor,
			self->orig->w * factor,
			self->orig->color
		)
	);
}

double		vector_dot_product(t_vector *self, t_vector *other)
{
	t_vector	*va;
	t_vector	*vb;
	double		ret;

	va = vector_normalize(self);
	vb = vector_normalize(other);
	ret =
		va->dest->x * vb->dest->x +
		va->dest->y * vb->dest->y +
		va->dest->z * vb->dest->z +
		va->dest->w * vb->dest->w;
	vector_free(va);
	vector_free(vb);
	return (ret);
}

void		vector_free(t_vector *self)
{
	vertex_free(self->dest);
	vertex_free(self->orig);
	ft_memdel((void**)&self);
}

void		vector_print(t_vector *self)
{
	ft_putstr("Vector ");
	ft_putstr(ft_ltoa_hex_static((t_ulong)self));
	ft_putstr(" {\n dest: ");
	vertex_print(self->dest);
	ft_putstr(",\n orig: ");
	vertex_print(self->orig);
	ft_putstr("\n}");
}
