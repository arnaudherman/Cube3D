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

	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");
	data = malloc(sizeof(t_data));

	if (init_default_all(data) != 0) {
        perror("Failed to init_default_all in main\n");
        return -1;
    }

	if (init_custom_all(data) != 0) {
        perror("Failed to init_custom_all in init_default_all\n");
        return -1;
    }

    // init_textures(&data->texture, data->mlx.mlx_ptr);
	// WTF ??? Assurez-vous que `data` contient toutes les informations nécessaires
	// data->texture = &texture;
	print_ray_info(&data->ray);
	printf("test\n");
	loop(data);

	free_all(data);

	return (0);
}
