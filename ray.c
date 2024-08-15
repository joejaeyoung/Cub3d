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



void	rotate_dir_vector(t_cub3d *cub3d, int degree)
{
	double	theta;
	double	old_x;
	double	old_y;
	int		i;
	int		j;

	old_x = cub3d -> user.dx;
	old_y = cub3d -> user.dy;
	theta = (double) degree * M_PI / 180;
	cub3d -> user.dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.dy = old_x * sin(theta) + old_y * cos(theta);
	my_mlx_pixel_put(cub3d, (cub3d -> user.x+ cub3d -> user.dx) * cub3d -> map.tile_len, (cub3d -> user.y+cub3d -> user.dy )* cub3d -> map.tile_len, 0xff0000);
	cub3d -> user.dx = old_x;
	cub3d -> user.dy = old_y;
}

void	shoot_ray(t_cub3d *cub3d, int degree)
{
	int	i;

	i = degree;
	while (i >= -degree)
	{
		rotate_dir_vector(cub3d, i);
		i--;
	}
}

void	draw_ray(t_cub3d *cub3d)
{
	printf("user x = %lf\n", cub3d -> user.x);
	printf("user y = %lf\n", cub3d -> user.y);
	shoot_ray(cub3d, 33);

}

