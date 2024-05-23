#include "cub3d-bis.h"

float get_ray_length(int map_width, int map_height, int window_width, int window_height, float field_of_view) 
{
    // Convert the field of view from degrees to radians
    float fov_rad = field_of_view * M_PI / 180.0;

    // Calculate the horizontal and vertical field of view
    float horizontal_fov = fov_rad;
    float vertical_fov = 2.0 * atan2(tan(fov_rad / 2.0) * window_height, window_width);

    // Ensure no division by zero
    if (tan(horizontal_fov / 2.0) == 0.0 || tan(vertical_fov / 2.0) == 0.0)
        return 0.0;

    // Calculate the horizontal and vertical ray lengths
    float horizontal_ray_length = map_width / (2.0 * tan(horizontal_fov / 2.0));
    float vertical_ray_length = map_height / (2.0 * tan(vertical_fov / 2.0));

    // Choose the larger of the two ray lengths
    float ray_length = (horizontal_ray_length > vertical_ray_length) ? horizontal_ray_length : vertical_ray_length;

    return ray_length;
}

void fov_rays(int hauteur_image, int largeur_image, float fov_horizontal_deg) 
{
    
    float fov_horizontal_rad;
	float rayon_horizontal;
	float fov_vertical_rad;
	float fov_vertical_deg;
	float rayon_vertical;

	// Convertir le FOV horizontal en radians
	fov_horizontal_rad = fov_horizontal_deg * M_PI / 180.0;

    // Ensure no division by zero
    if (tan(fov_horizontal_rad / 2.0) == 0.0)
        return;

    // Calculer le rayon horizontal nécessaire pour couvrir toute l'image
    rayon_horizontal = largeur_image / (2.0 * tan(fov_horizontal_rad / 2.0));

    // Calculer le FOV vertical en fonction du rapport de l'image
    fov_vertical_rad = 2.0 * atan2(tan(fov_horizontal_rad / 2.0) * hauteur_image, largeur_image);
    fov_vertical_deg = fov_vertical_rad * 180.0 / M_PI;

    // Ensure no division by zero
    if (tan(fov_vertical_rad / 2.0) == 0.0)
        return;

    // Calculer le rayon vertical nécessaire pour couvrir toute l'image
    rayon_vertical = hauteur_image / (2.0 * tan(fov_vertical_rad / 2.0));
}

float correct_fisheye(float distance, float ray_angle, float player_angle) 
{
    float angle_difference;
	float corrected_distance;
	
	angle_difference = ray_angle - player_angle;
    corrected_distance = distance * cos(angle_difference);
    return corrected_distance;
}

// ********************************************************* // 

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


// float get_ray_length(t_player *player) 
// {
//     float fov_rad;
// 	float vertical_ray_length;
// 	float horizontal_ray_length;
	
// 	fov_rad = player->fov * M_PI / 180.0;

//     vertical_ray_length = calculate_vertical_ray_length(fov_rad);
//     horizontal_ray_length = calculate_horizontal_ray_length(fov_rad);

// 	if (horizontal_ray_length > vertical_ray_length)
// 		return horizontal_ray_length;
// 	else 
// 		return	vertical_ray_length;
// }
