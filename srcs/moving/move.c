#include "cub3d.h"

int go_up(t_data *data)
{
    double x_new;
    double y_new;
	
	if (!player_wall_collision(&data->map, data->player->x_pos, data->player->y_pos + data->player->y_dir * SPEED))
	{
		y_new = data->player->y_pos + data->player->y_dir * SPEED;
		data->player->y_pos = y_new;
	}
    return 0;
}

int	go_left(t_data *data)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, data->player->x_pos - data->player->x_dir * SPEED, data->player->y_pos))
	{
		x_new = data->player->x_pos - data->player->x_dir * SPEED;
		data->player->x_pos = x_new;
	}
	return (0);
}

int	go_down(t_data *data)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, data->player->x_pos, data->player->y_pos - data->player->y_dir * SPEED))
	{
		y_new = data->player->y_pos - data->player->y_dir * SPEED;
		data->player->y_pos = y_new;
	}

	return (0);
}

int	go_right(t_data *data)
{
	double	x_new;
	double	y_new;

	if (!player_wall_collision(&data->map, data->player->x_pos + data->player->x_dir * SPEED, data->player->y_pos))
	{
		x_new = data->player->x_pos + data->player->x_dir * SPEED;
		data->player->x_pos = x_new;
	}

	return (0);
}

// pour connaître le nb total de mouvements effectués bro
// int	go_move(t_data *data)
// {
// 	int	go;

// 	go = 0;
	
// 	if (data->player->y_move == 1)
// 		go += go_up(data);
// 	if (data->player->x_move == -1)
// 		go += go_left(data);
// 	if (data->player->y_move == -1)
// 		go += go_down(data);
// 	if (data->player->x_move == 1)
// 		go += go_right(data);
// 	// if (data->player->rotate != 0)
// 	// 	go += go_rotate(data, data->player->rotate);
// 	return (go);
// }
