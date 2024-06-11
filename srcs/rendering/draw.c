#include "cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color) 
{
    char *dst;
    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_minimap_bg(t_image *map2d, int color) 
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

void	draw_tile(t_image *map2d, int x, int y) 
{
    int i = 0;
    while (i < map2d->tile_size) {
        int j = 0;
        while (j < map2d->tile_size) {
            my_mlx_pixel_put(map2d, x + i, y + j, 0xb6d7a8);
            j++;
        }
        i++;
    }
}

void	draw_vertical_lign(t_data *data, int tile_size)
{
    while (data->map.x_map <= data->map.x_map * tile_size) {
        my_mlx_pixel_put(data, data->map.x_map, 0, 0xFFFFFF); // Ligne en haut
        my_mlx_pixel_put(data, data->map.x_map, data->map.y_map * tile_size, 0xFFFFFF); // Ligne en bas
        data->map.x_map += tile_size;
    }
}

void	draw_square(t_data *data, int tile_size, int x, int y, int color)
{
    for (int i = 0; i < tile_size; i++) {
        for (int j = 0; j < tile_size; j++) {
            my_mlx_pixel_put(data, x + i, y + j, color);
        }
    }
}
