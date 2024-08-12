#include "Cub3d.h"

int	parse_map_texture_north(t_cub3d *cub3d, char *str)
{
	char	**splited_str;
	int		idx;

	idx = 0;
	if (ft_strncmp("NO", str, 2) == SUCCESS)
	{
		splited_str = ft_split(str, ' ');
		while(splited_str[idx])
			idx++;
		if (idx != 2)
			error(6);
		cub3d->map.texture.north_texture = ft_strdup(splited_str[1]);
		free_second_char_arr(splited_str);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_south(t_cub3d *cub3d, char *str)
{
	char	**splited_str;
	int		idx;

	idx = 0;
	if (ft_strncmp("SO", str, 2) == SUCCESS)
	{
		splited_str = ft_split(str, ' ');
		while(splited_str[idx])
			idx++;
		if (idx != 2)
			error(6);
		cub3d->map.texture.south_texture = ft_strdup(splited_str[1]);
		free_second_char_arr(splited_str);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_west(t_cub3d *cub3d, char *str)
{
	char	**splited_str;
	int		idx;

	idx = 0;
	if (ft_strncmp("WE", str, 2) == SUCCESS)
	{
		splited_str = ft_split(str, ' ');
		while(splited_str[idx])
			idx++;
		if (idx != 2)
			error(6);
		cub3d->map.texture.west_texture = ft_strdup(splited_str[1]);
		free_second_char_arr(splited_str);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_east(t_cub3d *cub3d, char *str)
{
	char	**splited_str;
	int		idx;

	idx = 0;
	if (ft_strncmp("EA", str, 2) == SUCCESS)
	{
		splited_str = ft_split(str, ' ');
		while(splited_str[idx])
			idx++;
		if (idx != 2)
			error(6);
		cub3d->map.texture.east_texture = ft_strdup(splited_str[1]);
		free_second_char_arr(splited_str);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture(t_cub3d *cub3d, char *str)
{
	return (parse_map_texture_north(cub3d, str) && parse_map_texture_south(cub3d, str) && \
		parse_map_texture_west(cub3d, str) && parse_map_texture_east(cub3d, str));
}
