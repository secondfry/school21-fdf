/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:54:11 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:31:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "defines.h"
# include "libft.h"

t_color	*color_new(t_byte red, t_byte green, t_byte blue);
t_color	*color_add(t_color *self, t_color *other);
t_color	*color_sub(t_color *self, t_color *other);
t_color	*color_mult(t_color *self, float factor);

#endif
