#include "cub3d-bis.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;
    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_vertical_lign(t_data *data)
{
    while (data->map.x_map <= MAP_WIDTH * TILE_SIZE) {
        my_mlx_pixel_put(data, data->map.x_map, 0, 0xFFFFFF); // Ligne en haut
        my_mlx_pixel_put(data, data->map.x_map, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Ligne en bas
        data->map.x_map += TILE_SIZE;
    }
}

void	draw_horizontal_lign(t_data *data)
{
    while (data->map.y_map <= MAP_HEIGHT * TILE_SIZE) {
        my_mlx_pixel_put(data, 0, data->map.y_map, 0xFFFFFF); // Ligne à gauche
        my_mlx_pixel_put(data, MAP_WIDTH * TILE_SIZE, data->map.y_map, 0xFFFFFF); // Ligne à droite
        data->map.y_map += TILE_SIZE;
    }
}

void draw_square(t_data *data, int x, int y, int color)
{
    for (int i = 0; i < TILE_SIZE; i++) {
        for (int j = 0; j < TILE_SIZE; j++) {
            my_mlx_pixel_put(data, x + i, y + j, color);
        }
    }
}