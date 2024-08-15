#include "Cub3d.h"

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

void	rotate_dir_vector(t_cub3d *cub3d, int degree)
{
	double	theta;
	double	old_x;
	double	old_y;
	int		i;

	i = 0;
	old_x = cub3d -> user.dx;
	old_y = cub3d -> user.dy;
	theta = (double) degree * M_PI / 180;
	cub3d -> user.dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.dy = old_x * sin(theta) + old_y * cos(theta);
	while (1)
	{
		if (is_correct_ray_coordi(cub3d, i))
		{
			my_mlx_pixel_put(cub3d, (cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i) , \
			(cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i), 0xff0000);
			i++;
		}
		else
			break ;
	}
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
	shoot_ray(cub3d, 33);
}

