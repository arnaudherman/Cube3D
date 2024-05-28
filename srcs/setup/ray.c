#include "cub3d-bis.h"

// // Will be used during the raycasting process
// int init_one_ray(t_data *data)
// {
// 	data->ray->x1 = data->player->x_pos;
// 	data->ray->y1 = data->player->y_pos;
//     // TO DO : ray index here ? value ?
// 	data->ray->camera_x = 2 * data->ray->ray_index / (double)WINDOW_WIDTH - 1; // Déplacement avant le calcul des directions
//     data->ray->dir_x = data->player->x_dir + data->player->x_plane * data->ray->camera_x;
//     data->ray->dir_y = data->player->y_dir + data->player->y_plane * data->ray->camera_x;
//     data->ray->map_x = (int)(data->player->x_pos);
//     data->ray->map_y = (int)(data->player->y_pos);
//     get_delta_dist(data);
//     get_side_dist(data);
// 	printf("data->ray->length = %f\n", data->ray->ray_length); // 246.378387
//     // To do : get_ray_length(data->player); here ?
// 	data->ray->ray_length = 1.0;
// 	data->ray->angle = data->player->angle - (data->player->fov / 2.0) + ((double)data->ray->ray_index / WINDOW_WIDTH) * data->player->fov;

//     return 0;
// }

int init_one_ray(int x, t_ray *ray, t_player *player)
{
	ray = malloc(sizeof(t_ray));
    if (ray == NULL) {
        perror("Allocation for ray failed\n");
        exit(EXIT_FAILURE);
    }
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = player->x_dir + player->x_plane * ray->camera_x;
	ray->dir_y = player->y_dir + player->y_plane * ray->camera_x;
	ray->map_x = (int)player->x_pos;
	ray->map_y = (int)player->y_pos;
	ray->dx = fabs(1 / ray->dir_x);
	ray->dy = fabs(1 / ray->dir_y);
	return 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->dx = 0;
	ray->dy = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
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
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->text_x = 0;
	ray->text_y = 0;
	ray->wall_hit = 0;
	// Init floats
	ray->dx = 0.0;
    ray->dy = 0.0;
    ray->wall_dist = 0.0;
	ray->wall_height = 0.0;
	ray->wall_x = 0.0;
	ray->wall_y = 0.0;
    ray->dir_x = 0.0;
    ray->dir_y = 0.0;
    ray->map_x = 0.0;
    ray->map_y = 0.0;
    ray->sidedist_x = 0.0;
    ray->sidedist_y = 0.0;
	ray->camera_x = 0.0;
	ray->ray_length = 0.0;
	ray->angle = 0.0;
    return ray;
}