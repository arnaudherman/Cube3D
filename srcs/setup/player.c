#include "cub3d-bis.h"

t_player	*allocate_player(void)
{
	t_player *player;

	if (!(player = (t_player *)calloc(sizeof(t_player), 1)))
		return (NULL);
	// player->x_pos = 0.0;
	// player->y_pos = 0.0;
	// player->x_dir = 0.0;
	// player->y_dir = 0.0;
	// player->x_plane = 0.0;
	// player->y_plane = 0.0;
	// player->speed = 0.0;
	// player->angle = 0.0;
	// player->fov = 0.0;
	// player->rotate = 0;
	// player->direction = '0';
	// player->size = 0.0;
	// player->color = 0;
	return (player);
}

int	init_player(t_player *player)
{
		// Address of player->x_pos: 0x120a8
		player->x_pos = 250;
		player->y_pos = 250;
		player->x_dir = 1;
		player->y_dir = -1; 
		player->x_plane = 0.66;
		player->y_plane = 0.66;
		player->speed = SPEED;
		player->angle = 0;
		player->fov = FOV;
		player->rotate = ROTATION;
		// TO DO : GO recup la direction N E S W
		player->direction = 'N';
		player->size = 32;
		player->color = 0x7F0FFF;
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