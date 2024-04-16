#include "cub3d-bis.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }


int	main(int ac, char *av)
{
	t_data 	data;
    t_player player;

	// 0) Check error
	if (ac != 2)
		perror("There must be precisely 2 arguments\n");

	// TO DO : FUNCTION to init t_data ; (t_data *)malloc(sizeof(t_data));
	// init_data(&data);

	// 1) Initialisation de la fenêtre MLX
	// mlx_init create a xvar struct and return a pointer to it;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return 1;

	// Create a new window ; read from an image (PNG format leaks memory)
	data.win_ptr = mlx_new_window(data.mlx_ptr, (MAP_WIDTH + 1) * TILE_SIZE, (MAP_HEIGHT + 1) * TILE_SIZE, "Cub3D");
    if (data.win_ptr == NULL)
	{
		// TO DO : destroy window ? display ? close ? mlx_destroy_display(mlx_ptr);
		return 1;
	}
	
	// 2) Initialize game data (you may need to modify this according to your game structure)
    // For example, initializing the map, player position, textures, etc.
    // init_game(&data);
	
	// TO DO : delete because already one image ? 
	// img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img.win_width, &img.win_height);
	// img.img = mlx_new_image(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE);

	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(mlx, render_next_frame, YourStruct);

	// 3) Initialisation du joueur
	// init_player();

	// 4) Allouez et initialisez votre carte
    data.map.map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    int i = 0;
    while (i < MAP_HEIGHT) {
        data.map.map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char)); // +1 pour le caractère de fin de chaîne '\0'
        int j = 0;
        while (j < MAP_WIDTH) {
            // Initialiser votre carte selon votre logique (par exemple, '1' pour un mur, '0' pour vide, etc.)
            data.map.map2d[i][j] = '0'; // Par défaut, supposons que toutes les cases sont vides
            j++;
        }
        data.map.map2d[i][j] = '\0'; // Terminer la chaîne de caractères
        i++;
    }

	// 5) Draw map
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // TO DO : remove red dot
 	draw_map(data.mlx_ptr, data.win_ptr, player);

	// 6) Draw player
	// draw_player(&img, &player); // Dessiner le joueur sur la carte
	// mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);

	// 7) player movement
	// Attacher la fonction de gestion des touches au hook clavier de la fenêtre MLX
    // mlx_key_hook(img.win_ptr, key_hook, &player);

	// 8) Hook to catch event
	mlx_loop_hook(data.win_ptr, 2, 1L<<0, close, &data);
	// 9) main loop
	mlx_loop(data.mlx_ptr);

	// // Cleanup resources
    // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
    // mlx_destroy_display(mlx_ptr);
	
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	init_mlx(&data);
	// init_textures(&data);
	// print_controls();
	//render_images(&data);
	// listen_for_input(&data);
	// mlx_loop_hook(data.mlx_ptr, /*function to render images*/, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}