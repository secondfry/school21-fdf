/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/16 03:53:17 by oadhesiv         ###   ########.fr       */
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
	fdf->matrix_translation = matrix_new_identity();
	fdf->matrix_rotation = matrix_new_identity();
	fdf->matrix_projection = matrix_new_identity();
	fdf->matrix_view = matrix_new_identity();
	fdf->options = FLAG_INVALIDATE_TRANSLATION | FLAG_INVALIDATE_ROTATION
				  | FLAG_INVALIDATE_PROJECTION;
	fdf->matrix_projection_properties = vector_new(
		90.0f, WIDTH / (float) HEIGHT, 0.1f, 100.0f);
}

void		input(char *filename)
{

}

int			main(int argc, char** argv)
{
	t_fdf	fdf;

	if (argc < 2) {
		return (EINVAL);
	}
	input(argv[argc]);
	init_mlx(&fdf);
	init_mlx_image(&fdf);
	init_pipeline(&fdf);
	init_teapot(&fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (ft_atoi(argv[argc - 1]));
}
