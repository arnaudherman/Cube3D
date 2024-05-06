#include "cub3d-bis.h"

// Use mlx_put_image_to_window() to display the image on the window
// instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);


	// TO DO : delete not need in loop ?
	// draw_map(data->image, &data->map);
	// draw_player(data->image, data->player);

	// printf("data->player->x_pos : %f\n", data->player->x_pos);
	// printf("data->player->y_pos : %f\n", data->player->y_pos);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);

	draw_map(data->image, &data->map);
	draw_player(data->image, data->player);
	key_move(data);

	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);
	
	// TO DO : 
	// raycasting(game, game->player, game->window, game->ray);

	return (0);
}