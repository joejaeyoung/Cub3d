#include "Cub3d.h"

void	is_valid_input(int argc, char *argv[])
{
	int	len;
	int	fd;

	//인자수 체크
	if (argc != 2)
		error(2);

	//파일 확장자 체크
	len = ft_strlen(argv[1]);
	if (ft_strcmp(argv[1] + len - 4, ".cub") != SUCCESS)
		error(2);

	//존재하는 파일인지 체크
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(3);
	else
		close(fd);
}
