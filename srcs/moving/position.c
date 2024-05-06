#include "cub3d-bis.h"

// static bool	good_map_pos(t_data *data, double x, double y)
// {
// 	if (x < 0.25 || x >= data->map.w_map - 1.25)
// 		return (false);
// 	if (y < 0.25 || y >= data->map.h_map -0.25)
// 		return (false);
// 	return (true);
// }

// static bool	good_wall_pos(t_data *data, double x, double y)
// {
// 	if (data->map.map2d[(int)y][(int)x] == '0')
// 		return (true);
// 	return (false);
// }

// static bool	good_pos(t_data *data, double x, double y)
// {
// 	if (good_wall_pos(data, x, y))
// 		return (true);
// 	if (good_map_pos(data, x, y))
// 		return (true);
// 	return (false);
// }

// bool	good_move(t_data *data, double x_new, double y_new)
// {
// 	if (good_pos(data, x_new, data->player->y_pos))
// 	{
// 		data->player->x_pos = x_new;
// 		return (false);
// 	}
// 	if (good_pos(data, data->player->x_pos, y_new))
// 	{
// 		data->player->y_pos = y_new;
// 		return (false);
// 	}
// 	return (true);
// }

static bool good_map_pos(t_data *data, double x, double y)
{
    return (x >= 0.25 && x < data->map.w_map - 1.25 && y >= 0.25 \
	&& y < data->map.h_map - 0.25);
}

static bool good_wall_pos(t_data *data, double x, double y)
{
    return (data->map.map2d[(int)y][(int)x] == '0');
}

bool good_move(t_data *data, double x_new, double y_new)
{
    return (good_map_pos(data, x_new, y_new) && good_wall_pos(data, x_new, y_new));
}
