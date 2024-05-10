#include "cub3d-bis.h"

t_ray *allocate_ray(void) 
{
    t_ray *ray;
	
	ray = malloc(sizeof(t_ray));
    if (ray == NULL) {
        perror("Allocation for ray failed\n");
        exit(EXIT_FAILURE);
    }
    ray->step_x = 0;
    ray->step_y = 0;
    ray->side = 0;
    ray->line_height = 0;
    ray->draw_start = 0;
    ray->draw_end = 0;
    ray->wall_dist = 0.0;
    ray->wall_x = 0.0;
    ray->pov_x = 0.0;
    ray->dir_x = 0.0;
    ray->dir_y = 0.0;
    ray->map_x = 0.0;
    ray->map_y = 0.0;
    ray->dx = 0.0;
    ray->dy = 0.0;
    ray->sidedist_x = 0.0;
    ray->sidedist_y = 0.0;
    return ray;
}

void init_rays(t_ray *ray)
{
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->pov_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0.0;
	ray->map_y = 0.0;
	ray->dx = 0.0;
	ray->dy = 0.0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
}