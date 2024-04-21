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

	// TO DO : delete because already one image ? 
	// img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img.win_width, &img.win_height);
	// img.img = mlx_new_image(mlx_ptr, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE);

	// GET THE IMAGE ADRESS
	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);