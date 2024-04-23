// #include "cub3d-bis.h"
#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

	
int	main(int ac, char **av)
{
	t_data	data;

	// 1) CHECK ARGS
	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");

	// 2) INIT ALL DATA
	// Main init function globale qui init la structre t_data
	// + call toutes les fonctions d'init dans cette fonction
	init_data(&data);

	// ???) TO DO : parser les args	

	// 3) TO DO : LISTEN FOR INPUTS

	// 4) TO DO : RENDER IMAGES with hook to catch event
	// create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	// 	Main events loop
	mlx_loop(data.mlx_ptr);
	
	// 5) TO DO ? Cleanup resources
	// mlx_destroy_window(mlx_ptr, mlx_win_ptr);	
	// mlx_destroy_display(mlx_ptr);

	return (0);
}