#include "cub3d.h"
#include "cub3d.h"

int	go_up(t_data *data, int tile_size)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, tile_size, data->player->x_pos,
			data->player->y_pos - 1 * SPEED))
	{
		y_new = data->player->y_pos - 1 * SPEED;
		data->player->y_pos = y_new;
	}
	return (0);
}

int	go_left(t_data *data, int tile_size)
int	go_left(t_data *data, int tile_size)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, tile_size, data->player->x_pos
			- 1 * SPEED, data->player->y_pos))
	{
		x_new = data->player->x_pos - 1 * SPEED;
		data->player->x_pos = x_new;
	}
	return (0);
}

int	go_down(t_data *data, int tile_size)
int	go_down(t_data *data, int tile_size)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, tile_size, data->player->x_pos,
			data->player->y_pos + 1 * SPEED))
	{
		y_new = data->player->y_pos + 1 * SPEED;
		data->player->y_pos = y_new;
	}
	return (0);
}

int	go_right(t_data *data, int tile_size)
int	go_right(t_data *data, int tile_size)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, tile_size, data->player->x_pos
			+ 1 * SPEED, data->player->y_pos))
	{
		x_new = data->player->x_pos + 1 * SPEED;
		data->player->x_pos = x_new;
	}
	return (0);
}
