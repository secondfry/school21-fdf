/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:06:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:11:12 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vertex.h"

t_vertex	*vertex_new(float x, float y, float z, float w, t_color *color)
{
	t_vertex	*ret;

	ret = (t_vertex *)malloc(sizeof(t_vertex));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->w = w;
	ret->color = color;
	return (ret);
}
