#include "Cub3d.h"

double	get_distance(t_cub3d *cub3d, int i)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = cub3d -> user.x * (double)cub3d -> map.tile_len;
	y1 = cub3d -> user.y * (double)cub3d -> map.tile_len;
	x2 = cub3d -> user.x * (double)cub3d -> map.tile_len + (double)cub3d -> user.dx * i;
	y2 = cub3d -> user.y * (double)cub3d -> map.tile_len + (double)cub3d -> user.dy * i;
	return (sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0)));
}

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

double get_height_ratio(t_cub3d *cub3d, int i, int x)
{
	// double distance_project_plane = (WINDOW_WIDTH / 2) / tan(deg2rad(66));
	// double projected_wall_height = (cub3d -> map.tile_len / get_distance(cub3d, i)) * distance_project_plane;
	// return (projected_wall_height);
	double	euclidean_distance = get_distance(cub3d, i);
	double	prep_distance = get_perp_distance(euclidean_distance, x, cub3d);
	//printf("eucl = %lf\n", euclidean_distance);
	//printf("perp = %lf\n", prep_distance);
	return (double)WINDOW_HEIGHT / prep_distance;
}

double abs_double(double a)
{
	if (a < 0)
		return -1 * a;
	return a;
}

int abs_int(int a)
{
	if (a < 0)
		return -1 * a;
	return a;
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

void	rotate_dir_vector(t_cub3d *cub3d, double degree, int x)
{
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

	double ray_dir_x = cub3d->user.dx;
	double ray_dir_y = cub3d->user.dy;
	while (1)
	{
		int tmp = is_correct_ray_coordi(cub3d, i);
		if (tmp == 1)
			i += 0.1;
		else
		{
			wall_dir = get_face_wall_direction(cub3d, tmp, i);
			ver_line(cub3d, x, get_height_ratio(cub3d, i, x),  0xff0000, wall_dir);
			break ;
		}
	}
	cub3d -> user.dx = old_x;
	cub3d -> user.dy = old_y;
}

void	shoot_ray(t_cub3d *cub3d, double degree)
{
	double	original_degree;
	double	step;
	int		x;

	x = 0;
	step = 66 / (double) WINDOW_WIDTH;
	original_degree = degree;
	printf("===start===\n");
	while (degree >= -original_degree)
	{
		rotate_dir_vector(cub3d, degree, x);
		degree -= step;
		x++;
	}
	printf("===end===\n");
}

void	draw_ray(t_cub3d *cub3d)
{
	shoot_ray(cub3d, 33);
}

