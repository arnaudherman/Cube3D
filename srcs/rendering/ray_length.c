#include "cub3d-bis.h"

// // Get me the vertical ray length
// float calculate_vertical_ray_length(float fov_rad) 
// {
//     if (tan(fov_rad / 2.0) == 0.0) {
//         return 0.0; // Prévenir la division par zéro
//     }
//     return WINDOW_HEIGHT / (2.0 * tan(fov_rad / 2.0));
// }

// // Get me the horizontal ray length
// float calculate_horizontal_ray_length(float fov_rad) 
// {
//     if (tan(fov_rad / 2.0) == 0.0) {
//         return 0.0; // Prévenir la division par zéro
//     }
//     return WINDOW_WIDTH / (2.0 * tan(fov_rad / 2.0));
// }

float calculate_vertical_ray_length(float fov_rad) 
{
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    // Nombre de tuiles verticales dans la carte
    int num_vertical_tiles = MAP_HEIGHT;
    // Hauteur d'une tuile en pixels
    int tile_height_px = TILE_SIZE;
    // Hauteur totale de la carte en pixels
    int total_map_height_px = num_vertical_tiles * tile_height_px;
    return total_map_height_px / (2.0 * tan(fov_rad / 2.0));
}

float calculate_horizontal_ray_length(float fov_rad) 
{
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    // Nombre de tuiles horizontales dans la carte
    int num_horizontal_tiles = MAP_WIDTH;
    // Largeur d'une tuile en pixels
    int tile_width_px = TILE_SIZE;
    // Largeur totale de la carte en pixels
    int total_map_width_px = num_horizontal_tiles * tile_width_px;
    return total_map_width_px / (2.0 * tan(fov_rad / 2.0));
}


float get_ray_length(t_player *player) 
{
    float fov_rad;
	float vertical_ray_length;
	float horizontal_ray_length;
	
	fov_rad = player->fov * M_PI / 180.0;

    vertical_ray_length = calculate_vertical_ray_length(fov_rad);
    horizontal_ray_length = calculate_horizontal_ray_length(fov_rad);

	if (horizontal_ray_length > vertical_ray_length)
		return horizontal_ray_length;
	else 
		return	vertical_ray_length;
}
