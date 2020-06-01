/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:08:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdlib.h>
# include "libft.h"

# define WIDTH 640
# define HEIGHT 480
# define TITLE "FDF"
# define M_PI_F 3.14159265358979323846264338327950288f
# define M_PI_2F 1.57079632679489661923132169163975144f

# define EINVAL 22

typedef float		*t_matrix_4;
typedef float		*t_vector_4;
typedef float		*t_quaterion;
typedef const float	*t_const_matrix_4;
typedef const float	*t_const_vector_4;
typedef const float	*t_const_quaterion;
typedef int			(*t_mlx_hook)();

typedef struct		s_fdf
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
	size_t		i;
	size_t		width;
	size_t		height;
	size_t		redraw;
}					t_fdf;

# define FLAG_INVALIDATE_TRANSLATION	1u << 0u
# define FLAG_INVALIDATE_ROTATION		1u << 1u
# define FLAG_INVALIDATE_PROJECTION		1u << 2u
# define FLAG_INVALIDATE_VIEW			1u << 3u

#endif
