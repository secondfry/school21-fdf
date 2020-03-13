/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:52:38 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 21:02:35 by oadhesiv         ###   ########.fr       */
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

#endif
