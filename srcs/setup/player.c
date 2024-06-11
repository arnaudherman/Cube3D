#include "cub3d.h"

t_player	*allocate_player(void)
{
	t_player *player;

	if (!(player = (t_player *)calloc(sizeof(t_player), 1)))
		return (NULL);
	return (player);
}

int	init_player(t_player *player)
{
		player->x_pos = 84;
		player->y_pos = 104;
		player->speed = SPEED;
		player->fov = FOV;
		player->rotate = ROTATION;
		player->direction = 'N';
		player->angle = 2.0f;
		player->x_dir = 1;
		player->y_dir = 0; 
		player->size = 10;
		player->color = 0x992800;
		return 0;
}
