/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 13:53:10 by oadhesiv         ###   ########.fr       */
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
	// t_color *f = color_new(100, 200, 0);
	// t_color *g = color_new(50, 150, 0);
	// t_color *e = a->sub(a, f);
	// t_color *h = e->add(e, g);
	// t_color *i = h->mult(h, 0.1);

	// float b0 = 0;
	// float c0 = 1;
	// t_vertex *b = vertex_new(&b0, &b0, &b0);
	// t_vertex *c = vertex_new(&b0, &b0, &b0, &c0);
	// t_vertex *d = vertex_new(&b0, &b0, &b0, &c0, a);

	mlx_loop(mlx);

	// for (int i = 0; i < 1000000; i++) {}

	return (ft_atoi(argv[argc - 1]));
}
