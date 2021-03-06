/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:46:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:46:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <math.h>
# include "libft.h"
# include "defines.h"
# include "matrix_factory.h"
# include "quaterion.h"

void	init_local_normalization(t_fdf *fdf);
void	init_local_scale(t_fdf *fdf);
void	init_local_rotation(t_fdf *fdf);
void	init_local_rotation_isometric(t_fdf *fdf);
void	init_world_translation(t_fdf *fdf);
void	init_world_rotation(t_fdf *fdf);
void	init_world_projection(t_fdf *fdf);

#endif
