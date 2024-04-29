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
	init_default_all(&data);
	printf("data->player.x_pos is : %d\n",  data.player.x_pos);
	printf("x_start is : %d\n",  data.player.x_pos);
	init_specific_all(&data);
	printf("data->player.x_pos is : %d\n",  data.player.x_pos);
	printf("x_start is : %d\n",  data.player.x_pos);

	// ???) TO DO : parser les args	

	// RENDERER
	// create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	// LISTENER
	// event_listener(&data);

	// LOOPER
	mlx_loop(data.mlx_ptr);
	
	// CLEANER
	// clean_all(&data);

	return (0);
}

