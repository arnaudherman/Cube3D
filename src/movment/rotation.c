#include "cub3d.h"

static int	rotate(t_data *data, double rotation_speed)
{
	t_player	*player;
	double		tmp;

	player = &data->player;
	tmp = player->x_dir;
	player->x_dir = player->x_dir * cos(rotation_speed) - player->y_dir * sin(rotation_speed);
	player->y_dir = tmp * sin(rotation_speed) + player->y_dir * cos(rotation_speed);
	tmp = player->x_plane;
	player->x_plane = player->x_plane * cos(rotation_speed) - player->y_plane * sin(rotation_speed);
	player->y_plane = tmp * sin(rotation_speed) + player->y_plane * cos(rotation_speed);
	return (1);
}

int	player_rotation(t_data *data, double rotation_direction)
{
	int		movement;
	double	rotation_speed;

	movement = 0;
	rotation_speed = ROTATION * rotation_direction;
	movement += rotate(data, rotation_speed);
	return (movement);
}