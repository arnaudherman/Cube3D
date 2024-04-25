#include "cub3d-bis.h"

char map_data[MAP_HEIGHT][MAP_WIDTH] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

void fill_map(t_map *map) {
    int i = 0;
    while (i < MAP_HEIGHT) {
        map->map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char));
        if (map->map2d[i] == NULL) {
            perror("fail in fill_map\n");
            return;
        }
        
        int j = 0;
        while (j < MAP_WIDTH) {
            map->map2d[i][j] = map_data[i][j];
            j++;
        }
        map->map2d[i][MAP_WIDTH] = '\0';
        i++;
    }
}

int malloc_map2d(t_map *map) {
    map->map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    if (map->map2d == NULL) {
		perror("fail in init_map\n");
        return -1;
    }
	return (0);
}

int init_map(t_map *map) {
    // Allocation dynamique de la mémoire pour map->map2d
    if (malloc_map2d(map) == -1) {
        perror("Failed to allocate memory for map2d\n");
        return -1;
    }

    // Remplissage des données de la carte 2D
    fill_map(map);

    // Initialisation de la couleur de la carte en noir
    map->color = 0x000000;

    return 0;
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
