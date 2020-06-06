/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:41:19 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 22:02:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_world_rotation(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_world_rotation);
	fdf->camera_rotation[0] = fmodf(fdf->camera_rotation[0], 360.f);
	fdf->camera_rotation[1] = fmodf(fdf->camera_rotation[1], 360.f);
	fdf->camera_rotation[2] = fmodf(fdf->camera_rotation[2], 360.f);
	fdf->matrix_world_rotation = matrix_new_rotation(
		fdf->camera_rotation[0],
		fdf->camera_rotation[1],
		fdf->camera_rotation[2]);
}
