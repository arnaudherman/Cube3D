#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

	
int	main(int ac, char **av)
{
	t_data	data;

	// 1) CHECKER
	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");

	// 2) INITIALISER
	// Main init function globale qui init la structre t_data
	// + call toutes les fonctions d'init dans cette fonction
	init_data(&data);

	// ???) TO DO : parser les args	

	// RENDERER
	// create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	// LISTENER
	event_listener(&data);

	// LOOPER
	mlx_loop(data.mlx_ptr);
	
	// CLEANER
	// clean_all(&data);

	return (0);
}

