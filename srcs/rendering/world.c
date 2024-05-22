#include "../include/cub3d-bis.h"

float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

void draw_world_bg(t_image *world, int color) 
{
	int x;
	int y;

	y = 0;
    while (y < WINDOW_HEIGHT / 2) {
		x = 0;
		while (x < WINDOW_WIDTH) {
			my_mlx_pixel_put(world, x, y, color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT) {
		x = 0;
		while (x < WINDOW_WIDTH) {
			my_mlx_pixel_put(world, x, y, 0xFFD700);
			x++;
		}
		y++;
	}
}

// OG loop to draw walls do not delete
// void draw_3d_world(t_map *map, t_image *world, int x, int y, int current_x, int current_y, int x1, int y1, t_ray *ray, t_data *data)
// {
// 	int wall_height;
// 	char wall_dir;
// 	int wall_top;

// 	 if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] != '0') {
//             wall_height = calculate_wall_height(current_x, current_y, x1, y1, ray, data);
//             wall_dir = get_wall_direction(x, y, map);
//             wall_top = get_wall_top(wall_height);
//             render_wall_texture(world, x * TILE_SIZE, ray->wall_height, wall_top, /*&*/data->texture, wall_dir);
//         }
// }


