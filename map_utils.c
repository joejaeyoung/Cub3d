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
