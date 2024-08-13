#include "Cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	is_valid_input(argc, argv);
	cub3d.map.field = NULL;
	parse_map(&cub3d, argv[1]);
	if (is_valid_field(&cub3d) == FAIL || cub3d.map.field == NULL || is_valid_player(&cub3d))\
	{
		printf("is not valid map\n");
		//print_field(cub3d.map.field);
	} 
	else
	{
		//printf("!!!!!!!!!!!!!!!!!!!!!!!!!11\n");
		print_array_map(&cub3d);
		make_it_3d(&cub3d);
	}
	free_map(&cub3d);
	free_texture(&cub3d);
}
