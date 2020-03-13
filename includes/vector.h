/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:52:38 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 21:59:40 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "defines.h"
# include "vertex.h"

t_vector	*vector_new(size_t args, t_vertex *dest, ...);
void		vector_print(t_vector *self);
double		vector_magnitude(t_vector *self);
t_vector	*vector_normalize(t_vector *self);
t_vector	*vector_add(t_vector *self, t_vector *other);
t_vector	*vector_sub(t_vector *self, t_vector *other);
t_vector	*vector_opposite(t_vector *self);
t_vector	*vector_scalar_product(t_vector *self, double factor);
double		vector_dot_product(t_vector *self, t_vector *other);
void		vector_free(t_vector *self);
void		vector_print(t_vector *self);

#endif
