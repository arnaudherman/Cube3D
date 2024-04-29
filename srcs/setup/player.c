#include "cub3d-bis.h"

// Check effectué pour le player
// couleur ok
// size ok
// position ok
// struct init ok
// fonction draw ok
// mlx_loop_hook avec render_next_frame ok
// my_mlx_pixel_put ok
int	init_player(t_data *data)
{
		data->player.x_pos = MAP_WIDTH / 2;
		data->player.y_pos = MAP_HEIGHT / 2;
		data->player.x_move = 1;
		data->player.y_move = 1;
		data->player.x_dir = 0;
		data->player.y_dir = -1; 
		data->player.x_plane = 0.66;
		data->player.y_plane = 0.66;
		data->player.speed = SPEED;
		data->player.angle = 0;
		data->player.fov = FOV;
		data->player.rotate = ROTATION;
		// TO DO : GO recup la direction N E S W
		data->player.direction = 'N';
		data->player.size = 64;
		data->player.color = 0x7FFF00;
		data->player.has_moved = 0;
		return 0;
}

// TO DO : Global function for player
// int setup_player_ready(t_data *data)
// {
// 	init_player(&data);
// 	set_direction(&data);
// 	// draw_player(&data);
// 	return 0;
// }