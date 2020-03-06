/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:30 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:09:55 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

#include "color.h"

typedef struct	s_vertex {
	float	x;
	float	y;
	float	z;
	float	w;
	t_color	*color;
}				t_vertex;

t_vertex	*vertex_new(float x, float y, float z, float w, t_color *color);

#endif
