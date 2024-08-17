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
				get_user_direction(cub3d, field->line[idx].direction);
			}
			idx++;
		}
		field = field->next;
	}
	if (num != 1)
		return (FAIL);
	return (SUCCESS);
}
