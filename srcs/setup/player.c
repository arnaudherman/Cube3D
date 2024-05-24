#include "cub3d-bis.h"

void set_direction(t_player *player, char direction)
{
    if (direction == 'N') {
        player->x_dir = 0;
        player->y_dir = -1;
        player->x_plane = 0.66;
        player->y_plane = 0;
    } else if (direction == 'E') {
        player->x_dir = 1;
        player->y_dir = 0;
        player->x_plane = 0;
        player->y_plane = 0.66;
    } else if (direction == 'S') {
        player->x_dir = 0;
        player->y_dir = 1;
        player->x_plane = -0.66;
        player->y_plane = 0;
    } else if (direction == 'W') {
        player->x_dir = -1;
        player->y_dir = 0;
        player->x_plane = 0;
        player->y_plane = -0.66;
    }
}

t_player	*allocate_player(void)
{
	t_player *player;

	if (!(player = (t_player *)calloc(sizeof(t_player), 1)))
		return (NULL);
	player->x_pos = 0.0;
	player->y_pos = 0.0;
	// TO DO : GO recup la directon N E S W
	// N : x = 0, y = 1;
	// E : x = 1, y = 0;
	// S : x = 0, y = -1;
	// W : x = -1, y = 0;
	player->direction = 'N';
	player->x_dir = 0.0;
	player->y_dir = 0.0;
	player->x_plane = 0.0;
	player->y_plane = 0.0;
	player->x_move = 0.0;
	player->y_move = 0.0;
	player->speed = 0.0;
	player->angle = 0.0;
	player->fov = 0.0;
	player->rotate = 0;
	player->x_rotated = 0;
	player->y_rotated = 0;
	player->size = 0.0;
	player->color = 0;
	return (player);
}



int	init_player(t_player *player)
{
	// TO DO : GO recup la position de départ
	// set_position(player);
	player->x_pos = 110.0;
	player->y_pos = 110.0;
	set_direction(player, player->direction);
	player->x_dir = 0.0; // init by set_direction
	player->y_dir = 0.0; // init by set_direction
	player->x_plane = 0.0; // init by set_direction
	player->y_plane = 0.0; // init by set_direction
	player->x_move = 0.0;
	player->y_move = 0.0;
	player->speed = SPEED;
	player->angle = 0.0;
	player->fov = FOV;
	player->rotate = ROTATION;
	player->x_rotated = 0;
	player->y_rotated = 0;

	player->size = 14;
	player->color = 0x992800;	
	return 0;
}
