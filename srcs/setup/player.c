#include "cub3d-bis.h"

// static void	default_player(t_player *player)
// {
//     player->x_pos = 0.0;
//     player->y_pos = 0.0;
//     player->x_move = 0;
//     player->y_move = 0;
//     player->x_dir = 0.0;
//     player->y_dir = 0.0;
//     player->x_plane = 0.0;
//     player->y_plane = 0.0;
//     player->speed = 0.0;
//     player->angle = 0.0;
//     player->fov = 0.0;
//     player->rotate = 0;
//     player->direction = '\0';
//     player->size = 0.0;
//     player->color = 0;
//     player->has_moved = 0;
// }

t_player *allocate_player() 
{
    t_player *player;
	
	player = malloc(sizeof(t_player));
    if (player == NULL) {
        perror("Allocation for player failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialiser les membres de la structure ici si nécessaire

    return player;
}

// Check effectué pour le player
// couleur ok
// size ok
// position ok
// struct init ok
// fonction draw ok
// mlx_loop_hook avec render_next_frame ok
// my_mlx_pixel_put ok

int	init_player(t_player *player)
{
		player->x_pos = MAP_WIDTH / 2;
		player->y_pos = MAP_HEIGHT / 2;
		player->x_move = 1;
		player->y_move = 1;
		player->x_dir = 0;
		player->y_dir = -1; 
		player->x_plane = 0.66;
		player->y_plane = 0.66;
		player->speed = SPEED;
		player->angle = 0;
		player->fov = FOV;
		player->rotate = ROTATION;
		// TO DO : GO recup la direction N E S W
		player->direction = 'N';
		player->size = 64;
		player->color = 0x7FFF00;
		player->has_moved = 0;
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