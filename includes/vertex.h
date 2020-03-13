/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:30 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 22:10:46 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "defines.h"
# include "color.h"

t_vertex	*vertex_new(size_t args, double x, double y, double z, ...);
t_vertex	*vertex_copy(t_vertex *self);
void		vertex_free(t_vertex *self);
void		vertex_print(t_vertex *self);

#endif
