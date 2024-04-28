#include "cub3d-bis.h"

int	draw_player(t_data *data)
{
	draw_square(&data, data->player.x_pos, data->player.y_pos, data->player.color);
	return 0;
}
