#include "cub3d-bis.h"

void draw_tile(t_image *image, int x, int y) {
    int i = 0;
    while (i < TILE_SIZE) {
        int j = 0;
        while (j < TILE_SIZE) {
            my_mlx_pixel_put(image, x + i, y + j, 0xFFFFF); // wall color here wtf
            j++;
        }
        i++;
    }
}

void draw_vertical_lines(t_image *image) {
    int x = 0;


    while (x < WINDOW_WIDTH) {
        draw_vertical_line(image, x, 0, 0xFFFFFF); // Draw line at the top
        draw_vertical_line(image, x, WINDOW_HEIGHT, 0xFFFFFF); // Draw line at the bottom
        x += TILE_SIZE;
    }
}

void draw_horizontal_lines(t_image *image) {
    int y = 0;
    while (y < WINDOW_HEIGHT) {
        draw_horizontal_line(image, 0, y, 0xFFFFFF); // Draw line on the left
        draw_horizontal_line(image, WINDOW_WIDTH, y, 0xFFFFFF); // Draw line on the right
        y += TILE_SIZE;
    }
}

// Définir une fonction pour dessiner une ligne verticale à une position x avec une couleur donnée
void draw_vertical_line(t_image *image, int x, int start_y, int color) {
    int y = start_y;
    while (y <= (MAP_HEIGHT * TILE_SIZE)) {
        my_mlx_pixel_put(image, x, y, color);
        y++;
    }
}

// Définir une fonction pour dessiner une ligne horizontale à une position y avec une couleur donnée
void draw_horizontal_line(t_image *image, int start_x, int y, int color) {
    int x = start_x;
    while (x <= (MAP_WIDTH * TILE_SIZE)) {
        my_mlx_pixel_put(image, x, y, color);
        x++;
    }
}

int draw_map(t_image *image, t_map *map) {

	int x;
	int y;

    draw_vertical_lines(image);
	// line_length = 7680, bits_per_pixel = 32

    draw_horizontal_lines(image);
	// line_length = 7680, bits_per_pixel = 32

    // draw tiles
    y = 0;
    while (y < MAP_HEIGHT) {
        x = 0;
        while (x < MAP_WIDTH) {
			printf("kiss line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
			// // line_length = 7680, bits_per_pixel = 32
            if (map->map2d[y][x] == '1') {
				printf("slap line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
                draw_tile(image, x * TILE_SIZE, y * TILE_SIZE);
				printf("you line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
            }
			x++;
			// line_length = 7680, bits_per_pixel = 32
        }
		printf("c draw map line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
        y++;
		printf("d draw map line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
    }
	printf("e draw map line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
    return (0);
}
