#include "Cub3d.h"
#include "Key.h"



void	rotate(int key, t_cub3d *cub3d)
{
	if (key == LEFT_VIEW)
	{	printf("LEFT view\n");
		// if (cub3d->user.direct == NORTH)
		// 	cub3d->user.direct = WEST;
		// else
		// 	cub3d->user.direct += 1;
		cub3d->user.degree += 1;
		if (cub3d->user.degree >= 360)
			cub3d->user.degree = 0;
	}
	if (key == RIGHT_VIEW)
	{	printf("Right view\n");
		// if (cub3d->user.direct == WEST)
		// 	cub3d->user.direct = NORTH;
		// else
		// 	cub3d->user.direct -= 1;
		cub3d->user.degree -= 1;
		if (cub3d->user.degree <= 0)
			cub3d->user.degree = 360;
	}
	printf("rotate : %d\n", cub3d->user.degree);
}

// void	zoom(int key, t_cub3d *cub3d)
// {
// 	if (key == ZOOM_IN)
// 		cub3d->zoom += 1;
// 	if (key == ZOOM_OUT && cub3d->zoom > 1)
// 		cub3d->zoom -= 1;
// }

// void	elevate(int key, t_cub3d *cub3d)
// {
// 	if (key == INCR_Z)
// 		cub3d->z_incr += 0.05;
// 	else
// 		cub3d->z_incr -= 0.05;
// }

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
	draw_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	return (0);
}