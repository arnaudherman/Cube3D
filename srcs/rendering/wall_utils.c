#include "cub3d-bis.h"

char get_wall_direction(int x, int y, t_map *map) 
{
    return map->map2d[y / TILE_SIZE][x / TILE_SIZE];
}

int get_wall_top(int wall_height) 
{
    return (WINDOW_HEIGHT / 2) - (wall_height / 2);
}

// TO DO : check x became x1 and y became y1 problem ?
// From player to wall hit
void get_wall_dist(t_player *player, t_ray *ray) 
{
    if (ray->side == 0 || ray->side == 1)
        ray->wall_dist = (ray->map_x - player->x_pos + (1 - ray->x1) / 2) / ray->dir_x;
    else
        ray->wall_dist = (ray->map_y - player->y_pos + (1 - ray->y1) / 2) / ray->dir_y;
}

void	get_wall_height(t_ray *ray)
{
	if (ray->wall_dist == 0)
		ray->wall_dist = 1;
	ray->wall_height = (int)(WALL_HEIGHT / ray->wall_dist);
}

int calculate_wall_height(float current_x, float current_y, t_ray *ray, t_data *data) 
{
    float distance;
	
	distance = sqrt((current_x - ray->x1) * (current_x - ray->x1) + (current_y - ray->y1) * (current_y - ray->y1));
    if (distance == 0) {
        distance = 1.0;  // Prévenir la division par zéro
    }
    // TO DO : here before correct_fisheye ? ray->wall_dist = distance;
    int corrected_distance = correct_fisheye(distance, data->ray->angle, data->player->angle);
    if (corrected_distance == 0)
        corrected_distance = 1;  // Prévenir la division par zéro
	ray->wall_dist = distance;
    return (int)(WALL_HEIGHT / corrected_distance);
}