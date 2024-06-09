#include "cub3d-bis.h"

void	calculate_deltas(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->dx = 0;
	else if (ray->dir_x == 0)
		ray->dx = 1;
	else
		ray->dx = fabs(1 / ray->dir_x);

	if (ray->dir_x == 0)
		ray->dy = 0;
	else if (ray->dir_y == 0)
		ray->dy = 1;
	else
		ray->dy = fabs(1 / ray->dir_y);
}

void	calculate_steps_sides(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->x_step = -1;
		ray->sx = (player->x_pos - ray->x_map) * ray->dx;
	}
	else
	{
		ray->x_step = 1;
		ray->sx = (ray->x_map - player->x_pos + 1.0)
			* ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->y_step = -1;
		ray->sy = (player->y_pos - ray->y_map) * ray->dy;
	}
	else
	{
		ray->y_step = 1;
		ray->sy = (ray->y_map - player->y_pos + 1.0)
			* ray->dy;
	}
}

void init_ray(t_ray *ray, t_player *player) 
{
    ray->x_map = (int)player->x_pos;
    ray->y_map = (int)player->y_pos;
    ray->camera_x = 2 * ray->x / (double)WINDOW_WIDTH - 1;
    ray->dir_x = player->x_dir + player->x_plane * ray->camera_x;
    ray->dir_y = player->y_dir + player->y_plane * ray->camera_x;
	ray->dx = fabs(1 / ray->dir_x);
    ray->dy = fabs(1 / ray->dir_y);
    // Initialize step and initial sideDist
    if (ray->dir_x < 0) {
        ray->x_step = -1;
        ray->sx = (player->x_pos - ray->x_map) * ray->dx;
    } else {
        ray->x_step = 1;
        ray->sx = (ray->x_map + 1.0 - player->x_pos) * ray->dx;
    }
    if (ray->dir_y < 0) {
        ray->y_step = -1;
        ray->sy = (player->y_pos - ray->y_map) * ray->dy;
    } else {
        ray->y_step = 1;
        ray->sy = (ray->y_map + 1.0 - player->y_pos) * ray->dy;
    }
    ray->hit = 0;
}
//     calculate_deltas(ray);
//     calculate_steps_sides(ray, player);
//     ray->hit = 0;
//     return 0;
// }
