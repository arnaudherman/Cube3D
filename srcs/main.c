#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

// TO DO free all allocated structs when not needed anymroe
int	main(int ac, char **av) 
{
	t_data	*data;

	// Use sleep() to test leaks with Instrument
	// sleep(10);

	// CHECK
	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");
	data = malloc(sizeof(t_data));

	// INIT
	if (init_default_all(data) != 0) {
        perror("Failed to init_default_all in main\n");
        return -1;
    }

	if (init_custom_all(data) != 0) {
        perror("Failed to init_custom_all in init_default_all\n");
        return -1;
    }

	printf("after init_cutom_all, player->x_pos is : %f\n",  data->player->x_pos);
	// player->x_pos is : 73896


	// mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.mlx_win_ptr, data.image.img, 0, 0);
	
	// PARSE ARGS	TO DO : ???) 

	// RENDER
	mlx_loop_hook(data->mlx.mlx_ptr, render_next_frame, data);

	// LISTENER
	// event_listener(&data);

	// LOOP
	mlx_loop(data->mlx.mlx_ptr);
	
	// CLEAN
	free_all(data);

	return (0);
}

