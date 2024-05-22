#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

	// Use sleep() to test leaks with Instrument
	// sleep(10);

// TO DO free all allocated structs when not needed anymroe
int	main(int ac, char **av) 
{
	t_data	*data;

	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");
	data = malloc(sizeof(t_data));

	init_default_all(data);
	init_custom_all(data);

	loop(data);

	free_all(data);

	return (0);
}
