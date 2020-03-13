/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 21:10:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "defines.h"
#include "color.h"
#include "vertex.h"
#include "vector.h"

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

	color_print(a); ft_putchar('\n');
	color_print(f); ft_putchar('\n');
	color_print(g); ft_putchar('\n');
	color_print(e); ft_putchar('\n');
	color_print(h); ft_putchar('\n');
	color_print(i); ft_putchar('\n');

	t_vertex *b = vertex_new(0, 1, 2, 3);
	t_vertex *c = vertex_new(1, 4, 5, 6, 7.0);
	t_vertex *d = vertex_new(2, 8, 9, 10, 11.0, i);

	vertex_print(b); ft_putchar('\n');
	vertex_print(c); ft_putchar('\n');
	vertex_print(d); ft_putchar('\n');

	t_vector *va = vector_new(0, b);
	t_vector *vb = vector_new(1, c, d);

	vector_print(va); ft_putchar('\n');
	vector_print(vb); ft_putchar('\n');

	mlx_loop(mlx);

	// for (int i = 0; i < 1000000; i++) {}

	return (ft_atoi(argv[argc - 1]));
}
