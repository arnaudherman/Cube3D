#include "cub3d-bis.h"

// Use mlx_put_image_to_window() to display the image on the window
// instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);

	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);

	draw_map(data->image, &data->map);
	draw_player(data->image, data->player);
	key_move(data);
	// TO DO : remove double mlx_clear_window ??
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
	raycasting(data);
	// draw_wall(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);
	return (0);
}