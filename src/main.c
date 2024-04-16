#include "cub3d-bis.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }


int	main(int ac, char **av)
{
	t_data 	data;

	// 0) Check error
	if (ac != 2)
		perror("There must be precisely 2 arguments\n");

	// TO DO : FUNCTION to init t_data ; (t_data *)malloc(sizeof(t_data));
	// init_data(&data);

	// TO DO : parser les args

	// Initialisation de la fenêtre MLX 
	my_mlx_init(&data);
	
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
	mlx_loop(data.mlx_ptr);

	// TO DO ? Cleanup resources
    // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
    // mlx_destroy_display(mlx_ptr);
	
	return (0);
}