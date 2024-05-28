#include "cub3d-bis.h"

// Use mlx_put_image_to_window() with a recycled image that you have cleared
// to display the image on the window instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	// Clear previous image
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);

	// Clear previous frame
    memset(data->world->addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * (data->world->bits_per_pixel / 8));

	draw_map(data->map2d, &data->map);
	key_move(data);
	draw_player(data->map2d, data->player);
	// draw_player(data->map2d, data->player, data->ray);
	draw_world_bg(data->world, 0x0057B8);
	// shoot_rays(data);
	raycasting(data->player, data);
	
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->world->img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->map2d->img, 20, 20);
	
	return (0);
}