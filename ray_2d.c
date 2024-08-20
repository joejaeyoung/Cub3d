#include "Cub3d.h"

void	ray_init(t_ray *ray, double angle)
{
	ray->ray_angle = angle;
	ray->wall_hitX = 0;
	ray->wall_hitY = 0;
	ray->distance = 0;
	ray->wasHit_vertical = FALSE;

	ray->isRay_facingDown = ray->ray_angle > 0 &&  ray->ray_angle < M_PI;
	ray->isRay_facingUp =!ray->isRay_facingDown;
	ray->isRay_facingRight = ray->ray_angle < 0.5 * M_PI || ray->ray_angle > 1.5 * M_PI;
	ray->isRay_facingLeft = !ray->isRay_facingRight;
}

int	cal_horz_ray(t_cub3d *cub3d, t_dpable_ray *horz)
{
	horz->found_wall_hit = FALSE;
	horz->wall_hitX = 0;
	horz->wall_hitY = 0;

	horz->y_intercept = floor(cub3d->user.y / cub3d->map.tile_len) * cub3d->map.tile_len;
	horz->y_intercept += cub3d->ray.isRay_facingDown ? cub3d->map.tile_len : 0;

	horz->x_intercept = cub3d->user.x + (horz->y_intercept - cub3d->user.y) / tan(cub3d->ray.ray_angle);

	horz->y_step = cub3d->map.tile_len;
	horz->y_step *= cub3d->ray.isRay_facingUp ? -1 : 1;

	horz->x_step = cub3d->map.tile_len / tan(cub3d->ray.ray_angle);
	horz->x_step *= (cub3d->ray.isRay_facingLeft && horz->x_step > 0) ? -1 : 1;
	horz->x_step *= (cub3d->ray.isRay_facingRight && horz->x_step < 0) ? -1 : 1;
}

int	cal_vert_ray()
{

}

int	get_face_wall_direction_2d(t_cub3d *cub3d, int dir, int i)
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

int		find_is_wall(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	int tile = cub3d->map.tile_len;

	double posX = cub3d->user.x;
	double posY = cub3d->user.y;

	//array 인덱스 기준으로 찍힘
	int mapX = (int)cub3d->user.x;
	int mapY = (int)cub3d->user.y;
	//printf("User : %d, %d\n", mapX, mapY);


	double sideDistX;
	double sideDistY;

	double deltaDistX = (ray_dir_y == 0) ? 0 : ((ray_dir_x == 0) ? 1 : abs(1 / ray_dir_x));
	double deltaDistY = (ray_dir_x == 0) ? 0 : ((ray_dir_y == 0) ? 1 : abs(1 / ray_dir_y));
	double perpWallDist;

	//printf("r_x : %lf, r_y : %lf, d_x : %lf, d_y : %lf\n", ray_dir_x, ray_dir_y, deltaDistX, deltaDistY);

	int stepX;
	int stepY;

	int hit = 0;
	int side;

	//calculate step and inital sideDist
	if (ray_dir_x < 0)
	{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
	} else {
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}

	if (ray_dir_y < 0)
	{
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
	} else {
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}

	//perform DDA
	while(hit == 0)
	{
		my_mlx_pixel_put(cub3d, mapX * cub3d->map.tile_len, mapY * cub3d->map.tile_len, 0xff0000);
		//jumpt to next map square, Or in x-direction, Or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			//printf("x기준 : side : %lf, delta : %lf, map : %d, step :%d \n", sideDistX, deltaDistX, mapX, stepX);
			//x줄
			side = 0;
		} else {
			//printf("y기준 : side : %lf, delta : %lf, map : %d, step :%d \n", sideDistY, deltaDistY, mapY, stepY);
			sideDistY += deltaDistY;
			mapY += stepY;
			//y면 가로줄
			side = 1;
		}
	
		//Check if ray has hit a wall
		if (cub3d->map.array_map[mapY][mapX] == 1)
		{
			hit = 1;
			printf("벽 부딪힘 : %d : %d : %d\n", mapX , mapY , side);
			// //fill_square(cub3d, mapX * cub3d->map.tile_len, mapY * cub3d->map.tile_len, 0xff0000);
			// for(int i = posY * tile; i < (posY + mapY) * tile; i++) {
			// 	for(int j = posX * tile; j < (posX + mapX) * tile; j++)
			// 		my_mlx_pixel_put(cub3d, j, i, 0xff0000);
			// }
			for (int row = -(4) / 2; row <= (4) / 2; row++)
			{
				for (int col = -(4) / 2; col <= (4) / 2; col++)
				{
					cub3d->img->addr[(int)(1 * (WINDOW_WIDTH * (mapY * tile + row))) + (mapX * tile+ col)] = 0xff0000;
				}
			}
			// while(1) {
			// 	int i = 1;
			// 	int dirx = mapX - cub3d->user.x / 
			// 	my_mlx_pixel_put(cub3d, (cub3d -> user.x * cub3d -> map.tile_len + ray_dir_x * i) , \
			// 	(cub3d -> user.y * cub3d -> map.tile_len + ray_dir_y* i), 0xff0000);
			// 	i += 1;
				
			// }
		}
	}
}

