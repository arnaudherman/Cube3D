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
	
	// PARSE ARGS	TO DO : ???) 

	// RAYCASTING

	// LOOP
	// 0x60300001abf0
	// mlx_key_hook(data->mlx.mlx_win_ptr, event_listener, &data);
	// 0x60300001abf0
	loop(data);

	// CLEAN
	free_all(data);

	return (0);
}
	
	// raycasting(game, game->player, game->window, game->ray);
	// mlx_hook(game->window->win_ptr, KEY_PRESS, 1L << 0, key_press, game);
	// mlx_hook(game->window->win_ptr, KEY_RELEASE, 1L << 1, key_release, game);
	// mlx_hook(game->window->win_ptr, 17, 1L << 17, destroy_window, game);
	