#include "cub3d.h"

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

void draw_tile(t_image *map2d, int x, int y) {
    int i = 0;
    while (i < TILE_SIZE) {
        int j = 0;
        while (j < TILE_SIZE) {
            my_mlx_pixel_put(map2d, x + i, y + j, 0xb6d7a8);
            j++;
        }
        i++;
    }
}

void draw_vertical_lines(t_image *map2d) {
    int x;

    x = 0;
    while (x < map2d->width) {
        draw_vertical_line(map2d, x, 0, 0xFFFFFF); // Draw line at the top
        draw_vertical_line(map2d, x, map2d->height - 1, 0xFFFFFF); // Draw line at the bottom
        x += TILE_SIZE;
    }
}

void draw_horizontal_lines(t_image *map2d) {
    int y;

    y = 0;
    while (y < map2d->height) {
        draw_horizontal_line(map2d, 0, y, 0xFFFFFF); // Draw line on the left
        draw_horizontal_line(map2d, map2d->width - 1, y, 0xFFFFFF); // Draw line on the right
        y += TILE_SIZE;
    }
}

// Définir une fonction pour dessiner une ligne verticale à une position x avec une couleur donnée
void draw_vertical_line(t_image *map2d, int x, int start_y, int color) {
    int y;

    y = start_y;
    while (y < map2d->height) {
        my_mlx_pixel_put(map2d, x, y, color);
        y++;
    }
}

// Définir une fonction pour dessiner une ligne horizontale à une position y avec une couleur donnée
void draw_horizontal_line(t_image *map2d, int start_x, int y, int color) {
    int x;

    x = start_x;
    while (x < map2d->width) {
        my_mlx_pixel_put(map2d, x, y, color);
        x++;
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

