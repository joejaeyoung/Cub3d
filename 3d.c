#include "Cub3d.h"

void	ver_line(t_cub3d *cub3d, int x, int y, int height, int color, int degree)
{
	printf("verLine\n");
	int	tmp_y;

	// tmp_y = height * 30;
	// while(tmp_y > 0)
	// {
	// 	my_mlx_pixel_put(cub3d, (degree + 33) * 33, WINDOW_HEIGHT / 2 + tmp_y, color);
	// 	tmp_y--;
	// }
	tmp_y = 0;
	while(tmp_y < height * 20)
	{
		if ((degree + 33) * 25 > 0 && (degree + 33) * 25 < WINDOW_WIDTH)
			if((WINDOW_HEIGHT / 2 - tmp_y) > 0 && (WINDOW_HEIGHT / 2 - tmp_y) < WINDOW_HEIGHT)
		my_mlx_pixel_put(cub3d, (degree + 33) * 25, WINDOW_HEIGHT / 2 - tmp_y, color);
		tmp_y++;
	}
	tmp_y = 0;
	while(tmp_y < height * 20)
	{
		if ((degree + 33) * 25 > 0 && (degree + 33) * 25 < WINDOW_WIDTH)
			if((WINDOW_HEIGHT / 2 + tmp_y) > 0 && (WINDOW_HEIGHT / 2 + tmp_y) < WINDOW_HEIGHT)
		my_mlx_pixel_put(cub3d, (degree + 33) * 25, WINDOW_HEIGHT / 2 + tmp_y, color);
		tmp_y++;
	}
}