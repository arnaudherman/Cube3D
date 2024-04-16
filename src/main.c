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

	// TO DO : Initialisation de la fenêtre MLX
	// mlx_init create a xvar struct and return a pointer to it;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return 1;

	// TO DO : Create a new window ; read from an image (PNG format leaks memory)
	data.win_ptr = mlx_new_window(data.mlx_ptr, (MAP_WIDTH + 1) * TILE_SIZE, (MAP_HEIGHT + 1) * TILE_SIZE, "Cub3D");
    if (data.win_ptr == NULL)
	{
		// TO DO : destroy window ? display ? close ? mlx_destroy_display(mlx_ptr);
		return 1;
	}
	
	// TO DO : Initialize game data : the map, player, textures, etc.
    // init_game(&data);
	// init_map(&data);
	// init_player(&data);
	// init_textures(&data);
	
	// TO DO : delete because already one image ? 
	// img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img.win_width, &img.win_height);
	// img.img = mlx_new_image(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE);

	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

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