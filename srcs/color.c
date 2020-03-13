/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:44:50 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 22:06:59 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*color_new(t_byte red, t_byte green, t_byte blue)
{
	t_color	*ret;

	ret = (t_color *)malloc(sizeof(t_color));
	ret->red = red;
	ret->green = green;
	ret->blue = blue;
	return (ret);
}

t_color	*color_add(t_color *self, t_color *other)
{
	return (color_new(
		self->red + other->red,
		self->green + other->green,
		self->blue + other->blue
	));
}

t_color	*color_sub(t_color *self, t_color *other)
{
	return (color_new(
		self->red - other->red,
		self->green - other->green,
		self->blue - other->blue
	));
}

t_color	*color_mult(t_color *self, float factor)
{
	return (color_new(
		self->red * factor,
		self->green * factor,
		self->blue * factor
	));
}

t_color	*color_copy(t_color *self)
{
	return (color_new(self->red, self->green, self->blue));
}

void	color_free(t_color *self)
{
	ft_memdel((void**)&self);
}

void	color_print(t_color *self)
{
	ft_putstr("Color ");
	ft_putstr(ft_ltoa_hex_static((t_ulong)self));
	ft_putstr(" { red: ");
	ft_putnbr(self->red);
	ft_putstr(", green: ");
	ft_putnbr(self->green);
	ft_putstr(", blue: ");
	ft_putnbr(self->blue);
	ft_putstr(" }");
}
