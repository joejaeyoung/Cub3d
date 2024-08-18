#include "Cub3d.h"

void	fill_square(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;

	j = -1;
	while(++j < (int)(1) * cub3d->map.tile_len / 10)
	{
		i = -1;
		while(++i < (int)(1) * cub3d->map.tile_len / 10)
			cub3d->img->addr[(int)(1 * WINDOW_WIDTH) * (y + j) + (x + i)] = color;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	tile_len;

	tile_len = cub3d->map.tile_len;
	x = cub3d->user.x * tile_len;
	y = cub3d->user.y * tile_len;
	for (int row = -(4) / 2; row <= (4) / 2; row++)
	{
		for (int col = -(4) / 2; col <= (4) / 2; col++)
		{
			cub3d->img->addr[(int)(1 * (WINDOW_WIDTH * (y + row))) + (x + col)] = 0x0000FF;
		}
	}
}

int	draw_minimap(t_cub3d *cub3d)
{
	int	count_h;
	int	count_w;
	t_field	*field;
	t_field *tmp;
	int	tile_len;

	tile_len = cub3d->map.tile_len;
	field = cub3d->map.field;
	count_h = -1;
	while ((field))
	{
		count_h++;
		count_w = -1;
		while(++count_w < field->line_num)
		{
			if (field->line[count_w].value == 1)
				fill_square(cub3d, (int)(1 * tile_len * count_w), (int)(1 * tile_len * count_h), 0xd2b48c);
			else if (field->line[count_w].value == -1)
				fill_square(cub3d, (int)(1 * tile_len * count_w), (int)(1 * tile_len * count_h), 0x000000);
			else if (field->line[count_w].value == 2)
			{
				fill_square(cub3d, (int)(1 * tile_len * count_w), (int)(1 * tile_len * count_h), 0xffffff);
				draw_player(cub3d);
			}
			else
				fill_square(cub3d, (int)(1 * tile_len * count_w), (int)(1 * tile_len * count_h), 0xffffff);
		}
		field = field -> next;
	}

	draw_ray(cub3d);
	return (0);
}
