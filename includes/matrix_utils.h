/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 01:09:34 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 17:18:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_UTILS_H
# define MATRIX_UTILS_H

# include "libft.h"
# include "defines.h"

t_vector_4	matrix_on_vector(t_const_matrix_4 m, t_const_vector_4 v);
t_matrix_4	matrix_on_matrix(t_const_matrix_4 a, t_const_matrix_4 b);

#endif
