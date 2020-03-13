/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 23:52:45 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "defines.h"

typedef struct	s_point
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	height;
	size_t	cur_x;
	size_t	cur_y;
}				t_point;

t_point	*point_new(size_t x, size_t y, size_t height)
{
	t_point	*ret;

	ret = (t_point *)malloc(sizeof(t_point));
	if (!ret)
		return (ret);
	ret->x = x;
	ret->y = y;
	ret->z = height;
	ret->screen_x = 0;
	ret->screen_y = 0;
	return (ret);
}

size_t	point_calc_helper(size_t a, size_t b, size_t c)
{
	return ((a - b) * c + b);
}

void	point_calc(t_point *point, size_t x, size_t y, size_t z)
{
	size_t	factor;

	factor = (point->z - z) / point->z;
	point->screen_x = point_calc_helper(point->x, x, factor);
	point->screen_y = point_calc_helper(point->y, y, factor);
}

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

	void *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putstr("[main] mlx_new_image errored.");
		mlx_destroy_window(mlx, win);
		ft_memdel((void**)&mlx);
		return (1);
	}

	int bpp = 0;
	int sl = 0;
	int e = 0;
	int *data = (int *)mlx_get_data_addr(img, &bpp, &sl, &e);

	t_point	*points[] = {
		point_new(0, 0, 0),
		point_new(1, 0, 0),
		point_new(2, 0, 0),
		point_new(0, 1, 0),
		point_new(1, 1, 10),
		point_new(2, 1, 0),
		point_new(0, 2, 0),
		point_new(1, 2, 0),
		point_new(2, 2, 0)
	};



	mlx_loop(mlx);

	return (ft_atoi(argv[argc - 1]));
}
