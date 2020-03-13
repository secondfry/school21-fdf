/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 20:39:40 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "defines.h"
#include "color.h"
#include "vertex.h"

int		main(int argc, char** argv) {
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr("[main] mlx_init errored.");
		return (1);
	}

	win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		ft_putstr("[main] mlx_new_window errored.");
		ft_memdel((void**)&mlx);
		return (1);
	}

	t_color *a = color_new(255, 255, 255);
	t_color *f = color_new(100, 200, 0);
	t_color *g = color_new(50, 150, 0);
	t_color *e = color_sub(a, f);
	t_color *h = color_add(e, g);
	t_color *i = color_mult(h, 0.1);

	color_print(a);
	color_print(f);
	color_print(g);
	color_print(e);
	color_print(h);
	color_print(i);

	t_vertex *b = vertex_new(3, 0, 0, 0);
	t_vertex *c = vertex_new(4, 0, 0, 0, 1);
	t_vertex *d = vertex_new(5, 0, 0, 0, 1, i);

	mlx_loop(mlx);

	// for (int i = 0; i < 1000000; i++) {}

	return (ft_atoi(argv[argc - 1]));
}
