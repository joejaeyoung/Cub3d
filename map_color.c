#include "Cub3d.h"

void	parse_color(t_color *color, char **str)
{
	int		idx;

	idx = 0;
	while(str[idx])
		idx++;
	if (idx != 4)
		error(5);
	color->r = ft_atoi(str[1]);
	color->g = ft_atoi(str[2]);
	color->b = ft_atoi(str[3]);
	color->color = (color -> r << 16 | color->g << 8 | color->b);
	//printf("r : %d, g : %d, b : %d\n", color->r, color->g, color->b);
	if (!ft_isrgb(color->r) || !ft_isrgb(color->g) || !ft_isrgb(color->b))
		error(5);
	free_second_char_arr(str);
}

int	parse_map_color(t_cub3d *cub3d, char *str)
{
	char	**splited_str;

	if (str[0] == 'F')
	{
		splited_str = ft_split_str(str, " ,");
		parse_color(&(cub3d->map.floor_color), splited_str);
		return (SUCCESS);
	}
	if (str[0] == 'C')
	{
		splited_str = ft_split_str(str, " ,");
		parse_color(&(cub3d->map.ceiling_color), splited_str);
		return (SUCCESS);
	}
	return (FAIL);
}
