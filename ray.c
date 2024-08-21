#include "Cub3d.h"


double	get_perp_distance(double euclidean_distance, int x, t_cub3d *cub3d)
{
	double	theta;
	double	v_dx;
	double	v_dy;
	double	r_dx;
	double	r_dy;
	//printf("euclidean_ : %lf\n", euclidean_distance);
	// if (x == WINDOW_WIDTH / 2)
	// 	return (euclidean_distance);
	r_dx = cub3d -> user.dx;
	r_dy = cub3d -> user.dy;
	//printf("ray 크기 : %lf\n", sqrt(pow(r_dx, 2) + pow(r_dy, 2)));
	//printf("ray 벡터 : %lf, %lf\n", r_dx, r_dy);
	v_dx = cub3d -> user.v_dx;
	v_dy = cub3d -> user.v_dy;
	//printf("수직 크기 : %lf\n", sqrt(pow(v_dx, 2) + pow(v_dy, 2)));
	//printf("수직 벡터 : %lf, %lf\n", v_dx, v_dy);
	if (x < WINDOW_WIDTH / 2)
	{
		theta = acos((r_dx * v_dx + r_dy * v_dy));
		//printf("내적 : %lf\n", (r_dx * -v_dx + r_dy * -v_dy));
	}
	else
	{
		theta = acos((r_dx * v_dx * -1 + r_dy * v_dy * -1));
		//printf("내적 : %lf\n", (r_dx * v_dx + r_dy * v_dy));
	}
	//theta = rad2deg(theta);
	//printf("theta = %lf\n", theta);
	//theta = 180 - theta;
	//theta = deg2rad(theta);
	return (sin(theta) * (euclidean_distance));
}


int	get_wall_dir(t_cub3d *cub3d, t_dpable_ray *ray)
{
	//x축 (남, 북)
	if (ray->side == 1)
	{
		//북
		if (ray->pos_y - ray->wall_hitY > 0)
			return (3);
		else
			return (2);
	}
	//y축 (동, 서)
	else if (ray->side == 0)
	{
		//서
		if (ray->pos_x - ray->wall_hitX > 0)
			return (1);
	}
	//동
	return (0);
}



void	dda(t_cub3d *cub3d, t_dpable_ray *ray)
{
	int	hit;

	hit = 0;
	while(hit == 0)
	{
		// my_mlx_pixel_put(cub3d, ray-> map_x * cub3d->map.tile_len, ray-> map_y * cub3d->map.tile_len, 0xff0000);
		if (ray -> sdx < ray -> sdy)
		{
			ray -> sdx += ray -> ddx;
			ray -> map_x += ray -> step_x;
			//printf("x기준 : side : %lf, delta : %lf, map : %d, step :%d \n", sideDistX, deltaDistX, mapX, stepX);
			//x줄
			ray -> side = 0;
		} 
		else {
			//printf("y기준 : side : %lf, delta : %lf, map : %d, step :%d \n", sideDistY, deltaDistY, mapY, stepY);
			ray-> sdy += ray-> ddy;
			ray-> map_y += ray -> step_y;
			//y면 가로줄
			ray->side = 1;
		}
	
		//Check if ray has hit a wall
		if (cub3d->map.array_map[ray -> map_y][ray -> map_x] == 1)
		{
			ray->wall_hitX = ray->map_x;
			ray->wall_hitY = ray->map_y;
			hit = 1;
			// printf("벽 부딪힘 : %d : %d : %d\n", ray->map_x , ray->map_y , ray->side);
			// for (int row = -(4) / 2; row <= (4) / 2; row++)
			// {
			// 	for (int col = -(4) / 2; col <= (4) / 2; col++)
			// 	{
			// 		cub3d->img->addr[(int)(1 * (WINDOW_WIDTH * (ray->map_y * cub3d->map.tile_len + row))) + (ray->map_x * cub3d->map.tile_len+ col)] = 0xff0000;
			// 	}
			// }
		}
	}
}

void	draw_ceil(t_cub3d *cub3d, int x, t_dpable_ray *ray)
{
	int y;

	y = 0;
	while (y < ray -> verLineDrawStart)
		my_mlx_pixel_put(cub3d, x, y++, cub3d -> map.ceiling_color.color);
}
void	draw_floor(t_cub3d *cub3d, int x, t_dpable_ray *ray)
{
	int y;

	y = ray -> verLineDrawEnd;
	while (y < WINDOW_HEIGHT)
		my_mlx_pixel_put(cub3d, x, y++, cub3d -> map.floor_color.color);
}

void	find_wall_3d(t_cub3d *cub3d, t_dpable_ray *ray, int x)
{
	init_ray(cub3d, ray , x);
	dda(cub3d, ray);
	if (ray->side == 0)
		ray->perpWallDist = (ray->sdx - ray->ddx);
	else
		ray->perpWallDist  = (ray->sdy - ray->ddy);
	ray->lineHeight = (int)(WINDOW_HEIGHT / ray->perpWallDist);
	ray->verLineDrawStart = -ray->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (ray->verLineDrawStart < 0)
		ray->verLineDrawStart = 0;
	ray->verLineDrawEnd = ray->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (ray->verLineDrawEnd >= WINDOW_HEIGHT)
		ray->verLineDrawEnd = WINDOW_HEIGHT - 1;
	draw_ceil(cub3d, x, ray);
	ver_line(cub3d, x, ray->verLineDrawStart, ray->verLineDrawEnd, get_wall_dir(cub3d, ray));
	draw_floor(cub3d, x, ray);
}

// void	rotate_dir_vector(t_cub3d *cub3d, int x)
// {
// 	t_dpable_ray	ray;
// 	find_wall_3d(cub3d, &ray, x);
// }

void	shoot_ray(t_cub3d *cub3d)
{
	int				x;
	t_dpable_ray	ray;

	x =  0;
	while (x < WINDOW_WIDTH)
	{
		find_wall_3d(cub3d, &ray, x);
		x++;
	}
}

void	draw_ray(t_cub3d *cub3d)
{
	shoot_ray(cub3d);
}

