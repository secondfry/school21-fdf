/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:30 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:08:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_LOOP_H
# define HOOKS_LOOP_H

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "defines.h"
# include "init.h"
# include "matrix_factory.h"
# include "matrix_utils.h"
# include "bresenham.h"

int		loop_key_hook(int keycode, t_fdf *fdf);
int		loop_destroy_hook();
int		loop_hook(t_fdf *fdf);
void	loop_calculate_matrix_local_normalization(t_fdf *fdf);
void	loop_calculate_matrix_local_scale(t_fdf *fdf);
void	loop_calculate_matrix_local_rotation(t_fdf *fdf);
void	loop_calculate_matrix_world_translation(t_fdf *fdf);
void	loop_calculate_matrix_world_rotation(t_fdf *fdf);
void	loop_calculate_matrix_world_projection(t_fdf *fdf);
void	loop_calculate_matrix_view(t_fdf *fdf);
void	loop_fill_image(t_fdf *fdf);
void	bresenham_check(t_fdf *fdf, float **dots, size_t counter);
void	loop_fill_image_cleanup(t_fdf *fdf, float **data);
void	loop_render(t_fdf *fdf);

#endif
