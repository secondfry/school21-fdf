/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:49:29 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/14 19:53:35 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "defines.h"

# ifdef _STDIO_H_
void	point_print(t_point *self);
# endif

t_point	*point_new(size_t x, size_t y, size_t height);
short	point_calc_helper(float a, float b, float c);
void	point_calc(t_point *point, float x, float y, float z);
void	rotate_x(t_point *point, float angle);
void	rotate_y(t_point *point, float angle);
void	rotate_z(t_point *point, float angle);

#endif