int		is_correct_ray_coordi_2d(t_cub3d *cub3d, int i)
{
	//find_is_wall(cub3d, 1);
	if ((cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i >= 0 && \
		cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i <= WINDOW_WIDTH) && \
		(cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i >= 0 && \
		cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i <= WINDOW_HEIGHT))
		{
			// if (cub3d -> map.array_map[(int)(cub3d -> user.y * cub3d -> map.tile_len + \
			// cub3d -> user.dy * i) / cub3d -> map.tile_len] \
			// [(int) (cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i) \
			// / cub3d -> map.tile_len] != 1
			// )
			// {
			// 	// if (y % cub3d->map.tile_len == 0)
			// 	// 	printf("x 축에 맞음\n");
			// 	// else if (x % cub3d->map.tile_len == 0)
			// 	// 	printf("y 축에 맞음\n");
			// return (1);
			// }
		return (1);
		}
	return (0);
}

void	rotate_dir_vector_2d(t_cub3d *cub3d, double degree, int x)
{
	ray_init(&cub3d->ray, degree);

	double	theta;
	double	old_x;
	double	old_y;
	double		i;
	int		wall_dir;

	i = 0.0;
	old_x = cub3d -> user.dx;
	old_y = cub3d -> user.dy;
	theta = deg2rad(degree);
	cub3d -> user.dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.dy = old_x * sin(theta) + old_y * cos(theta);

	double	ray_dir_x = cub3d->user.dx;
	double	ray_dir_y = cub3d->user.dy;
	printf("ray dir : %lf, %lf\n", ray_dir_x, ray_dir_y);

	find_is_wall(cub3d, ray_dir_x, ray_dir_y);

	while (1)
	{
		int tmp = is_correct_ray_coordi_2d(cub3d, i);
		if (tmp) {
			my_mlx_pixel_put(cub3d, (cub3d -> user.x * cub3d -> map.tile_len + cub3d -> user.dx * i) , \
			(cub3d -> user.y * cub3d -> map.tile_len + cub3d -> user.dy * i), 0xff0000);
			i += 0.5;
		}
		else
			break;
	}
	cub3d -> user.dx = old_x;
	cub3d -> user.dy = old_y;
}

void	shoot_ray_2d(t_cub3d *cub3d, double degree)
{
	double	original_degree;
	double	step;
	int		x;

	x = 0;
	step = 66 / (double) WINDOW_WIDTH;
	original_degree = degree;
	// printf("===start===\n");
	// while (degree >= -original_degree)
	// {
		rotate_dir_vector_2d(cub3d, 0, x);
	// 	degree -= step;
	// 	x++;
	// }
	// printf("===end===\n");
}

void	draw_ray_2d(t_cub3d *cub3d)
{
	shoot_ray_2d(cub3d, 33);
}

