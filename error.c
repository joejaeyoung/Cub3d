#include "Cub3d.h"

void	error(int error_num)
{
	if (error_num == 2)
		ft_putendl_fd("Error\nWrong input: usage: ./Cub3d *.cub", STDERR_FILENO);
	else if (error_num == 3)
		ft_putendl_fd("Error\nFile open error", STDERR_FILENO);
	else if (error_num == 4)
		ft_putendl_fd("Error\nMalloc fail", STDERR_FILENO);
	else if (error_num == 5)
		ft_putendl_fd("Error\nWrong rgb value", STDERR_FILENO);
	else if (error_num == 6)
		ft_putendl_fd("Error\nWrong texture value", STDERR_FILENO);
	else if (error_num == 7)
		ft_putendl_fd("Error\nPlayer is not one", STDERR_FILENO);
	else if (error_num == 8)
		ft_putendl_fd("Error\nMlx error", STDERR_FILENO);
	else if (error_num == 9)
		ft_putendl_fd("Error\n,Player direction is wrong", STDERR_FILENO);
	exit(error_num);
}