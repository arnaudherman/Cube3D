#include "cub3d-bis.h"

// Handle key press events && exit game
void	loop(t_data *data)
{
	mlx_hook(data->mlx.mlx_win_ptr, KEY_PRESS, 1L << 0, key_press, data);
	mlx_hook(data->mlx.mlx_win_ptr, KEY_RELEASE, 1L << 1, key_release, data);
	mlx_hook(data->mlx.mlx_win_ptr, 17, 1L << 17, exit_game, data);
	mlx_loop_hook(data->mlx.mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx.mlx_ptr);
}
