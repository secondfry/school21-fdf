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
	struct s_color	*(*new)(t_byte, t_byte, t_byte);
	struct s_color	*(*add)(struct s_color *, struct s_color *);
	struct s_color	*(*sub)(struct s_color *, struct s_color *);
	struct s_color	*(*mult)(struct s_color *, float);
}				t_color;

typedef struct	s_vertex {
	float			x;
	float			y;
	float			z;
	float			w;
	t_color			*color;
	struct s_vertex	*(*new)(float *, float *, float *, ...);
}				t_vertex;

#endif
