#include "cub3d-bis.h"

static int	up(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x_pos + data->player.x_dir * SPEED;
	new_y = data->player.y_pos + data->player.y_dir * SPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	down(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x_pos - data->player.x_dir * SPEED;
	new_y = data->player.y_pos - data->player.y_dir * SPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x_pos + data->player.y_dir * SPEED;
	new_y = data->player.y_pos - data->player.x_dir * SPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x_pos - data->player.y_dir * SPEED;
	new_y = data->player.y_pos + data->player.x_dir * SPEED;
	return (is_valid_move(data, new_x, new_y));
}

int	move(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.y_move == 1)
		moved += up(data);
	if (data->player.y_move == -1)
		moved += down(data);
	if (data->player.x_move == -1)
		moved += left(data);
	if (data->player.x_move == 1)
		moved += right(data);
	if (data->player.rotate != 0)
		moved += player_rotation(data, data->player.rotate);
	return (moved);
}