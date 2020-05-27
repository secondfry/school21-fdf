/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaterion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 01:08:07 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 17:06:50 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERION_H
# define QUATERION_H

# include <math.h>
# include "libft.h"
# include "defines.h"

t_quaterion	quaternion_new(float angle_x, float angle_y, float angle_z);
t_matrix_4	quaternion_to_matrix(t_const_quaterion self);

#endif
