#include "cub3d-bis.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }



// TO DO big function for mlx
// TO DO big function for player
int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	char 	**map;
	t_data 	data;
    t_player player;

	// TO DO : Where and how to ini t_data ; (t_data *)malloc(sizeof(t_data));

	// 1) Initialisation de la fenêtre MLX
	// mlx_init create a xvar struct and return a pointer to it;
	data.mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
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
    player.x_pos = 100; // Position x initiale du joueur
    player.y_pos = 100; // Position y initiale du joueur
    player.speed = 5; // Vitesse de déplacement du joueur

	// 4) Allouez et initialisez votre carte
    map = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    int i = 0;
    while (i < MAP_HEIGHT) {
        map[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char)); // +1 pour le caractère de fin de chaîne '\0'
        int j = 0;
        while (j < MAP_WIDTH) {
            // Initialiser votre carte selon votre logique (par exemple, '1' pour un mur, '0' pour vide, etc.)
            map[i][j] = '0'; // Par défaut, supposons que toutes les cases sont vides
            j++;
        }
        map[i][j] = '\0'; // Terminer la chaîne de caractères
        i++;
    }

	// 5) Draw map
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // TO DO : remove red dot
 	draw_map(data->mlx_ptr, data->win_ptr, player);

	// 6) Draw player
	// draw_player(&img, &player); // Dessiner le joueur sur la carte
	// mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);

	// 7) player movement
	// Attacher la fonction de gestion des touches au hook clavier de la fenêtre MLX
    // mlx_key_hook(img.win_ptr, key_hook, &player);

	// 8) Hook to catch event
	mlx_hook(data.win_ptr, 2, 1L<<0, close, &data);
	// 8) main loop
	mlx_loop(data.mlx_ptr);

	// // Cleanup resources
    // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
    // mlx_destroy_display(mlx_ptr);
	
	return (0);
}

// int main(void)
// {
//     void *mlx_ptr;
//     void *mlx_win_ptr;
// 	t_player player;

// 	 // Initialiser la position du joueur
//    	init_player(player);

//     // Initialisation de la fenêtre MLX
//     mlx_ptr = mlx_init();
//     if (mlx_ptr == NULL)
//         return 1;

//     // Créer une nouvelle fenêtre
//     mlx_win_ptr = mlx_new_window(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Map2D");
//     if (mlx_win_ptr == NULL)
//         return 1;

//     // Dessiner la carte
//     draw_map(mlx_ptr, mlx_win_ptr, player);

//     // Boucle MLX principale
//     mlx_loop(mlx_ptr);

//     return 0;
// }
