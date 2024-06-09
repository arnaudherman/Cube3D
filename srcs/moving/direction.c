#include "cub3d.h"

static void	set_east_west(t_player *player)
{
	if (player->direction == 'E')
	{
		player->angle = 0.0f; // East
		player->x_dir = 1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = 0.66;
	}
	else if (player->direction == 'W')
	{
		player->angle = M_PI; // 180 degrés, ou π radians = West
		player->x_dir = -1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = -0.66;
	}
	else
		return ;
}

static void	set_north_south(t_player *player)
{
	if (player->direction == 'N')
	{
		player->angle = M_PI / 2.0f; // Nord = 90 degrees, or π/2 radians
		player->x_dir = 0;
		player->y_dir = 1;
		player->x_plane = 0.66;
		player->y_plane = 0;
	}
	else if (player->direction == 'S')
	{
		player->angle = 3 * M_PI / 2.0f; // Sout = 270 degrés, ou 3π/2 radians
		player->x_dir = 0;
		player->y_dir = -1;
		player->x_plane = -0.66;
		player->y_plane = 0;
	}
	else
		return ;
}

void	set_direction(t_player *player)
{
	set_north_south(player);
	set_east_west(player);
}
