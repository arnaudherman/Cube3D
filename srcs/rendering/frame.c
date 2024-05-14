#include "cub3d-bis.h"

// Use mlx_put_image_to_window() with a recycled image that you have cleared
// to display the image on the window instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);
	// mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);

	// draw_world();
	draw_map(data->map2d, &data->map);
	draw_player(data->map2d, data->player);
	key_move(data);
	raycasting(data);
	// draw_wall(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->map2d->img, 0, 0);
	return (0);
}