/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:54:11 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 22:08:41 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdlib.h>
# include "libft.h"
# include "defines.h"

t_color	*color_new(t_byte red, t_byte green, t_byte blue);
t_color	*color_add(t_color *self, t_color *other);
t_color	*color_sub(t_color *self, t_color *other);
t_color	*color_mult(t_color *self, float factor);
t_color	*color_copy(t_color *self);
void	color_free(t_color *self);
void	color_print(t_color *self);

#endif
