#include "cub3d-bis.h"

// Get me the vertical ray length
float calculate_vertical_ray_length(float fov_rad) 
{
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return WINDOW_HEIGHT / (2.0 * tan(fov_rad / 2.0));
}

// Get me the horizontal ray length
float calculate_horizontal_ray_length(float fov_rad) 
{
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return WINDOW_WIDTH / (2.0 * tan(fov_rad / 2.0));
}

float get_ray_length(t_player *player) 
{
    float fov_rad;
	float vertical_ray_length;
	float horizontal_ray_length;
	
	// get me the fov in radians
	fov_rad = player->fov * M_PI / 180.0;

    vertical_ray_length = calculate_vertical_ray_length(fov_rad);
    horizontal_ray_length = calculate_horizontal_ray_length(fov_rad);

	if (horizontal_ray_length > vertical_ray_length)
		return horizontal_ray_length;
	else 
		return	vertical_ray_length;
}
