#include "Cub3d.h"

int		is_wall(t_cub3d *cub3d, double x, double y)
{
	int	len;
	int	tmp_y;
	int	tmp_x;
	int	tmp_x2;

	tmp_y = round(y);
	tmp_x = (int)(x);
	tmp_x2 = (int)(x) + 1;
	len = cub3d->map.tile_len;
	// if (cub3d->map.array_map[tmp_y / len - 1][tmp_x / len] == 1 || 
	// 	cub3d->map.array_map[tmp_y / len - 1][(tmp_x + 1) / len] == 1 ||
	// 	cub3d->map.array_map[tmp_y / len][tmp_x / len] == 1)
	// 	return (1);
	if (cub3d->map.array_map[tmp_y / len - 1][tmp_x / len] == 1)
		return (1);
	return (0);
}

void	draw_one_ray(t_cub3d *cub3d, int angle)
{
	if (angle % 90 == 0)
		slope_verti_hori(cub3d, angle);
	if (angle > 0 && angle < 90 || angle > 360)
		one_quadrants(cub3d, angle);
	if (angle > 90 && angle < 180)
		two_quadrants(cub3d, angle);
	if (angle > 180 && angle < 270)
		three_quadrants(cub3d, angle);
	if (angle > 270 && angle < 360 || angle < 0)
		four_quadrants(cub3d, angle);
}

void	draw_ray(t_cub3d *cub3d)
{
	t_direction direction = cub3d->user.direct;
	double	angle;
	double	max_angle;

	angle = cub3d->user.degree;
	max_angle = angle + 30;

	while(angle <= max_angle)
	{
		draw_one_ray(cub3d, angle);
		draw_one_ray(cub3d, angle - 30);
		angle += 5;
	}
}

