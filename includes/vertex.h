/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:30 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 20:45:49 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include <stdlib.h>
# include "defines.h"

t_vertex	*vertex_new(size_t args, double x, double y, double z, ...);
void		vertex_print(t_vertex *self);

#endif
