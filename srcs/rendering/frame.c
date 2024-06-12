#include "cub3d.h"

void	draw_minimap_bg(t_image *map2d, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < map2d->height)
	{
		x = 0;
		while (x < map2d->width)
		{	
			my_mlx_pixel_put(map2d, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_world_bg(t_image *world, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{ 
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(world, x, y, color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(world, x, y, 0xFFD700);
			x++;
		}
		y++;
	}
}

int draw_player(t_image *image, t_player *player)
{
    player->x_center = (int)player->x_pos;
    player->y_center = (int)player->y_pos;
    player->x_start = player->x_center - player->size / 2;
    player->y_start = player->y_center - player->size / 2;
    player->x_end = player->x_center + player->size / 2;
    player->y_end = player->y_center + player->size / 2;
    player->y = player->y_start; 
    while (player->y < player->y_end)
    {
        player->x = player->x_start;
        while (player->x < player->x_end)
        {
            player->local_x = player->x - player->x_center;
            player->local_y =player->y - player->y_center;

            player->global_x = player->local_x + player->x_center;
            player->global_y = player->local_y + player->y_center;

            if (player->global_x >= player->x_start && player->global_x < player->x_end && player->global_y >= player->y_start && player->global_y < player->y_end)
                my_mlx_pixel_put(image, player->global_x, player->global_y, player->color);
             player->x++;
        }
        player->y++;
    }
    return 0;
}


#include <time.h>
double get_elapsed_time() // DEBUG stuff
{
    static clock_t start_time = 0;
    // if (start_time == 0) {
    //     start_time = clock();
    //     return 0.0;
    // } else {
        clock_t current_time = clock();
        double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
		start_time = clock();
        return elapsed_time;
    // }
}

// Use mlx_put_image_to_window() with a recycled image that you have cleared
// to display the image on the window instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
	memset(data->world->addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT
		* (data->world->bits_per_pixel / 8));
	draw_map(data->map2d, &data->map);
	key_move(data, data->map2d->tile_size);
	draw_player(data->map2d, data->player);
	draw_world_bg(data->world, 0x0057B8);
	raycasting(data, data->player, &data->mlx);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr,
		data->world->img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr,
		data->map2d->img, 20, 20);
	// fps 
	
	// DEBUG stuff
	static	int all_fps;
	static	int frame_count;
	static	int total_frame_count;
	static	int total_fps_count;
	double dt = get_elapsed_time();
	double fps = 1.0 / dt;
	all_fps += fps;
	frame_count++;
	total_frame_count++;
	if (frame_count == 100)
	{
		total_fps_count += all_fps;
		printf("last %d frames avrage fps: %d\t(total: %d)\t(dt: %f)\n", frame_count, all_fps / frame_count, total_fps_count / total_frame_count, dt);
		all_fps = 0;
		frame_count = 0;
	}


	return (0);
}
