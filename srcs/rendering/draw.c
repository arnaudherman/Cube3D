#include "cub3d-bis.h"

void my_mlx_pixel_put(t_image *image, int x, int y, int color) 
{
    char *dst;
    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
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

void draw_ray_on_map(t_data *data, t_ray *ray, t_player *player, t_mlx *mlx)
{
    init_ray(ray, player);

    // Use DDA to draw the ray on the 2D map
    while (ray->hit == 0)
    {
        if (ray->sx < ray->sy)
        {
            ray->sx += ray->dx;
            ray->x_map += ray->x_step;
            ray->side = 0;
        }
        else
        {
            ray->sy += ray->dy;
            ray->y_map += ray->y_step;
            ray->side = 1;
        }
        if (data->map.map2d[ray->y_map][ray->x_map] > 0)
            ray->hit = 1;
    }

    // Draw my ray on 2D map
    my_mlx_pixel_put(data->map2d, ray->x_map * TILE_SIZE, ray->y_map * TILE_SIZE, 0xff0000);
}

void draw_rays_on_map(t_data *data, t_player *player, t_mlx *mlx)
{
    t_ray ray;
    ray.x = 0;
    while (ray.x < WINDOW_WIDTH)
    {
        draw_ray_on_map(data, &ray, player, mlx);
        ray.x++;
    }
}