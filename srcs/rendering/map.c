#include "cub3d-bis.h"

void draw_tile(t_data *data, int x, int y) {
    int i = 0;
    while (i < TILE_SIZE) {
        int j = 0;
        while (j < TILE_SIZE) {
            my_mlx_pixel_put(data, x + i, y + j, 0x808080); // wall color here
            j++;
        }
        i++;
    }
}

void draw_vertical_lines(t_data *data) {
    int x = 0;
    while (x < WINDOW_WIDTH) {
        draw_vertical_line(data, x, 0, 0xFFFFFF); // Draw line at the top
        draw_vertical_line(data, x, WINDOW_HEIGHT, 0xFFFFFF); // Draw line at the bottom
        x += TILE_SIZE;
    }
}

void draw_horizontal_lines(t_data *data) {
    int y = 0;
    while (y < WINDOW_HEIGHT) {
        draw_horizontal_line(data, 0, y, 0xFFFFFF); // Draw line on the left
        draw_horizontal_line(data, WINDOW_WIDTH, y, 0xFFFFFF); // Draw line on the right
        y += TILE_SIZE;
    }
}

// Définir une fonction pour dessiner une ligne verticale à une position x avec une couleur donnée
void draw_vertical_line(t_data *data, int x, int start_y, int color) {
    int y = start_y;
    while (y <= (MAP_HEIGHT * TILE_SIZE)) {
        my_mlx_pixel_put(data, x, y, color);
        y++;
    }
}

// Définir une fonction pour dessiner une ligne horizontale à une position y avec une couleur donnée
void draw_horizontal_line(t_data *data, int start_x, int y, int color) {
    int x = start_x;
    while (x <= (MAP_WIDTH * TILE_SIZE)) {
        my_mlx_pixel_put(data, x, y, color);
        x++;
    }
}

// Fonction de dessin de la carte
int draw_map(t_data *data) {
    // Initialiser les variables de position à zéro
    data->map.x_map = 0;
    data->map.y_map = 0;

    // Dessiner les lignes verticales et horizontales
    draw_vertical_lines(data);
    draw_horizontal_lines(data);

    // Dessiner les tuiles de la carte
    int y = 0;
    while (y < MAP_HEIGHT) {
        int x = 0;
        while (x < MAP_WIDTH) {
            if (data->map.map2d[y][x] == '1') {
                draw_tile(data, x * TILE_SIZE, y * TILE_SIZE);
            }
            x++;
        }
        y++;
    }

    return (0);
}
