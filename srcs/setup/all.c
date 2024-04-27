#include "cub3d-bis.h"

int	init_all(t_data *data)
{
	// Handle Image
	init_image(&data->image);
	data->image.img = mlx_new_image(&data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->image.img == NULL) {
        perror("Failed to create image\n");
        return 1;
    }
	data->image.addr = (int *)mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel,
			&data->image.line_length, &data->image.endian);

	// Handle Map
	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	// Handle other structs
	// init_minimap(&data->minimap);
	// init_ray(&data->ray);
	// init_texture(&data->texture);
	// init_color(&data->color);

	// Handle MLX
	if (init_mlx_engine(data) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}
	return (0);
}
