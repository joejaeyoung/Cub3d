#include "Cub3d.h"

void	print_field(t_field *field)
{
	t_field *tmp = field;
	int	i = 0;
	while(tmp) {
		if (i < 10)
			printf("%2d : %2d :", i, tmp->height);
		else
			printf("%d : %d :", i, tmp->height);
		for(int j = 0; j < tmp->line_num; j++) {
			if (tmp->line[j].value >= 0)
				printf("%2d", tmp->line[j].value);
			else
				printf("%d", tmp->line[j].value);
		}
		printf("\n");
		tmp = tmp -> next;
		i++;
	}
}

void	print_array_map(t_cub3d *cub3d)
{
	for(int i = 0; i < cub3d->map.map_height; i++) {
		for(int j = 0; j < cub3d->map.max_width; j++) {
			printf("%d ", cub3d->map.array_map[i][j]);
		}
		printf("\n");
	}
}