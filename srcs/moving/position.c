#include "cub3d-bis.h"

// en fonction de son angle
// void update_player_pos(t_player *player, double move_distance) {
//     player->x_pos += move_distance * cos(player->angle);
//     player->y_pos += move_distance * sin(player->angle);
// }

bool is_wall(t_map *map, int x, int y) 
{
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)
        return true;
    return map->map2d[y][x] == '1';
}

bool player_wall_collision(t_map *map, double x, double y) 
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
