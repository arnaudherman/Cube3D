#include "cub3d-bis.h"

// From player to wall hit
void	get_wall_dist(t_player *player, t_ray *ray)
{
    float dx;
	float dy;
	float distance;

	dx = ray->x_end - player->x_pos;
    dy = ray->y_end - player->y_pos;
    distance = sqrt(dx * dx + dy * dy);

    ray->wall_dist = distance;
	return ;
}

void	get_wall_height(t_ray *ray)
{
    int wall_height;
	
	if (ray->wall_dist == 0)
		ray->wall_dist = 1;
	wall_height = (int)(WALL_HEIGHT / ray->wall_dist);
	ray->wall_height = wall_height;
    return ;
}

void draw_wall_column(t_data *data, int column, float angle)
{
    int top;
	int bottom;
	int y;
	
	top = (WINDOW_HEIGHT - data->ray->wall_height) / 2;
    bottom = top + data->ray->wall_height;
    y = top;
    while (y < bottom)
    {
        my_mlx_pixel_put(data->image, column, y, 0x808080);
        y++;
    }
}

void draw_wall(t_data *data, int x, int y)
{
    int column = 0;
    float angle = data->player->angle - (FOV / 2);
    
    while (column < WINDOW_WIDTH)
    {
        get_wall_dist(data->player, data->ray);
        get_wall_height(data->ray);
        draw_wall_column(data, column, angle);
        
        column++;
        angle += (FOV / WINDOW_WIDTH);
    }
}
