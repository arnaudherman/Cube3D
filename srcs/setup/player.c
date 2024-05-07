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
		// TO DO : GO recup la position de départ
		// set_position(player);
		player->x_pos = 240;
		player->y_pos = 240;
		player->speed = SPEED;
		player->fov = FOV;
		player->rotate = ROTATION;
		// TO DO : GO recup la directon N E S W
		// player->direction = get_direction(player);
		player->direction = 'N';
		// set_direction function's gonna init following values
		// set_direction(player); // from direction.c
		player->angle = 2.0f;
		player->x_dir = 1;
		player->y_dir = -1; 
		player->x_plane = 0.66;
		player->y_plane = 0.66;
		player->size = 24;
		player->color = 0x992800;
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