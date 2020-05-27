/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:30 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 22:02:39 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "defines.h"
# include "matrix_factory.h"
# include "matrix_utils.h"
# include "quaterion.h"
# include "vertex.h"

# define LOG_DEBUG

int		loop_hook(t_fdf *fdf);
void	loop_calculate_matrix_translation(t_fdf *fdf);
void	loop_calculate_matrix_rotation(t_fdf *fdf);
void	loop_calculate_matrix_projection(t_fdf *fdf);
void	loop_calculate_matrix_view(t_fdf *fdf);
void	loop_render(t_fdf *fdf);

#endif
