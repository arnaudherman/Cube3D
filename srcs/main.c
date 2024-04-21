// #include "cub3d-bis.h"
#include "cub3d-bis.h"



	// TO DO : parser les args

	// Initialisation de la fenêtre MLX 
	// my_mlx_init(&data);
	
	// TO DO : Initialize game data : the map, player, textures, etc.
 	// init_game(&data);
	// init_map(&data);
	// init_player(&data);
	// init_textures(&data);

	// TO DO : LISTEN FOR INPUTS

	// Render images with hook to catch event
	// TO DO : create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	// Main loop
	// mlx_loop(data.mlx_ptr);

	// TO DO ? Cleanup resources
    // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
    // mlx_destroy_display(mlx_ptr);
	


int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		perror("There must be precisely 2 arguments\n");

	data = (t_data *)malloc(sizeof(t_data));
	// Function globale qui init la structre t_data
	// Appeler toutes les fonctions d'init dans cette fonction 
	init_data(&data);

	// TO DO : parser les args
	
	// TO DO : Initialize game data : the map, player, textures, etc.
	// init_game(&data);
	// init_map(&data);
	// init_player(&data);
	// init_textures(&data);

	// TO DO : LISTEN FOR INPUTS

	// Render images with hook to catch event
	// TO DO : create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	

	// TO DO ? Cleanup resources
	// mlx_destroy_window(mlx_ptr, mlx_win_ptr);	
	// mlx_destroy_display(mlx_ptr);

	return (0);
}