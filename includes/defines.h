/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:46:11 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdlib.h>
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "FDF"
# define M_PI_F 3.14159265358979323846264338327950288f
# define M_PI_2F 1.57079632679489661923132169163975144f
# define M_PI_4F 0.785398163397448309615660845819875721f
# define M_SQRT2_F 1.41421356237309504880168872420969808f
# define M_SQRT1_2_F 0.707106781186547524400844362104849039f

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
	t_ushort	flags;
	t_byte		options;
	t_vector_4	camera_position;
	t_vector_4	camera_rotation;
	t_matrix_4	matrix_local_normalization;
	t_matrix_4	matrix_local_scale;
	t_matrix_4	matrix_local_rotation;
	t_matrix_4	matrix_local_translation;
	t_matrix_4	matrix_world_translation;
	t_matrix_4	matrix_world_rotation;
	t_matrix_4	matrix_world_projection;
	t_vector_4	matrix_world_projection_properties;
	t_matrix_4	matrix_view;
	float		**points;
	t_byte		*heights;
	size_t		point_count;
	t_ushort	frame[3];
	size_t		cols;
	size_t		rows;
	size_t		height;
}					t_fdf;

# define FLAG_INVALIDATE_LOCAL_NORMALIZATION	1u << 0u
# define FLAG_INVALIDATE_LOCAL_SCALE			1u << 1u
# define FLAG_INVALIDATE_LOCAL_ROTATION			1u << 3u
# define FLAG_INVALIDATE_LOCAL_TRANSLATION		1u << 2u
# define FLAG_INVALIDATE_WORLD_TRANSLATION		1u << 4u
# define FLAG_INVALIDATE_WORLD_ROTATION			1u << 5u
# define FLAG_INVALIDATE_WORLD_PROJECTION		1u << 6u
# define FLAG_INVALIDATE_VIEW					1u << 7u
# define FLAG_REDRAW							1u << 8u

# define OPTION_ENABLE_PERSPECTIVE				1u << 0u
# define OPTION_ENABLE_ROTATION					1u << 1u
# define OPTION_ISOMETRIC						1u << 2u
# define OPTION_ROTATION_X						1u << 3u
# define OPTION_ROTATION_Y						1u << 4u
# define OPTION_ROTATION_Z						1u << 5u

# define EVENT_KEY_PRESS						2
# define EVENT_KEY_RELEASE						3
# define EVENT_BUTTON_PRESS						4
# define EVENT_BUTTON_RELEASE					5
# define EVENT_MOTION_NOTIFY					6
# define EVENT_EXPOSE							12
# define EVENT_DESTROY							17

/*
** https://refspecs.linuxfoundation.org/LSB_1.3.0/gLSB/gLSB/libx11-ddefs.html
*/
# define MASK_KEY_PRESS							1ul << 0u
# define MASK_KEY_RELEASE						1ul << 1u
# define MASK_BUTTON_PRESS						1ul << 2u
# define MASK_BUTTON_RELEASE					1ul << 3u
# define MASK_EXPOSE							1ul << 15u
# define MASK_DESTROY							1ul << 17u

# define KEY_A									0
# define KEY_S									1
# define KEY_D									2
# define KEY_F									3
# define KEY_Q									12
# define KEY_W									13
# define KEY_E									14
# define KEY_R									15
# define KEY_T									17
# define KEY_Z									6
# define KEY_X									7
# define KEY_C									8
# define KEY_ESC								53

#endif
