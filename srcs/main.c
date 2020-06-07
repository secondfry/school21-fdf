/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 06:03:56 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	ft_ptr_check(fdf->mlx, "[main] mlx_init errored.", 0);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, TITLE);
	ft_ptr_check(fdf->win, "[main] mlx_new_window errored.", 1, fdf->mlx);
}

void		init_mlx_image(t_fdf *fdf)
{
	int bits_per_pixel;
	int size_line;
	int endianess;

	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
	{
		ft_putstr("[main] mlx_new_image errored.");
		mlx_destroy_window(fdf->mlx, fdf->win);
		ft_memdel(&(fdf->mlx));
		exit(ENOMEM);
	}
	fdf->img_data = (int *)mlx_get_data_addr(
		fdf->img, &bits_per_pixel, &size_line, &endianess);
	fdf->size_line_char = (size_t)size_line;
	fdf->size_line_int = (size_t)(size_line / 4);
}

void		init_pipeline(t_fdf *fdf)
{
	fdf->flags = FLAG_INVALIDATE_LOCAL_NORMALIZATION
		| FLAG_INVALIDATE_LOCAL_SCALE | FLAG_INVALIDATE_LOCAL_ROTATION
		| FLAG_INVALIDATE_LOCAL_TRANSLATION | FLAG_INVALIDATE_WORLD_TRANSLATION
		| FLAG_INVALIDATE_WORLD_PROJECTION | FLAG_REDRAW;
	fdf->options = OPTION_ENABLE_PERSPECTIVE | OPTION_ROTATION_X;
	fdf->camera_position = vector_new(0, 0, 1000.f, 1);
	fdf->camera_rotation = vector_new(0, 0, 0, 1);
	fdf->matrix_local_normalization = matrix_new_identity();
	fdf->matrix_local_scale = matrix_new_identity();
	fdf->matrix_local_rotation = matrix_new_identity();
	fdf->matrix_local_translation = matrix_new_identity();
	fdf->matrix_world_translation = matrix_new_identity();
	fdf->matrix_world_rotation = matrix_new_identity();
	fdf->matrix_world_projection = matrix_new_identity();
	fdf->matrix_world_projection_properties = vector_new(
		90.0f, WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	fdf->matrix_view = matrix_new_identity();
	fdf->point_count = 0;
	ft_bzero(&(fdf->frame), sizeof(size_t) * 3);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_putendl_fd("Provide one valid map file argument, please.", 2);
		return (EINVAL);
	}
	init_pipeline(&fdf);
	input(&fdf, argv[argc - 1]);
	init_mlx(&fdf);
	init_mlx_image(&fdf);
	mlx_hook(fdf.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, loop_key_hook, &fdf);
	mlx_hook(fdf.win, EVENT_DESTROY, MASK_DESTROY, loop_destroy_hook, &fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (ft_atoi(argv[argc - 1]));
}
