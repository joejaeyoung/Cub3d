#include "Cub3d.h"

double	deg2rad(int degree)
{
	return (degree * (M_PI / 180));
}

int	rad2deg(int radians)
{
	return (radians * (180 / PI));
}

void	coordi_ray_point(t_cub3d *cub3d, double *x, double *y)
{
	// *x = WINDOW_WIDTH / (cub3d->map.max_width + 1) * (*x);
	// *y = WINDOW_HEIGHT / (cub3d->map.map_height + 1) * (*y);
	*x *= cub3d->map.tile_len;
	*y *= cub3d->map.tile_len;
}

int		is_correct_ray_coordi(t_cub3d *cub3d, int i)
{
	if ((cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i >= 0 && \
		cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i <= WINDOW_WIDTH) && \
		(cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i >= 0 && \
		cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i <= WINDOW_HEIGHT) && \
		cub3d -> map.array_map[(int)(cub3d -> user.y * cub3d -> map.tile_len + \
		cub3d -> user.dy * i) / cub3d -> map.tile_len] \
		[(int) (cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i) \
		/ cub3d -> map.tile_len] != 1
		)
		return (1);
	return (0);
}