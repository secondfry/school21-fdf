/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:44:50 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:05:16 by oadhesiv         ###   ########.fr       */
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
	ret->new = color_new;
	ret->add = color_add;
	ret->sub = color_sub;
	ret->mult = color_mult;
	return (ret);
}

t_color	*color_add(t_color *self, t_color *other)
{
	return (self->new(
		self->red + other->red,
		self->green + other->green,
		self->blue + other->blue
	));
}

t_color	*color_sub(t_color *self, t_color *other)
{
	return (self->new(
		self->red - other->red,
		self->green - other->green,
		self->blue - other->blue
	));
}

t_color	*color_mult(t_color *self, float factor)
{
	return (self->new(
		self->red * factor,
		self->green * factor,
		self->blue * factor
	));
}
