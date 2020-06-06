/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:49:29 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 05:11:52 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include "defines.h"
# include "matrix_factory.h"
# include "vector.h"
# include "input.h"
# include "hooks_loop.h"

void		init_mlx(t_fdf *fdf);
void		init_mlx_image(t_fdf *fdf);
void		init_pipeline(t_fdf *fdf);

#endif
