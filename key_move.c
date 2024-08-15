#include "Cub3d.h"
#include "Key.h"

void	move_up(t_cub3d *cub3d)
{
	int	nx;
	int	ny;

	nx = (int)(cub3d -> user.x + cub3d -> user.dx * 0.1 / cub3d -> map.tile_len);
	ny = (int)(cub3d -> user.y + cub3d -> user.dy * 0.1 / cub3d -> map.tile_len);
	if (cub3d -> map.array_map[ny][nx] != 1)
	{
		cub3d -> user.x += cub3d -> user.dx * 0.1;
		cub3d -> user.y += cub3d -> user.dy * 0.1;
	}
	
}

void move_down(t_cub3d *cub3d)
{
	int	nx;
	int	ny;

	nx = (int) (cub3d -> user.x - cub3d -> user.dx * 0.1 / cub3d -> map.tile_len);
	ny = (int) (cub3d -> user.y - cub3d -> user.dy * 0.1 / cub3d -> map.tile_len);
	if (cub3d -> map.array_map[ny][nx] != 1)
	{
		cub3d -> user.x -= cub3d -> user.dx * 0.1;
		cub3d -> user.y -= cub3d -> user.dy * 0.1;
	}
}


void move_right(t_cub3d *cub3d)
{
	int	nx;
	int	ny;

	nx = (int) (cub3d -> user.x + cub3d -> user.v_dx * 0.1 / cub3d -> map.tile_len);
	ny = (int) (cub3d -> user.y + cub3d -> user.v_dy * 0.1 / cub3d -> map.tile_len);
	if (cub3d -> map.array_map[ny][nx] != 1)
	{
		cub3d -> user.x += cub3d -> user.v_dx * 0.1;
		cub3d -> user.y += cub3d -> user.v_dy * 0.1;
	}
}

void move_left(t_cub3d *cub3d)
{
	int nx;
	int ny;

	nx = (int) (cub3d -> user.x - cub3d -> user.v_dx * 0.1 / cub3d -> map.tile_len);
	ny = (int) (cub3d -> user.y - cub3d -> user.v_dy * 0.1 / cub3d -> map.tile_len);
	if (cub3d -> map.array_map[ny][nx] != 1)
	{
		cub3d -> user.x -= cub3d -> user.v_dx * 0.1;
		cub3d -> user.y -= cub3d -> user.v_dy * 0.1;
	}
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
