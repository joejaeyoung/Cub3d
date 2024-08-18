#include "Cub3d.h"

void	ver_line(t_cub3d *cub3d, int x, double height, int color)
{
	double	y1;
	double	y2;

	y1 = WINDOW_HEIGHT / 2 - height * 5;
	y2 = WINDOW_HEIGHT / 2 + height * 5;
	while (y1 <= y2){
		if (0 <= x && x <= WINDOW_WIDTH && \
			0 <= y1 && y1 <= WINDOW_HEIGHT)
		my_mlx_pixel_put(cub3d, round(x) , round(y1), color);
		y1++;
	}
}