#include "cub3d-bis.h"

void draw_minimap_bg(t_image *map2d, int color) 
{
    int x;
    int y;

    y = 0;
    while (y < map2d->height) {
        x = 0;
        while (x < map2d->width) {
            my_mlx_pixel_put(map2d, x, y, color);
            x++;
        }
        y++;
    }
}

int draw_map(t_image *map2d, t_map *map) {

    int x;
    int y;

    draw_minimap_bg(map2d, 0xbba498);
    draw_vertical_lines(map2d);
    draw_horizontal_lines(map2d);

    y = 0;
    while (y < MAP_HEIGHT * TILE_SIZE) {
        x = 0;
        while (x < MAP_WIDTH * TILE_SIZE) {
            if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] == '0') {
                draw_tile(map2d, x, y);
            }
            x += TILE_SIZE;
        }
        y += TILE_SIZE;
    }
    return (0);
}

