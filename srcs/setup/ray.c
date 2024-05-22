#include "cub3d-bis.h"

int init_rays(t_ray *ray, t_player *player)
{
	// TO DO : check x became x1 problem ?
    ray->camera_x = 2 * ray->x1 / (double)WINDOW_WIDTH - 1; // Déplacement avant le calcul des directions
    ray->dir_x = player->x_dir + player->x_plane * ray->camera_x;
    ray->dir_y = player->y_dir + player->y_plane * ray->camera_x;
    ray->map_x = (int)player->x_pos;
    ray->map_y = (int)player->y_pos;

    ray->x1 = 0;
    ray->side = 0;
    ray->line_height = 0;
    ray->wall_dist = 0.0;
    ray->wall_x = 0.0;

    get_delta_dist(ray);
    get_side_dist(ray, player);
    ray->ray_length = get_ray_length(MAP_WIDTH, MAP_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, FOV);
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
    ray->x1 = 0;
	ray->y1 = 0;
	ray->x2 = 0;
	ray->y2 = 0;
	ray->steps = 0;
	ray->step_x = 0;
	ray->step_y = 0;
    ray->line_height = 0;
	ray->side = 0;
    ray->wall_dist = 0.0;
	ray->wall_height = 0.0;
    ray->dir_x = 0.0;
    ray->dir_y = 0.0;
    ray->map_x = 0.0;
    ray->map_y = 0.0;
    ray->dx = 0.0;
    ray->dy = 0.0;
    ray->sidedist_x = 0.0;
    ray->sidedist_y = 0.0;
	ray->camera_x = 0.0;
	ray->ray_length = 0.0;
    return ray;
}