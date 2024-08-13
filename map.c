#include "Cub3d.h"

void	parse_map(t_cub3d *cub3d, char *filename)
{
	int	fd;
	int	height;
	char	*str;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error(3);

	while(1) {
		str = get_next_line(fd);
		if (!str)
			break;
		if (str[0] == '\0')
		{
			free(str);
			continue;
		}
		if (parse_map_texture(cub3d, str) && parse_map_color(cub3d, str))
		{
			ft_lstadd_back(&(cub3d->map.field), ft_lstnew_field(height, str));
			height++;
		}
		free(str);
		str = NULL;
	}
	save_max_line_num(cub3d);
	make_field_rectangle(cub3d);
	make_field_array(cub3d);
}

