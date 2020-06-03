#include "hooks_loop.h"

void	loop_calculate_matrix_world_rotation(t_fdf *fdf)
{
	if (!(fdf->flags & FLAG_INVALIDATE_WORLD_ROTATION))
		return ;
#ifdef LOG_DEBUG
	ft_putendl("FLAG_INVALIDATE_WORLD_PROJECTION");
#endif
	init_world_rotation(fdf);
	fdf->flags -= FLAG_INVALIDATE_WORLD_ROTATION;
	fdf->flags |= FLAG_INVALIDATE_VIEW;
}
