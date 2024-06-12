#include "cub3d.h"
#include "cub3d.h"

void	rotate_left(t_data *data)
{
	data->player->angle -= ROTATION;
	if (data->player->angle < 0.0)
		data->player->angle += 360.0;
	data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
	data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}

void	rotate_right(t_data *data)
{
	data->player->angle += ROTATION;
	if (data->player->angle >= 360.0)
		data->player->angle -= 360.0;
	data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
	data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}
