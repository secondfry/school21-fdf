/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/02/29 14:17:34 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "mlx.h"
#include "libft.h"

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

	mlx_loop(mlx);

	return (ft_atoi(argv[argc - 1]));
}
