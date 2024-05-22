#include "cub3d-bis.h"

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

// Similar
void draw_square(t_data *data, int x, int y, int color) {
	int i;
	int j;

	i = 0;
    while (i < TILE_SIZE) {
		j = 0; 
        while (j < TILE_SIZE) {
            my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
        }
		i++;
    }
}
