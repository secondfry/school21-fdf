#ifndef INIT_H
# define INIT_H

# include <math.h>
# include "libft.h"
# include "defines.h"
# include "matrix_factory.h"

void	init_local_normalization(t_fdf *fdf);
void	init_local_scale(t_fdf *fdf);
void	init_world_translation(t_fdf *fdf);

#endif
