#include "cub3d-bis.h"

void	init_data(t_data *data)
{
	
	// init_image(&data->image);
	init_map(&data->map);
	// init_minimap(&data->minimap);
	// init_player(&data->player);
	// init_ray(&data->ray);
	// init_texture(&data->texture);
	// init_color(&data->color);
	init_mlx_engine(data);
}