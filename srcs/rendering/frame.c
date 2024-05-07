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
	printf(" angle between frames : %f\n", data->player->angle);
	printf(" x_dir between frames : %lf\n", data->player->x_dir);
	printf(" y_dir between frames : %lf\n", data->player->y_dir);
	// TO DO : remove double mlx_clear_window ??
	// mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
	raycasting(data);
	// printf(" 1) x_pos : %f\n", data->player->x_pos);
	// printf(" 1) y_pos : %f\n", data->player->y_pos);

	// printf(" 2) x_dir : %f\n", data->player->x_dir);
	// printf(" 2) y_dir : %f\n", data->player->y_dir);

	// printf(" 3 ) x_plane : %f\n", data->player->x_plane);
	// printf(" 3 ) y_plane : %f\n", data->player->y_plane);

	// printf(" 4 ) Angle : %f\n", data->player->angle);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);
	
	// TO DO : 
	// raycasting(game, game->player, game->window, game->ray);

	return (0);
}