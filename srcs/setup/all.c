#include "cub3d-bis.h"

int	init_data(t_data *data)
{
	
	init_image(&data->image);
	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}
	// init_minimap(&data->minimap);
	init_player(&data->player);
	// init_ray(&data->ray);
	// init_texture(&data->texture);
	// init_color(&data->color);
	if (init_mlx_engine(data) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}
	return (0);
}