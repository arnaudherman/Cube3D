#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

// L'offset mémoire pour un pixel à une certaine position (x, y) dans l'image
// y * line_length : cela détermine la position verticale dans l'image en prenant en compte la longueur de la ligne.
// x * (bits_per_pixel / 8) : cela détermine la position horizontale en prenant en compte le nombre de bits par pixel et le divisant par 8 pour obtenir le nombre d'octets.
// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	init()
// {
// 	glClearColor(0.3, 0.3, 0.3, 0);
// 	gluOrtho2D(0, 1920, 1080, 0);
// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// ft_bzero(&data, sizeof(t_data));
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

// clear and free
// mlx_destroy_display(mlx);
// free(mlx);


// TO DO big function for mlx
// TO DO big function for player
int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_data img;
    t_player player;
	// char	*relative_path = "./test.xpm";

	// 1) Initialisation de la fenêtre MLX
	// mlx_init create a xvar struct and return a pointer to it;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return 1;

	// Create a new window ; read from an image (PNG format leaks memory)
    mlx_win_ptr = mlx_new_window(mlx_ptr, TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT, "Cub3D");
    if (mlx_win_ptr == NULL)
	{
		// mlx_destroy_display(mlx_ptr);
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
    player.x_pos_px = 100; // Position x initiale du joueur
    player.y_pos_px = 100; // Position y initiale du joueur
    player.speed = 5; // Vitesse de déplacement du joueur

	// 4) Draw map
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // TO DO : remove red dot
	draw_map(mlx_ptr, mlx_win_ptr);

	// 5) Draw player
	draw_player(&img, &player); // Dessiner le joueur sur la carte
	// mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);

	// 6) player movement
	// Attacher la fonction de gestion des touches au hook clavier de la fenêtre MLX
    mlx_key_hook(img.win_ptr, key_hook, &player);

	// 7) main loop
	mlx_loop(mlx_ptr);

	// // Cleanup resources
    // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
    // mlx_destroy_display(mlx_ptr);
	
	return (0);
}