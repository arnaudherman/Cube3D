#include "cub3d-bis.h"

int	exit_game(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
}

void	clear_map(t_data *data)
{
	int	i;

}

void	clear_window(t_mlx *mlx)
{
	if (mlx->mlx_win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win_ptr);
	free(mlx);
}

void	clear_image(t_image *image, t_mlx *mlx)
{
	if (image->relative_path)
		free(image->relative_path);
	if (image->img)
		mlx_destroy_image(mlx->mlx_ptr, image->img);
	free(image);
}

// void	destroy_data(t_data *data)
// {
// 	free(data->keys);
// 	free(data->player);
// 	clear_map(data);
// 	clear_image(data->no_texture, data->mlx.mlx_win_ptr);
// 	clear_image(data->so_texture, data->mlx.mlx_win_ptr);
// 	clear_image(data->we_texture, data->mlx.mlx_win_ptr);
// 	clear_image(data->ea_texture, data->mlx.mlx_win_ptr);
// 	clear_image(data->sp_texture, data->mlx.mlx_win_ptr);
// 	clear_image(data->image, data->mlx.mlx_win_ptr);
// 	if (data->sprites_head)
// 		free_sprites(&data->sprites_head);
// 	free(data->sprites_head);
// 	clear_window(data->data->mlx.mlx_win_ptr);
// 	free(data);
// }