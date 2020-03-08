/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:31:41 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 800
# define HEIGHT 600
# define TITLE "FDF"

# include "libft.h"

typedef struct	s_color {
	t_byte			red;
	t_byte			green;
	t_byte			blue;
}				t_color;

typedef struct	s_vertex {
	double			x;
	double			y;
	double			z;
	double			w;
	t_color			*color;
}				t_vertex;

#endif
