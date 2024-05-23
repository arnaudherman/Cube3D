#include "cub3d-bis.h"

void draw_wall_column(t_image *world, int column, int wall_height)
{
	int top;
	int bottom;
	int y;

    top = (WINDOW_HEIGHT - wall_height) / 2;
    bottom = top + wall_height;

    if (top < 0)
		top = 0;
    if (bottom >= WINDOW_HEIGHT)
		bottom = WINDOW_HEIGHT - 1;

	y = top;
    while (y <= bottom)
    {
        my_mlx_pixel_put(world, column, y, 0xBBA498);
		y++;
    }
}

void draw_wall(t_data *data, t_ray *ray) 
{
	int column;

	column = 0;
    while (column < WINDOW_WIDTH) {
		// To do : ray->camera_x init already in init ray, second time is useless ? 
		ray->camera_x = 2 * column / (double)WINDOW_WIDTH - 1;  // Correct position for camera_x
        ray->dir_x = data->player->x_dir + data->player->x_plane * ray->camera_x;
        ray->dir_y = data->player->y_dir + data->player->y_plane * ray->camera_x;

        ray->map_x = (int)data->player->x_pos;
        ray->map_y = (int)data->player->y_pos;

        get_delta_dist(data);
        get_side_dist(data);
        // TO DO second dda ?
		perform_dda(ray, &data->map);
        get_wall_dist(data->player, ray);
        get_wall_height(ray);

        draw_wall_column(data->world, column, ray->wall_height);
		column++;
    }
}
