/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:11:58 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 21:12:18 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_new(size_t args, t_vertex *dest, ...)
{
	t_vector	*ret;
	va_list		ap;
	t_vertex	*orig;


	ret = (t_vector *)malloc(sizeof(t_vector));
	ret->dest = dest;
	ret->orig = vertex_new(1, 0, 0, 0, 1);
	if (args < 1)
		return (ret);
	va_start(ap, dest);
	orig = va_arg(ap, t_vertex *);
	ft_memdel((void**)&ret->orig);
	ret->orig = orig;
	va_end(ap);
	return (ret);
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
