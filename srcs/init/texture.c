#include "cub3d-bis.h"
// USING void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
void	init_texture(t_data *data)
{
	data->texture.NO = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.NO, data->win_height, data->win_height);
	data->texture.SO = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.SO, data->win_height, data->win_height);
	data->texture.WE = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.WE, data->win_height, data->win_height);
	data->texture.EA = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.EA, data->win_height, data->win_height);
	data->texture.found = 0;
	data->texture.size = TEXTURE;
}

