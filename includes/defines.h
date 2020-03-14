/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/14 19:49:23 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 800
# define HEIGHT 600
# define TITLE "FDF"

# include <stdlib.h>

typedef struct	s_point
{
	size_t	x;
	size_t	y;
	size_t	z;
	float	xr;
	float	yr;
	float	zr;
	short	screen_x;
	short	screen_y;
}				t_point;

#endif
