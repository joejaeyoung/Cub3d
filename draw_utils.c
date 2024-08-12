#include "Cub3d.h"

void	my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	cub3d->img->addr[y * WINDOW_WIDTH + x] = color;
}

void	my_mlx_pixel_put_double(t_cub3d *cub3d, double x, double y, int color)
{
	cub3d->img->addr[(int)y * WINDOW_WIDTH + (int)x] = color;
}

//콜 바이 벨류, 콜 바이 레퍼런스 확인하기
void	coordinate_point(t_cub3d *cub3d, t_point *start, t_point *end)
{
	int	s_x;
	int	s_y;
	int	e_x;
	int	e_y;
	s_x = WINDOW_WIDTH / (cub3d->map.max_width + 1) * (*start).width;
	s_y = WINDOW_HEIGHT / (cub3d->map.map_height + 1) * (*start).height;
	e_x = WINDOW_WIDTH / (cub3d->map.max_width + 1) * (*end).width;
	e_y = WINDOW_HEIGHT / (cub3d->map.map_height + 1) * (*end).height;
	(*start).width = s_x;
	(*start).height = s_y;
	(*end).width = e_x;
	(*end).height = e_y;
}

void	coordinate_spot(t_cub3d *cub3d, double *x, double *y)
{
	// *x = WINDOW_WIDTH / (cub3d->map.max_width + 1) * (*x);
	// *y = WINDOW_HEIGHT / (cub3d->map.map_height + 1) * (*y);
	*x *= cub3d->map.tile_len;
	*y *= cub3d->map.tile_len;
}

void	de_coordinate_spot(t_cub3d *cub3d, double *de_x, double *de_y, double *co_x, double *co_y)
{
	*de_x = (cub3d->map.max_width + 1) / WINDOW_WIDTH * (*co_x);
	*de_y = (cub3d->map.map_height + 1) / WINDOW_HEIGHT * (*co_y);
}