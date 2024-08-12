#include "Cub3d.h"

int	check_prev_field(t_field *prev_field, int idx)
{
	if (prev_field->line[idx].value != 1 && prev_field->line[idx].value != -1)
	{
		printf("%d:%dis_valid_point check faild 1\n", prev_field->height, idx);
		return (FAIL);
	}
	if (idx - 1 >= 0 && (prev_field->line[idx - 1].value != 1 && prev_field->line[idx - 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", prev_field->height, idx);
		return (FAIL);
	}
	if (idx + 1 < prev_field->line_num && (prev_field->line[idx + 1].value != 1 && prev_field->line[idx + 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", prev_field->height, idx);
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_next_field(t_field *next_field, int idx)
{
	if (next_field->line[idx].value != 1 && next_field->line[idx].value != -1)
	{
		printf("%d:%dis_valid_point check faild 1\n", next_field->height, idx);
		return (FAIL);
	}
	if (idx - 1 >= 0 && (next_field->line[idx - 1].value != 1 && next_field->line[idx - 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", next_field->height, idx);
		return (FAIL);
	}
	if (idx + 1 < next_field->line_num && (next_field->line[idx + 1].value != 1 && next_field->line[idx + 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", next_field->height, idx);
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_current_field(t_field *field, int idx)
{
	if (idx - 1 >= 0 && (field->line[idx - 1].value != 1 && field->line[idx - 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", field->height, idx);
		return (FAIL);
	}
	if (idx + 1 < field->line_num && (field->line[idx + 1].value != 1 && field->line[idx + 1].value != -1))
	{
		printf("%d:%dis_valid_point check faild 1\n", field->height, idx);
		return (FAIL);
	}
	return (SUCCESS);
}
