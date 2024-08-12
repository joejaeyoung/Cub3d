#include "Cub3d.h"

int	deg2rad(int degrees)
{
	return (degrees * (PI / 180));
}

int	rad2deg(int radians)
{
	return (radians * (180 / PI));
}

int	get_angle(t_direction d)
{
	if (d == NORTH)
		return (90);
	if (d == SOUTH)
		return (180);
	if (d == EAST)
		return (0);
	if (d == WEST)
		return (270);
	return (90);
}

void	coordi_ray_point(t_cub3d *cub3d, double *x, double *y)
{
	// *x = WINDOW_WIDTH / (cub3d->map.max_width + 1) * (*x);
	// *y = WINDOW_HEIGHT / (cub3d->map.map_height + 1) * (*y);
	*x *= cub3d->map.tile_len;
	*y *= cub3d->map.tile_len;
}
