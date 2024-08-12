#include "Cub3d.h"

void	one_quadrants(t_cub3d *cub3d, int angle)
{
	double	tmp_x;
	double	tmp_y;
	double	slope;

	slope = tan(angle * 3.141592 / 180.0);
	tmp_x = (double)cub3d->user.x;
	tmp_y = (double)cub3d->user.y;
	coordi_ray_point(cub3d, &tmp_x, &tmp_y);
	while(1)
	{
		if (tmp_y > 0.0 && tmp_x < (double)WINDOW_WIDTH && tmp_x > 0.0 && tmp_y < (double)WINDOW_HEIGHT)
			my_mlx_pixel_put_double(cub3d, tmp_x, tmp_y, 0xff0000);
		else
			break;
		if (angle < 45)
		{
			tmp_y -= 0.01;
			tmp_x += 0.01 * tan((90-angle) * 3.141592 / 180.0);
		}
		else
		{
			tmp_x += 0.01;
			tmp_y += -0.01 * slope;
		}
		//printf("tmp_x : %d. tmp_y : %d slope : %lf\n", tmp_x, tmp_y, slope);
	}
}

void	two_quadrants(t_cub3d *cub3d, int angle)
{
	double	tmp_x;
	double	tmp_y;
	double	slope;

	tmp_x = (double)cub3d->user.x;
	tmp_y = (double)cub3d->user.y;
	slope = tan(angle * 3.141592 / 180.0);
	coordi_ray_point(cub3d, &tmp_x, &tmp_y);
	while(1)
	{
		if (tmp_y > 0.0 && tmp_x < (double)WINDOW_WIDTH && tmp_x > 0.0 && tmp_y < (double)WINDOW_HEIGHT)
			my_mlx_pixel_put_double(cub3d, tmp_x, tmp_y, 0xff0000);
		else
			break;
		if (angle < 90 + 45)
		{
			tmp_y -= 0.01;
			tmp_x += 0.01 * tan((90 - angle) * 3.141592 / 180.0);
		}
		else
		{
			tmp_x -= 0.01;
			tmp_y += 0.01 * slope;
		}
		//printf("tmp_x : %d. tmp_y : %d slope : %lf\n", tmp_x, tmp_y, slope);
	}
}

void	three_quadrants(t_cub3d *cub3d, int angle)
{
	double	tmp_x;
	double	tmp_y;
	double	slope;

	tmp_x = (double)cub3d->user.x;
	tmp_y = (double)cub3d->user.y;
	slope = tan(angle * 3.141592 / 180.0);
	coordi_ray_point(cub3d, &tmp_x, &tmp_y);
	while(1)
	{
		if (tmp_y > 0.0 && tmp_x < (double)WINDOW_WIDTH && tmp_x > 0.0 && tmp_y < (double)WINDOW_HEIGHT)
			my_mlx_pixel_put_double(cub3d, tmp_x, tmp_y, 0xff0000);
		else
			break;
		if (angle > 180 + 45)
		{
			tmp_y += 0.01;
			tmp_x -= 0.01 * tan((270 - angle) * 3.141592 / 180.0);
		}
		else
		{
			tmp_x -= 0.01;
			tmp_y += 0.01 * slope;
		}
		//printf("tmp_x : %d. tmp_y : %d slope : %lf\n", tmp_x, tmp_y, slope);
	}
}

void	four_quadrants(t_cub3d *cub3d, int angle)
{
	double	tmp_x;
	double	tmp_y;
	double	slope;

	tmp_x = (double)cub3d->user.x;
	tmp_y = (double)cub3d->user.y;
	slope = tan(angle * 3.141592 / 180.0);
	coordi_ray_point(cub3d, &tmp_x, &tmp_y);
	while(1)
	{
		if (tmp_y > 0.0 && tmp_x < (double)WINDOW_WIDTH && tmp_x > 0.0 && tmp_y < (double)WINDOW_HEIGHT)
			my_mlx_pixel_put_double(cub3d, tmp_x, tmp_y, 0xff0000);
		else
			break;
		if (angle < 270 + 45)
		{
			tmp_y += 0.01;
			tmp_x += 0.01 * tan((angle - 270) * 3.141592 / 180.0);
		}
		else
		{
			tmp_x += 0.01;
			tmp_y -= 0.01 * slope;
		}
		//printf("tmp_x : %d. tmp_y : %d slope : %lf\n", tmp_x, tmp_y, slope);
	}
}

void	slope_verti_hori(t_cub3d *cub3d, int angle)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = (double)cub3d->user.x;
	tmp_y = (double)cub3d->user.y;
	coordi_ray_point(cub3d, &tmp_x, &tmp_y);
	while(1)
	{
		if (tmp_y > 0 && tmp_x < WINDOW_WIDTH && tmp_x > 0 && tmp_y < WINDOW_HEIGHT)
			my_mlx_pixel_put(cub3d, tmp_x, tmp_y, 0xff0000);
		else
			break;
		if (angle == 90)
			tmp_y -= 1;
		if (angle == 270)
			tmp_y += 1;
		if (angle == 180)
			tmp_x -= 1;
		if (angle == 0 || angle == 360)
			tmp_x += 1;
	}
}
