#include "Cub3d.h"
#include <stdio.h>

int	*load_image_malloc(t_cub3d *cub3d, t_tmptex *img, int dir)
{
	int	x;
	int	y;
	int	*result;
	void *tmp_img;

	img->img = mlx_xpm_file_to_image(cub3d->mlx, "./textures/greystone.xpm", &img->width, &img->height);
	if (!img->img)
		(printf("%p\n", img->img), error(8));
	cub3d->map.texture[dir].width = img->width;
	cub3d->map.texture[dir].height = img->height;

	img->data = (int *)mlx_get_data_addr(img->img, &img->pixel_bits, &img->line_bytes, &img->endian);
	if (!img->data)
		error(8);
	result = (int *)malloc(sizeof(int) * (img->height * img->width));
	if (!result)
		error(4);
	y = -1;
	while(++y < img->height)
	{
		x = -1;
		while(++x < img->width)
			result[img->width * y + x] = img->data[img->width * y + x];
	}
	mlx_destroy_image(cub3d->mlx, img->img);
	printf("%d : image load 완료\n", dir);
	return (result);
}	

int	parse_map_texture_north(t_cub3d *cub3d, char *str)
{
	t_tmptex	tmp_tex;
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
		cub3d->map.texture[3].text_path = ft_strdup(splited_str[1]);
		cub3d->map.texture[3].width = 64;
		cub3d->map.texture[3].height = 64;
		free_second_char_arr(splited_str);
		cub3d->map.texture[3].texture = load_image_malloc(cub3d, &tmp_tex, 3);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_south(t_cub3d *cub3d, char *str)
{
	t_tmptex	tmp_tex;
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
		cub3d->map.texture[2].text_path = ft_strdup(splited_str[1]);
		cub3d->map.texture[2].width = 64;
		cub3d->map.texture[2].height = 64;
		free_second_char_arr(splited_str);
		cub3d->map.texture[2].texture = load_image_malloc(cub3d, &tmp_tex, 2);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_west(t_cub3d *cub3d, char *str)
{
	t_tmptex	tmp_tex;
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
		cub3d->map.texture[1].text_path = ft_strdup(splited_str[1]);
		cub3d->map.texture[1].width = 64;
		cub3d->map.texture[1].height = 64;
		free_second_char_arr(splited_str);
		cub3d->map.texture[1].texture = load_image_malloc(cub3d, &tmp_tex, 1);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture_east(t_cub3d *cub3d, char *str)
{
	t_tmptex	tmp_tex;
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
		cub3d->map.texture[0].text_path = ft_strdup(splited_str[1]);
		cub3d->map.texture[0].width = 64;
		cub3d->map.texture[0].height = 64;
		free_second_char_arr(splited_str);
		cub3d->map.texture[0].texture = load_image_malloc(cub3d, &tmp_tex, 0);
		return (SUCCESS);
	}
	return (FAIL);
}

int	parse_map_texture(t_cub3d *cub3d, char *str)
{
	return (parse_map_texture_north(cub3d, str) && parse_map_texture_south(cub3d, str) && \
		parse_map_texture_west(cub3d, str) && parse_map_texture_east(cub3d, str));
}
