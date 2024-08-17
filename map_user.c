#include "Cub3d.h"

void	user_north(t_cub3d *cub3d)
{
	cub3d->user.dx = 0;
	cub3d->user.dy = -1;
	cub3d->user.v_dx = 1;
	cub3d->user.v_dy = 0;
}

void	user_west(t_cub3d *cub3d)
{
	cub3d->user.dx = -1;
	cub3d->user.dy = 0;
	cub3d->user.v_dx = 0;
	cub3d->user.v_dy = -1;
}

void	user_south(t_cub3d *cub3d)
{
	cub3d->user.dx = 0;
	cub3d->user.dy = -1;
	cub3d->user.v_dx = -1;
	cub3d->user.v_dy = 0;
}

void	user_east(t_cub3d *cub3d)
{
	cub3d->user.dx = 1;
	cub3d->user.dy = 0;
	cub3d->user.v_dx = 0;
	cub3d->user.v_dy = 1;
}

void	get_user_direction(t_cub3d *cub3d, char c)
{
	if (c == 'N' || c == 'n')
		user_north(cub3d);
	else if (c == 'W' || c == 'w')
		user_west(cub3d);
	else if (c == 'S' || c == 's')
		user_south(cub3d);
	else if (c == 'E' || c == 'e')
		user_east(cub3d);
	else
		error(9);
}