#include "cub3d-bis.h"

void	draw_vertical_lines(t_image *map2d) {
    int x;

    x = 0;
    while (x < map2d->width) {
        draw_vertical_line(map2d, x, 0, 0xFFFFFF); // Draw line at the top
        draw_vertical_line(map2d, x, map2d->height - 1, 0xFFFFFF); // Draw line at the bottom
        x += TILE_SIZE;
    }
}

void	draw_horizontal_lines(t_image *map2d) {
    int y;

    y = 0;
    while (y < map2d->height) {
        draw_horizontal_line(map2d, 0, y, 0xFFFFFF); // Draw line on the left
        draw_horizontal_line(map2d, map2d->width - 1, y, 0xFFFFFF); // Draw line on the right
        y += TILE_SIZE;
    }
}

// Définir une fonction pour dessiner une ligne verticale à une position x avec une couleur donnée
void	draw_vertical_line(t_image *map2d, int x, int start_y, int color) {
    int y;

    y = start_y;
    while (y < map2d->height) {
        my_mlx_pixel_put(map2d, x, y, color);
        y++;
    }
}

// Définir une fonction pour dessiner une ligne horizontale à une position y avec une couleur donnée
void	draw_horizontal_line(t_image *map2d, int start_x, int y, int color) {
    int x;

    x = start_x;
    while (x < map2d->width) {
        my_mlx_pixel_put(map2d, x, y, color);
        x++;
    }
}

void	draw_vertical_lign(t_data *data) {
    while (data->map.x_map <= MAP_WIDTH * TILE_SIZE) {
        my_mlx_pixel_put(data, data->map.x_map, 0, 0xFFFFFF); // Ligne en haut
        my_mlx_pixel_put(data, data->map.x_map, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Ligne en bas
        data->map.x_map += TILE_SIZE;
    }
}