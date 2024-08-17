#include "Cub3d.h"

void	save_max_line_num(t_cub3d *cub3d)
{
	int	max_width;
	int	height;
	t_field *field;
	
	field = cub3d->map.field;
	height = 0;
	max_width = -1;
	while(field)
	{
		if (max_width < field->line_num)
			max_width = field->line_num;
		height++;
		field = field->next;
	}
	cub3d->map.max_width = max_width;
	cub3d->map.map_height = height;
	printf("max width : %d, map_height : %d\n", cub3d->map.max_width, cub3d->map.map_height);
}

void make_field_rectangle(t_cub3d *cub3d)
{
	t_field	*field;

	field = cub3d->map.field;
	while(field)
	{
		if (field->line_num != cub3d->map.max_width)
			field->line = ft_realloc(field->line, field->line_num, cub3d->map.max_width);
		field->line_num = cub3d->map.max_width;
		field = field->next;
	}
}

void	make_field_array(t_cub3d *cub3d)
{
	t_field	*tmp;
	int		height;
	int		width;
	int		max_width;

	max_width = cub3d->map.max_width;
	cub3d->map.array_map = (int **)malloc(sizeof(int *) * cub3d->map.map_height);
	tmp = cub3d->map.field;
	height = -1;
	while(++height < cub3d->map.map_height) {
		width = -1;
		cub3d->map.array_map[height] = (int *)malloc(sizeof(int) * max_width);
		while(++width < max_width)
			cub3d->map.array_map[height][width] = tmp->line[width].value;
		tmp = tmp -> next;
	}
}

void	get_tile_len(t_cub3d *cub3d)
{
	int	tile_width;
	int	tile_height;

	tile_width = (WINDOW_WIDTH) / cub3d->map.max_width;
	tile_height = (WINDOW_HEIGHT) / cub3d->map.map_height;
	if (tile_width < tile_height)
		cub3d->map.tile_len = tile_width;
	else
		cub3d->map.tile_len = tile_height;
}
