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


int	get_face_wall_direction(t_cub3d *cub3d, int dir, int i)
{
	double u_x;
	double u_y;
	double w_x;
	double w_y;
	double d_x;
	double d_y;

	int r_x;
	int r_y;

	int hori;
	u_x = cub3d->user.x * cub3d->map.tile_len;
	u_y = cub3d->user.y * cub3d->map.tile_len;
	w_x = u_x + cub3d->user.dx * i;
	w_y = u_y + cub3d->user.dy * i;
	r_x = (int)(w_x * 1000)%24;
	r_y = (int)(w_y * 1000)%24;


	//printf("ux : %lf, uy : %lf\n", u_x, u_y);
	//printf("w_x : %lf, w_y : %lf\n", w_x, w_y);
	
	//printf("dx : %d, dy : %d\n", r_x, r_y);
	
	//printf("rx : %d, ry : %d\n", r_x, r_y);
	printf("dir :%d\n", dir);
	//printf("tile len : %d\n", cub3d->map.tile_len);
	if (r_x < r_y) {
		hori =0;
		//printf("동서\n");
	}
	else {
		hori = 1;
		//printf("남북\n");
	}
	//west
	if (hori == 0 && (u_x - w_x) > 0) {
		return 1;
	}
	//east
	else if (hori == 0 && (u_x - w_x) < 0) {
		return 0;
	}
	//south
	else if (hori == 1 && (u_y - w_y) > 0) {
		return (3);
	}
	return (2);

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
			// ray->wall_hitX = ray->map_x;
			// ray->wall_hitY = ray->map_y;
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
	while (ray -> verLineDrawStart <= ray -> verLineDrawEnd)
	{
		int	color;

		if (ray -> side)
			color = 0xff0000;
		else
			color = 0xff00ff;
		my_mlx_pixel_put(cub3d, x , ray -> verLineDrawStart, color);
		ray -> verLineDrawStart++;
	}
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

