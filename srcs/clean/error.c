#include "cub3d-bis.h"

// void	ft_error(char *error)
// {
// 	ft_putendl_fd(error, 2);
// 	exit(-1);
// }

int err(char *str)
{	
	while (*str)
		write(2, str++, 1);
	return 1;
}