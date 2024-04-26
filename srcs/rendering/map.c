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
    while (data->map.x_map <= MAP_WIDTH * TILE_SIZE) {
        draw_vertical_line(data, data->map.x_map, 0, 0xFFFFFF); // Draw line at the top
        draw_vertical_line(data, data->map.x_map, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Draw line at the bottom
        data->map.x_map += TILE_SIZE;
    }
}

void draw_horizontal_lines(t_data *data) {
    while (data->map.y_map <= MAP_HEIGHT * TILE_SIZE) {
        draw_horizontal_line(data, 0, data->map.y_map, 0xFFFFFF); // Draw line on the left
        draw_horizontal_line(data, MAP_WIDTH * TILE_SIZE, data->map.y_map, 0xFFFFFF); // Draw line on the right
        data->map.y_map += TILE_SIZE;
    }
}

void draw_vertical_line(t_data *data, int x, int start_y, int color) {
    int y = start_y;
    while (y <= (MAP_HEIGHT * TILE_SIZE)) {
        my_mlx_pixel_put(data, x, y, color);
        y++;
    }
}

void draw_horizontal_line(t_data *data, int start_x, int y, int color) {
    int x = start_x;
    while (x <= (MAP_WIDTH * TILE_SIZE)) {
        my_mlx_pixel_put(data, x, y, color);
        x++;
    }
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;
    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void draw_square(t_data *data, int x, int y, int color)
{
    for (int i = 0; i < TILE_SIZE; i++) {
        for (int j = 0; j < TILE_SIZE; j++) {
            my_mlx_pixel_put(data, x + i, y + j, color);
        }
    }
}

int draw_map(t_data *data) {
    // Draw vertical lines
    draw_vertical_lines(data);
	
    // Draw horizontal lines
    draw_horizontal_lines(data);

    // Draw tiles
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