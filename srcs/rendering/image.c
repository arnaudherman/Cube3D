#include "cub3d-bis.h"

// L'offset mémoire pour un pixel à une certaine position (x, y) dans l'image
// y * line_length : cela détermine la position verticale dans l'image en prenant en compte la longueur de la ligne.
// x * (bits_per_pixel / 8) : cela détermine la position horizontale en prenant en compte le nombre de bits par pixel et le divisant par 8 pour obtenir le nombre d'octets.
// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// // mlx_init create a xvar struct and return a pointer to it;
// int	my_mlx_init(t_data *data)
// {

// 	data->mlx_ptr = mlx_init();
// 	if (data->mlx_ptr == NULL)
// 		return 1;

// 	// TO DO : Create a new window ; read from an image (PNG format leaks memory)
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, (MAP_WIDTH + 1) * TILE_SIZE, (MAP_HEIGHT + 1) * TILE_SIZE, "Cub3D");
    
// 	// TO DO : create destroy function
// 	// if (data->win_ptr == NULL)
// 	// {
// 	// 	mlx_destroy_display(data->mlx_ptr); // Clean up
// 	// 	return 1;
// 	// }

// 	 // Get image address
//     data->image.addr = mlx_get_data_addr(data->image.img, &(data->image.bits_per_pixel), &(data->image.line_length),
//                                          &(data->image.endian));
    
//     // Example usage of my_mlx_pixel_put
//     my_mlx_pixel_put(&data->image, 5, 5, 0x00FF0000);

//     // Put image to window
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 0, 0);

//     // Enter the event loop
//     mlx_loop(data->mlx_ptr);

//     return 0;
// }

	// TO DO : delete because already one image ? 
	// img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img.win_width, &img.win_height);
	// img.img = mlx_new_image(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE);

// GET THE IMAGE ADRESS
	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);