#include "init.h"

void	init_local_normalization(t_fdf *fdf)
{
	ft_memdel((void**)&fdf->matrix_local_normalization);
	fdf->matrix_local_normalization = matrix_new_translation(
		-1.f * (float)(fdf->cols - 1) / 2.f,
		(float)(fdf->rows - 1) / 2.f,
		0);
}

void	init_local_scale(t_fdf *fdf)
{
	float	factor;

	ft_memdel((void**)&fdf->matrix_local_scale);
	if (fdf->options & OPTION_ENABLE_PERSPECTIVE)
	{
		factor = M_SQRT1_2_F * fminf(WIDTH, HEIGHT)
			/ fminf(fminf(fdf->cols, fdf->rows), fdf->height);
		fdf->matrix_local_scale = matrix_new_scale(factor, factor, factor);
	}
	else
	{
		factor = 1.f / fmaxf(fmaxf(fdf->cols, fdf->rows), fdf->height);
		fdf->matrix_local_scale = matrix_new_scale(
			factor,
			factor * WIDTH / HEIGHT,
			-1.f * factor);
	}
}

void	init_world_translation(t_fdf *fdf)
{
	if (!(fdf->options & OPTION_ENABLE_PERSPECTIVE))
		return ;
	ft_memdel((void**)&fdf->matrix_world_translation);
	fdf->matrix_world_translation = matrix_new_translation(0.f, 0.f, -10.f);
}
