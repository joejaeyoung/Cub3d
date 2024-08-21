#include "Cub3d.h"

void	ver_line(t_cub3d *cub3d, int x, double y_s, double y_e, int wall_dir)
{

	int y1;
	int y2;

	y1 = y_s;
	y2 = y_e;
	while (y1 <= y2){
		if (0 <= x && x <= WINDOW_WIDTH && \
			0 <= y1 && y1 <= WINDOW_HEIGHT)
		
		my_mlx_pixel_put(cub3d, x , y1, cub3d->map.texture[wall_dir].texture[64 * ((int)round(y1) % 64) + (x % 64)]);
		y1++;
	}
}

// void	ver_line_2d(t_cub3d *cub3d, int x, int color, int wall_dir)
// {
// 	double	y1;
// 	double	y2;

// 	y1 = (double)WINDOW_HEIGHT / 2 - height * 5;
// 	y2 = (double)WINDOW_HEIGHT / 2 + height * 5;
// 	while (y1 <= y2){
// 		if (0 <= x && x <= WINDOW_WIDTH && \
// 			0 <= y1 && y1 <= WINDOW_HEIGHT)
		
// 		my_mlx_pixel_put(cub3d, x , y1, cub3d->map.texture[wall_dir].texture[64 * ((int)round(y1) % 64) + (x % 64)]);
// 		y1++;
// 	}
// }