/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 05:58:38 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:46:23 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <fcntl.h>
# include "get_next_line.h"
# include "defines.h"
# include "graceful.h"
# include "vector.h"

typedef struct	s_i
{
	size_t		d;
	size_t		x;
	size_t		y;
	ssize_t		z;
}				t_i;

void			check_file(char *filename);
size_t			dots_in_line(char *line, ssize_t *out);
void			scan_file(t_fdf *fdf, char *filename);
void			fill_data(t_fdf *fdf, char *filename);
void			input(t_fdf *fdf, char *filename);

#endif
