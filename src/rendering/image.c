#include "cub3d-bis.h"

// mlx_init create a xvar struct and return a pointer to it;

int	my_mlx_init(t_data *data)
{

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


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

	// TO DO : delete because already one image ? 
	// img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img.win_width, &img.win_height);
	// img.img = mlx_new_image(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE);

// GET THE IMAGE ADRESS
	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);