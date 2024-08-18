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
	printf("theta = %lf\n", theta);
	//theta = 180 - theta;
	//theta = deg2rad(theta);
	return (sin(theta) * euclidean_distance);
}

double get_height_ratio(t_cub3d *cub3d, int i, int x)
{
	// double distance_project_plane = (WINDOW_WIDTH / 2) / tan(deg2rad(66));
	// double projected_wall_height = (cub3d -> map.tile_len / get_distance(cub3d, i)) * distance_project_plane;
	// return (projected_wall_height);
	double	euclidean_distance = get_distance(cub3d, i);
	double	prep_distance = get_perp_distance(euclidean_distance, x, cub3d);
	printf("eucl = %lf\n", euclidean_distance);
	printf("perp = %lf\n", prep_distance);
	return (double)WINDOW_HEIGHT / prep_distance;
}

double abs_double(double a)
{
	if (a < 0)
		return -1 * a;
	return a;
}
int	get_face_wall_direction(t_cub3d *cub3d, int i)
{
	double	x;
	double	y;
	double	tmp_x;
	double	tmp_y;

	int	hori;
	double user_x;
	double user_y;
	double wall_x;
	double wall_y;

	int xx;
	int yy;
	//hori == 0 -> x 축에 맞은 ray

	hori = -1;
	x = (double)(cub3d->user.x * cub3d->map.tile_len + cub3d->user.dx * i) / (double)cub3d->map.tile_len + 1;
	y = (double)(cub3d->user.y * cub3d->map.tile_len + cub3d->user.dy * i) / (double)cub3d->map.tile_len + 1;
	tmp_x = abs_double((double)(cub3d->user.x * cub3d->map.tile_len + cub3d->user.dx * i) - (double)cub3d->map.tile_len * x);
	tmp_y = abs_double((double)(cub3d->user.y * cub3d->map.tile_len + cub3d->user.dy * i) - (double)cub3d->map.tile_len * y);
	xx = round(tmp_x);
	yy = round(tmp_y);

	if (xx > yy) {
		hori = 1;
		printf("북남\n");
	}
	else
		hori = 0;

	// x = (double)(cub3d->user.x * cub3d->map.tile_len + cub3d->user.dx * i) / (double)cub3d->map.tile_len;
	// y = (double)(cub3d->user.y * cub3d->map.tile_len + cub3d->user.dy * i) / (double)cub3d->map.tile_len;
	// tmp_x = (double)(cub3d->user.x * cub3d->map.tile_len + cub3d->user.dx * i) - (double)cub3d->map.tile_len * x;
	// tmp_y = (double)(cub3d->user.y * cub3d->map.tile_len + cub3d->user.dy * i) - (double)cub3d->map.tile_len * y;
	
	user_x = (double)(cub3d->user.x * cub3d->map.tile_len);
	user_y = (double)(cub3d->user.y * cub3d->map.tile_len);

	wall_x = (double)(cub3d->user.x * cub3d->map.tile_len + cub3d->user.dx * i);
	wall_y = (double)(cub3d->user.y * cub3d->map.tile_len + cub3d->user.dy * i);

	// if (abs_double(tmp_x) > abs_double(tmp_y)) {
	// 	hori = 1;
	// 	printf("남북\n");
	// }
	// else
	// 	hori = 0;

	if (hori == 0 && (user_x - wall_x) > 0)
		return (1);
	else if (hori == 0 && (user_x - wall_x) < 0)
		return (0);
	else if (hori == 1 && (user_y - wall_y) > 0)
		return (3);
	return (2);
}

void	rotate_dir_vector(t_cub3d *cub3d, double degree, int x)
{
	double	theta;
	double	old_x;
	double	old_y;
	int		i;
	int		wall_dir;

	i = 0;
	old_x = cub3d -> user.dx;
	old_y = cub3d -> user.dy;
	theta = deg2rad(degree);
	cub3d -> user.dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.dy = old_x * sin(theta) + old_y * cos(theta);
	while (1)
	{
		if (is_correct_ray_coordi(cub3d, i))
			i++;
		else
		{
			wall_dir = get_face_wall_direction(cub3d, i);
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

