#include "Cub3d.h"

void	free_map(t_cub3d *cub3d)
{
	ft_lstclear(&cub3d->map.field);
}

void	free_texture(t_cub3d *cub3d)
{
	// if (cub3d->map.texture.north_texture)
	// 	free(cub3d->map.texture.north_texture);
	// if (cub3d->map.texture.south_texture)
	// 	free(cub3d->map.texture.south_texture);
	// if (cub3d->map.texture.west_texture)
	// 	free(cub3d->map.texture.west_texture);
	// if (cub3d->map.texture.east_texture)
	// 	free(cub3d->map.texture.east_texture);
	// cub3d->map.texture.north_texture = NULL;
	// cub3d->map.texture.south_texture = NULL;
	// cub3d->map.texture.west_texture = NULL;
	// cub3d->map.texture.east_texture = NULL;
}

void	free_second_char_arr(char **str)
{
	int	idx;
	int	i;

	idx = 0;
	i = -1;
	while(str[idx])
		idx++;
	while(++i < idx)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}
