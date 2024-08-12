#include "Cub3d.h"

int	is_valid_point(t_cub3d *cub3d, t_field *field, int idx)
{
	t_field *prev_field;
	t_field *next_field;

	prev_field = ft_lstfind_node(cub3d->map.field, field->height - 1);
	next_field = ft_lstfind_node(cub3d->map.field, field->height + 1);

	if (prev_field && (idx < prev_field->line_num))
		if (check_prev_field(prev_field, idx) == FAIL)
			return (FAIL);
	if (next_field && idx < next_field->line_num)
		if (check_next_field(next_field, idx) == FAIL)
			return (FAIL);
	if (field && idx - 1 >= 0 && idx  + 1 < field->line_num)
		if (check_current_field(field, idx) == FAIL)
			return (FAIL);
	return (SUCCESS);
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

int	is_valid_field(t_cub3d *cub3d)
{
	t_field	*field;
	int		idx;

	field = cub3d->map.field;
	while(field)
	{
		idx = 0;
		while(idx < field->line_num)
		{
			if (field->line[idx].value == -1)
			{
				if (is_valid_point(cub3d, field, idx) == FAIL) {

					return (FAIL);
				}
			}
			idx++;
		}
		field = field->next;
	}
	get_tile_len(cub3d);
	return (SUCCESS);
}

t_direction	get_user_direction(t_cub3d *cub3d, char c)
{
	if (c == 'N' || c == 'n')
	{
		cub3d->user.degree = 90;
		return (NORTH);
	}
	if (c == 'W' || c == 'w')
	{
		cub3d->user.degree = 180;
		return (WEST);
	}
	if (c == 'E' || c == 'e')
	{
		cub3d->user.degree = 0;
		return (EAST);
	}
	if (c == 'S' || c == 's')
	{
		cub3d->user.degree = 270;
		return (SOUTH);
	}
	return (NORTH);
}

int	is_valid_player(t_cub3d *cub3d)
{
	int	num;
	t_field	*field;
	int	idx;

	num = 0;
	field = cub3d->map.field;
	while(field)
	{
		idx = 0;
		while(idx < field->line_num)
		{
			if (field->line[idx].value == 2)
			{
				num++;
				cub3d->user.x = idx;
				cub3d->user.y = field->height;
				cub3d->user.direct = get_user_direction(cub3d, field->line[idx].direction);
			}
			idx++;
		}
		field = field->next;
	}
	if (num != 1)
		return (FAIL);
	return (SUCCESS);
}
