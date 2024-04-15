#include "cub3d.h"

static bool	is_valid_wall_collision_position(t_data *data, double x, double y)
{
	if (data->map.map2d[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_map_position(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map.w_map - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map.h_map -0.25)
		return (false);
	return (true);
}

// static bool	is_valid_pos(t_data *data, double x, double y)
// {
// 	if (!BONUS && is_valid_pos_in_map(data, x, y))
// 		return (true);
// 	if (BONUS && is_valid_pos_wall_collision(data, x, y))
// 		return (true);
// 	return (false);
// }

bool	is_valid_move(t_data *data, double new_x, double new_y)
{
	if (is_valid_pos(data, new_x, data->player.y_pos))
	{
		data->player.x_pos = new_x;
		return (false);
	}
	if (is_valid_pos(data, data->player.x_pos, new_y))
	{
		data->player.y_pos = new_y;
		return (false);
	}
	return (true);
}
