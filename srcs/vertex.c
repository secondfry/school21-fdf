/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:30:08 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/05/31 13:58:03 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"

#include <stdio.h>

void		t_vertex_4_print(t_vector_4 self)
{
	printf("Point { x: %5.3f, y: %5.3f, z: %5.3f, w: %5.3f }\n", self[0], self[1], self[2], self[3]);
}
