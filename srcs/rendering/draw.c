#include "../include/cub3d-bis.h"

void draw_ceiling(t_data *data) {
    int x = 0;
    while (x < WINDOW_WIDTH) {
        int y = 0;
        while (y < WINDOW_HEIGHT / 2) {
            my_mlx_pixel_put(data, x, y, CEILING); // Remplacez CEILING_COLOR par la couleur choisie pour le plafond
            y++;
        }
        x++;
    }
}

void draw_floor(t_data *data) {
    int x = 0;
    while (x < WINDOW_WIDTH) {
        int y = WINDOW_HEIGHT / 2;
        while (y < WINDOW_HEIGHT) {
            my_mlx_pixel_put(data, x, y, FLOOR); // Remplacez FLOOR_COLOR par la couleur choisie pour le sol
            y++;
        }
        x++;
    }
}
