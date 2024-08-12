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