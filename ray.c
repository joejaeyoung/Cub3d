#include "Cub3d.h"

double	get_distance(t_cub3d *cub3d, int i)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = cub3d -> user.x * cub3d -> map.tile_len;
	y1 = cub3d -> user.y * cub3d -> map.tile_len;
	x2 = cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i;
	y2 = cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i;
	return (sqrt(pow(x2 - x1, 2)) + sqrt(pow(y2 - y1, 2)));
}

double get_height_ratio(t_cub3d *cub3d, int i)
{
	double	distance;

	distance = get_distance(cub3d, i);
	printf("distance = %lf\n" , get_distance(cub3d, i));
	return (WINDOW_HEIGHT / distance);
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
	theta = deg2rad(degree);
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
		{
			printf("height = %lf\n" , get_height_ratio(cub3d, i));
			break ;
		}
	}
	cub3d -> user.dx = old_x;
	cub3d -> user.dy = old_y;
}

void	shoot_ray(t_cub3d *cub3d, int degree)
{
	int	i;

	i = degree;
	printf("========\n");
	while (i >= -degree)
	{
		rotate_dir_vector(cub3d, i);
		i--;
	}
	printf("========\n");
}

void	draw_ray(t_cub3d *cub3d)
{
	shoot_ray(cub3d, 33);
}

