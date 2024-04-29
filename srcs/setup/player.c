#include "cub3d-bis.h"

int	init_player(t_data *data)
{
		data->player.x_pos = 1;
		data->player.y_pos = 1;
		data->player.x_move = 1;
		data->player.y_move = 1;
		data->player.x_dir = 1;
		data->player.y_dir = 1; 
		data->player.x_plane = 0;
		data->player.y_plane = 0;
		data->player.speed = SPEED;
		data->player.angle = 0;
		data->player.fov = FOV;
		data->player.rotate = ROTATION;
		// TO DO : GO recup la direction N E S W
		data->player.direction = 'N';
		// data->player.size = TILE_SIZE / 2;
		data->player.size = 50;
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