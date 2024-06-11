#include "cub3d.h"

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

	// TO DO : activate later aligator
	if (ac != 2) {
        perror("There must be precisely 2 arguments\n");
        return EXIT_FAILURE;
    }

	data = malloc(sizeof(t_data));
    if (!data) {
        fprintf(stderr, "Failed to malloc data in main\n");
        exit(EXIT_FAILURE);
    }

	if (init_default_all(data) != 0) {
        perror("Failed to init_default_all in main\n");
        return -1;
    }
	if (init_custom_all(data) != 0) {
        perror("Failed to init_custom_all in init_default_all\n");
        return -1;
    }
	
	printf("PATATAS BRAVAS : map->w_map = %d, map->h_map = %d\n", data->map.w_map, data->map.h_map);

	// TO DO : activate later aligator
	if (parsing(av[1], data) != 0)
	{
		perror("Parsing failed sorry I'm out!\n");
		return -1;
	}
	
	init_map2d(data->map2d, &data->mlx, data->map.x_map, data->map.y_map);

	// TO DO : delete later cause gonna be in parsing
	init_textures(data, &data->mlx);

	// DEBUG HERE : map->w_map = 95434556, map->h_map = 95434560
	loop(data);
	
	free_all(data);

	return (0);
}
