#include "cub3d.h"
#include "cub3d.h"

t_player	*allocate_player(void)
{
	t_player	*player;

	player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!player)
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
	player->angle = 0;
	player->x_dir = 1;
	player->y_dir = 0;
	player->size = 10;
	player->color = 0x992800;
	player->x_center = 0;
	player->y_center = 0;
	player->global_x = 0;
	player->global_y = 0;
	player->local_x = 0;
	player->local_y = 0;
	player->x = 0;
	player->y = 0;
	player->x_start = 0;
	player->y_start = 0;
	player->x_end = 0;
	player->y_end = 0;
	return (0);
}
