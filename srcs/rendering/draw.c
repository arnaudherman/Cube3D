#include "cub3d-bis.h"

void my_mlx_pixel_put(t_image *image, int x, int y, int color) {
	// printf("xaq mlx_loop_hook line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
	// HERE : line_length = 0, bits_per_pixel = 0
    char *dst;
    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	// Debug: x = 0, y = 0, line_length = 24672, bits_per_pixel = 5600
	// Debug: Calculated address: 0x3e8
	// printf("Debug: x = %d, y = %d, line_length = %d, bits_per_pixel = %d\n", x, y, image->line_length, image->bits_per_pixel);
    // printf("Debug: Calculated address: %p\n", (void*)dst); 
	// Debug: x = 58, y = 57, line_length = 0, bits_per_pixel = 0 (et y boucle avec + 1 par iteration)
	// Debug: Calculated address: 0x60700001feb0
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

void draw_square(t_data *data, int x, int y, int color)
{
    for (int i = 0; i < TILE_SIZE; i++) {
        for (int j = 0; j < TILE_SIZE; j++) {
            my_mlx_pixel_put(data, x + i, y + j, color);
        }
    }
}

void draw_col(t_data *data, t_mlx *mlx, t_ray *ray) 
{
    calculate_draw_positions(mlx, ray);
    calculate_wall_x(data, ray);
    set_color_on_image(data, ray);
    set_wall_texture(data, ray);
}