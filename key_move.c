#include "Cub3d.h"
#include "Key.h"

// int	is_wall(t_cub3d *cub3d, double x, double y)
// {
// 	int		tile_len;
// 	t_field	*field;

// 	tile_len = cub3d->map.tile_len;
// 	if ((int)round(x) % tile_len == 0 || (int)round(y) % tile_len == 0)
// 	{
// 		field = ft_lstfind_node(cub3d->map.field, (int)y / tile_len);
// 		printf("y : %d, x : %d, v : %d\n", field->line[(int)x / tile_len].height, field->line[(int)x / tile_len].width, field->line[(int)x / tile_len].value);
// 		if (field->line[(int)x / tile_len].value == 1)
// 		{
// 			printf("벽이다!\n");
// 			return (SUCCESS);
// 		}
// 	}
// 	return (FAIL);
// }

void	move_up(t_cub3d *cub3d)
{
	// int	deg;
	// double	tmp_x;
	// double	tmp_y;

	// tmp_x = 0;
	// tmp_y = 0;
	// deg = cub3d->user.degree;
	// if (deg == 90)
	// 	tmp_y = -0.01;
	// else if (deg == 180)
	// 	tmp_x = -0.005;
	// else if (deg == 270)
	// 	tmp_y = 0.005;
	// else if (deg == 0 || deg == 360)
	// 	tmp_x = 0.005;
	// else if ((deg > 0 && deg < 90) || (deg > 270 && deg < 360))
	// {
	// 	tmp_x = 0.01;
	// 	tmp_y = -0.01 * tan(deg * 3.141592 / 180.0);
	// }
	// else if ((deg > 90 && deg < 180) || (deg > 180 && deg < 270))
	// {
	// 	tmp_x = -0.01;
	// 	tmp_y = 0.01 * tan(deg * 3.141592 / 180.0);
	// }
	// if (is_wall(cub3d, cub3d->user.x + tmp_x, cub3d->user.y + tmp_y) == FAIL)
	// {
	// 	cub3d->user.x += tmp_x;
	// 	cub3d->user.y += tmp_y;
	// }
	cub3d -> user.x += cub3d -> user.dx * 0.1;
	cub3d -> user.y += cub3d -> user.dy * 0.1;
}

void move_down(t_cub3d *cub3d)
{
	// int	deg;

	// deg = cub3d->user.degree;
	// if (deg == 90)
	// 	cub3d->user.y += 0.005;
	// if (deg == 180)
	// 	cub3d->user.x += 0.005;
	// if (deg == 270)
	// 	cub3d->user.y -= 0.005;
	// if (deg == 0 || deg == 360)
	// 	cub3d->user.x -= 0.01;
	// if ((deg > 0 && deg < 90) || (deg > 270 && deg < 360))
	// {
	// 	cub3d->user.x -= 0.01;
	// 	cub3d->user.y += 0.01 * tan((deg + 180) * 3.141592 / 180.0);
	// }
	// if ((deg > 90 && deg < 180) || (deg > 180 && deg < 270))
	// {
	// 	cub3d->user.x += 0.01;
	// 	cub3d->user.y -= 0.01 * tan((deg + 180) * 3.141592 / 180.0);
	// }
	cub3d -> user.x -= cub3d -> user.dx * 0.1;
	cub3d -> user.y -= cub3d -> user.dy * 0.1;
}


void move_right(t_cub3d *cub3d)
{
	// int	deg;




	// deg = cub3d->user.degree;
	// if (deg - 90 < 0)
	// 	deg = 270 + deg;
	// else
	// 	deg = deg- 90;
	// if (deg == 90)
	// 	cub3d->user.y -= 0.005;
	// if (deg == 180)
	// 	cub3d->user.x -= 0.005;
	// if (deg == 270)
	// 	cub3d->user.y += 0.005;
	// if (deg == 0 || deg == 360)
	// 	cub3d->user.x += 0.005;
	// if ((deg > 0 && deg < 90) || (deg > 270 && deg < 360))
	// {
	// 	cub3d->user.x += 0.01;
	// 	cub3d->user.y -= 0.01 * tan(deg * 3.141592 / 180.0);
	// }
	// if ((deg > 90 && deg < 180) || (deg > 180 && deg < 270))
	// {
	// 	cub3d->user.x -= 0.01;
	// 	cub3d->user.y += 0.01 * tan(deg * 3.141592 / 180.0);
	// }
	cub3d -> user.x += cub3d -> user.v_dx * 0.1;
	cub3d -> user.y += cub3d -> user.v_dy * 0.1;
}

void move_left(t_cub3d *cub3d)
{
	// int	deg;

	// deg = cub3d->user.degree;
	// if (deg - 90 < 0)
	// 	deg = 270 + deg;
	// else
	// 	deg = deg- 90;
	// if (deg == 90)
	// 	cub3d->user.y += 0.005;
	// if (deg == 180)
	// 	cub3d->user.x += 0.005;
	// if (deg == 270)
	// 	cub3d->user.y -= 0.005;
	// if (deg == 0 || deg == 360)
	// 	cub3d->user.x -= 0.005;
	// if ((deg > 0 && deg < 90) || (deg > 270 && deg < 360))
	// {
	// 	cub3d->user.x -= 0.01;
	// 	cub3d->user.y += 0.01 * tan(deg * 3.141592 / 180.0);
	// }
	// if ((deg > 90 && deg < 180) || (deg > 180 && deg < 270))
	// {
	// 	cub3d->user.x += 0.01;
	// 	cub3d->user.y -= 0.01 * tan(deg * 3.141592 / 180.0);
	// }
	cub3d -> user.x -= cub3d -> user.v_dx * 0.1;
	cub3d -> user.y -= cub3d -> user.v_dy * 0.1;
	// cub3d -> user.y -= cub3d -> user.dy * 0.1;
}

void	move(int key, t_cub3d *cub3d)
{
	if (key == UP)
		move_up(cub3d);
	if (key == DOWN)
		move_down(cub3d);
	if (key == RIGHT)
		move_right(cub3d);
	if (key == LEFT)
		move_left(cub3d);
}
