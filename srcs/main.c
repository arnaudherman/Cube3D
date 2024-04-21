// #include "cub3d-bis.h"
#include "cub3d-bis.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }


// int	main(int ac, char **av)
// {
// 	t_data 	data;

// 	// 0) Check error
// 	if (ac != 2)
// 		perror("There must be precisely 2 arguments\n");

// 	// TO DO : FUNCTION to init t_data ; (t_data *)malloc(sizeof(t_data));
// 	// init_data(&data);

// 	// TO DO : parser les args

// 	// Initialisation de la fenêtre MLX 
// 	my_mlx_init(&data);
	
// 	// TO DO : Initialize game data : the map, player, textures, etc.
//     // init_game(&data);
// 	// init_map(&data);
// 	// init_player(&data);
// 	// init_textures(&data);

// 	// TO DO : LISTEN FOR INPUTS

// 	// Render images with hook to catch event
// 	// TO DO : create function render_next_frame function to render images
// 	// int	render_next_frame(void *YourStruct);
// 	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

// 	// Main loop
// 	mlx_loop(data.mlx_ptr);

// 	// TO DO ? Cleanup resources
//     // mlx_destroy_window(mlx_ptr, mlx_win_ptr);
//     // mlx_destroy_display(mlx_ptr);
	
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int map2d[MAP_WIDTH][MAP_HEIGHT] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

	int rows = sizeof(map2d)/sizeof(map2d[0]);
	int columns = sizeof(map2d[0])/sizeof(map2d[0][0]);

	printf("rows: %d\n", rows);
	printf("columns: %d\n", columns);

	if (ac != 2)
		perror("There must be precisely 2 arguments\n");

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.image.img = mlx_new_image(mlx, 1920, 1080);
	img.image.addr = mlx_get_data_addr(img.image.img, &img.image.bits_per_pixel, &img.image.line_length,
								&img.image.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.image.img, 0, 0);
	mlx_loop(mlx);
}