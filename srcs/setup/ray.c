#include "cub3d-bis.h"

void	calculate_delta_dist(t_ray *ray)
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

void	calculate_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->x = -1;
		ray->sidedist_x = (player->x_pos - ray->map_x) * ray->dx;
	}
	else
	{
		ray->x = 1;
		ray->sidedist_x = (ray->map_x - player->x_pos + 1.0)
			* ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->y = -1;
		ray->sidedist_y = (player->y_pos - ray->map_y) * ray->dy;
	}
	else
	{
		ray->y = 1;
		ray->sidedist_y = (ray->map_y - player->y_pos + 1.0)
			* ray->dy;
	}
}

int init_rays(t_ray *ray, t_player *player)
{
	ray->x = 0;
	ray->side = 0;
	ray->line_height = 0;
	// ray->draw_start = 0;
	// ray->draw_end = 0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->pov_x = 0.0;
	ray->dir_x = player->x_dir + player->x_plane * ray->camera_x;
	ray->dir_y = player->y_dir + player->y_plane * ray->camera_x;
	ray->map_x = (int)player->x_pos;
	ray->map_y = (int)player->y_pos;

	// TO DO : CHECK IF :
	calculate_delta_dist(ray);
	// ray->dx = cos(player->angle);
	// ray->dy = sin(player->angle);

	calculate_side_dist(ray, player);
	ray->camera_x = 2 * ray->x / (double)WINDOW_WIDTH - 1;
	return 0;
}

t_ray *allocate_ray(void) 
{
    t_ray *ray;
	
	ray = malloc(sizeof(t_ray));
    if (ray == NULL) {
        perror("Allocation for ray failed\n");
        exit(EXIT_FAILURE);
    }
    ray->x = 0;
	ray->y = 0;
	ray->xinc = 0;
	ray->yinc = 0;
	ray->step = 0;
	ray->x_start = 0;
	ray->y_start = 0;
    ray->x_end = 0;
	ray->y_end = 0;
    ray->line_height = 0;
	// ray->side = 0;
    // ray->draw_start = 0;
    // ray->draw_end = 0;
    ray->wall_dist = 0.0;
	ray->wall_height = 0.0;
    // ray->wall_x = 0.0;
	// ray->wall_y = 0.0;
    // ray->pov_x = 0.0;
    ray->dir_x = 0.0;
    ray->dir_y = 0.0;
    ray->map_x = 0.0;
    ray->map_y = 0.0;
    ray->dx = 0.0;
    ray->dy = 0.0;
    ray->sidedist_x = 0.0;
    ray->sidedist_y = 0.0;
	ray->camera_x = 0.0;
    return ray;
}