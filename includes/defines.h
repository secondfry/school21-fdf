/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/16 03:51:32 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "FDF"

# include <stdlib.h>
# include "libft.h"

typedef float	*t_matrix_4;
typedef float	*t_vector_4;
typedef float	*t_quaterion;
typedef int		(*t_mlx_hook)();

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_data;
	size_t		size_line_int;
	size_t		size_line_char;
	t_byte		options;
	t_vector_4	camera_position;
	t_vector_4	camera_rotation;
	t_matrix_4	matrix_translation;
	t_matrix_4	matrix_rotation;
	t_vector_4	matrix_projection_properties;
	t_matrix_4	matrix_projection;
	t_matrix_4	matrix_view;
	float		**points;
	size_t		point_count;
	short		i;
}				t_fdf;

# define FLAG_INVALIDATE_TRANSLATION	1 << 0
# define FLAG_INVALIDATE_ROTATION		1 << 1
# define FLAG_INVALIDATE_PROJECTION		1 << 2
# define FLAG_INVALIDATE_VIEW			1 << 3

#endif
