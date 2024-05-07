#include "cub3d-bis.h"

bool is_wall(t_map *map, int x, int y) 
{
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)
        return true;
    return map->map2d[y][x] == '1';
}

bool check_collision(t_map *map, double x, double y) 
{
    int x_tile_left;
    int x_tile_right;
    int y_tile_top;
    int y_tile_bottom;

    x_tile_left = (int)((x - 24 / 2) / TILE_SIZE);
    x_tile_right = (int)((x + 24 / 2) / TILE_SIZE);
    y_tile_top = (int)((y - 24 / 2) / TILE_SIZE);
    y_tile_bottom = (int)((y + 24 / 2) / TILE_SIZE);

    if (is_wall(map, x_tile_left, (int)(y / TILE_SIZE)) ||
        is_wall(map, x_tile_right, (int)(y / TILE_SIZE)) ||
        is_wall(map, (int)(x / TILE_SIZE), y_tile_top) ||
        is_wall(map, (int)(x / TILE_SIZE), y_tile_bottom)) {
        return true;
    }
	
    return false;
}

// static bool	check_map_pos(t_data *data, double x, double y)
// {
// 	if (x < 0.25 || x >= data->map.w_map - 1.25)
// 		return (false);
// 	if (y < 0.25 || y >= data->map.h_map -0.25)
// 		return (false);
// 	return (true);
// }

// static bool	check_wall_pos(t_data *data, double x, double y)
// {
// 	if (data->map.map2d[(int)y][(int)x] == '0')
// 		return (true);
// 	return (false);
// }

// static bool	check_pos(t_data *data, double x, double y)
// {
// 	if (check_wall_pos(data, x, y))
// 		return (true);
// 	if (check_map_pos(data, x, y))
// 		return (true);
// 	return (false);
// }

// bool	check_move(t_data *data, double x_new, double y_new)
// {
// 	// Let's check the new x position
// 	if (check_pos(data, x_new, data->player->y_pos) == true)
// 	{
// 		data->player->x_pos = x_new;
// 		return (false);
// 	}
// 	// Let's check the new y position
// 	if (check_pos(data, data->player->x_pos, y_new) == true)
// 	{
// 		data->player->y_pos = y_new;
// 		return (false);
// 	}
// 	return (true);
// }

// bool check_map_pos(t_data *data, double x, double y)
// {
//     return (x >= 0.25 && x < data->map.w_map - 1.25 && y >= 0.25 \
// 	&& y < data->map.h_map - 0.25);
// }

// bool check_wall_pos(t_data *data, double x, double y)
// {
// 	if (data->map.map2d[(int)y][(int)x] == '0')
// 		return (true);
// 	return (false);
// }

// bool check_move(t_data *data, double x_new, double y_new)
// {
//     return (check_map_pos(data, x_new, y_new) && check_wall_pos(data, x_new, y_new));
// }
