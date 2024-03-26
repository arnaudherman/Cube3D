

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		ft_error(ERROR_NBR_ARG);
	ft_bzero(&data, sizeof(t_data));
	if (!parsing(argv, &data))
		return (0);
}
