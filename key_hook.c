#include "Cub3d.h"
#include "Key.h"

void	rotate(int key, t_cub3d *cub3d)
{
	double	old_x;
	double	old_y;
	double	theta;
	double 	degree;

	if (key == LEFT_VIEW)
		degree = -1;
	else
		degree = 1;
	old_x = cub3d -> user.dx;
	old_y = cub3d -> user.dy;
	theta = deg2rad(degree);
	cub3d -> user.dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.dy = old_x * sin(theta) + old_y * cos(theta);
	old_x = cub3d -> user.v_dx;
	old_y = cub3d -> user.v_dy;
	cub3d -> user.v_dx = old_x * cos(theta) - old_y * sin(theta);
	cub3d -> user.v_dy = old_x * sin(theta) + old_y * cos(theta);
}

int	exit_program(void *f)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)f;
	// mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	// mlx_destroy_window(cub3d->mlx, cub3d->win);
	// mlx_destroy_display(cub3d->mlx);
	// free(cub3d->mlx);
	exit(SUCCESS);
}

int	handle_key(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		exit_program(cub3d);
	// if (key == ZOOM_IN || key == ZOOM_OUT)
	// 	zoom(key, cub3d);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		move(key, cub3d);
	if (key == LEFT_VIEW || key == RIGHT_VIEW)
		rotate(key, cub3d);
	// if (key == ROTATE_X || key == RE_ROTATE_X || key == ROTATE_Z || \
	// key == RE_ROTATE_Z || key == ROTATE_Y || key == RE_ROTATE_Y)
	// 	rotate(key, cub3d);
	// if (key == INCR_Z || key == DECR_Z)
	// 	elevate(key, cub3d);
	// if (key == F_VIEW || key == T_VIEW || key == R_VIEW)
	// 	bonus_graphic(key, cub3d);
	mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	cub3d->img->img = mlx_new_image(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!cub3d->img->img)
		error(8);
	//draw_minimap(cub3d);
	draw_ray(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	return (0);
}