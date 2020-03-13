/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:44:50 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 20:41:57 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
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

void	color_print(t_color *self)
{
	ft_putstr("Color ");
	ft_putlong((long)self);
	ft_putstr(" { red: ");
	ft_putnbr(self->red);
	ft_putstr(", green: ");
	ft_putnbr(self->green);
	ft_putstr(", blue: ");
	ft_putnbr(self->blue);
	ft_putstr(" }\n");
}
