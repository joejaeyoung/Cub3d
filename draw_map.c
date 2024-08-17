#include "Cub3d.h"

void	fill_image(t_cub3d *cub3d)
{
	cub3d->img->addr = (int *)mlx_get_data_addr(cub3d->img->img, &cub3d->img->pixel_bits, \
	&cub3d->img->line_bytes, &cub3d->img->endian);
	if (!cub3d->img->addr)
		error(4);
	//draw_minimap(cub3d);	
	draw_ray(cub3d);
}

void	init_window(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		error(4);
	cub3d->win = mlx_new_window(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!cub3d->win)
		error(4);
}
void	make_it_3d(t_cub3d *cub3d)
{
	t_img img;

	img.addr = NULL;
	cub3d->map.zoom = ((WINDOW_WIDTH / cub3d->map.max_width) / 3);

	img.img = mlx_new_image(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img.img)
		error(4);
	cub3d->img = &img;
	fill_image(cub3d); //map 그리고 하는 거
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	mlx_hook(cub3d->win, 2, 1L<<0, &handle_key, cub3d);
	mlx_loop_hook(cub3d->mlx, draw_minimap, cub3d);
	//mlx_hook(cub3d->win, 17, 0, 0, &exit_program, cub3d);
	mlx_hook(cub3d->win, 17, 0, &exit_program, cub3d);
	mlx_loop(cub3d->mlx);
}