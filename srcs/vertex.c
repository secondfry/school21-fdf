/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:30:08 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 21:31:44 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"

#include <stdio.h>

void		t_vertex_4_print(t_vector_4 self)
{
	printf("Point { x: %5.3f, y: %5.3f, z: %5.3f, w: %5.3f }\n", self[0], self[1], self[2], self[3]);
}
