/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/15 00:47:07 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "defines.h"
#include "color.h"
#include "vertex.h"
#include "vector.h"

#include <unistd.h>

int		main(int argc, char** argv) {
	void	*mlx;
	void	*win;

	// mlx = mlx_init();
	// if (!mlx)
	// {
	// 	ft_putstr("[main] mlx_init errored.");
	// 	return (1);
	// }

	// win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	// if (!win)
	// {
	// 	ft_putstr("[main] mlx_new_window errored.");
	// 	ft_memdel((void**)&mlx);
	// 	return (1);
	// }

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
	t_vertex *z = vertex_new(1, 0, 0, 0, 0.0);
	t_vertex *w = vertex_new(1, 1, 1, 1, 0.0);

	vertex_print(b); ft_putchar('\n');
	vertex_print(c); ft_putchar('\n');
	vertex_print(d); ft_putchar('\n');

	t_vector *vz = vector_new(0, b);
	t_vector *va = vector_new(1, w, z);
	t_vector *vb = vector_new(1, c, d);

	vector_print(vz); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vz));

	vector_print(va); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(va));

	vector_print(vb); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vb));

	t_vector *vc = vector_normalize(va);
	t_vector *vd = vector_normalize(vb);

	vector_print(vc); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vc));

	vector_print(vd); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vd));

	t_vector *ve = vector_add(va, vb);

	vector_print(ve); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(ve));

	t_vector *vf = vector_sub(va, vb);

	vector_print(vf); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vf));

	t_vector *vg = vector_opposite(va);

	vector_print(vg); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vg));

	t_vector *vh = vector_scalar_product(va, -14.0);

	vector_print(vh); ft_putchar('\n');
	printf("Magnitude: %f\n", vector_magnitude(vh));

	double dp = vector_dot_product(va, vb);
	printf("dot product: %f\n", dp);

	double cs = vector_cos(va, vb);
	printf("cosine: %f\n", cs);

	printf("\n========== Actually doing graphics ==========\n");
	t_color *red = color_new(255, 0, 0);
	t_color *green = color_new(0, 255, 0);
	t_color *blue = color_new(0, 0, 255);
	t_vertex *A = vertex_new(2, 1, 0, 0, 1.0, red);
	t_vertex *B = vertex_new(2, 0, 1, 0, 1.0, green);
	t_vertex *C = vertex_new(2, 0, 0, 1, 1.0, blue);
	t_vector *AB = vector_new(1, B, A);
	t_vector *BC = vector_new(1, C, B);
	t_vector *CA = vector_new(1, A, C);
	ft_putstr("AB: "); vector_print(AB); ft_putchar('\n');
	ft_putstr("BC: "); vector_print(BC); ft_putchar('\n');
	ft_putstr("CA: "); vector_print(CA); ft_putchar('\n');

	// mlx_loop(mlx);

	sleep(1000000000);

	color_free(a);
	color_free(f);
	color_free(g);
	color_free(e);
	color_free(h);
	color_free(i);
	vertex_free(b);
	vertex_free(c);
	vertex_free(d);
	vertex_free(w);
	vertex_free(z);
	vector_free(vz);
	vector_free(va);
	vector_free(vb);
	vector_free(vc);
	vector_free(vd);
	vector_free(ve);
	vector_free(vf);
	vector_free(vg);
	vector_free(vh);

	color_free(red);
	color_free(green);
	color_free(blue);
	vertex_free(A);
	vertex_free(B);
	vertex_free(C);
	vector_free(AB);
	vector_free(BC);
	vector_free(CA);

	return (ft_atoi(argv[argc - 1]));
}
