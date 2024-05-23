#include "cub3d-bis.h"

char get_wall_direction(int x, int y, t_map *map) 
{
    return map->map2d[y / TILE_SIZE][x / TILE_SIZE];
}

int get_wall_top(int wall_height) 
{
    return (WINDOW_HEIGHT / 2) - (wall_height / 2);
}

float correct_fisheye(float distance, float ray_angle, float player_angle) 
{
    float angle_difference;
	float corrected_distance;
	
	angle_difference = ray_angle - player_angle;
    corrected_distance = distance * cos(angle_difference);
    return corrected_distance;
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