#include "cub3d-bis.h"

// Get me the vertical ray length
float calculate_vertical_ray_length(int map_height, int window_height, float fov_rad) {
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return map_height / (2.0 * tan(fov_rad / 2.0));
}

// Get me the horizontal ray length
float calculate_horizontal_ray_length(int map_width, int window_width, float fov_rad) {
    if (tan(fov_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return map_width / (2.0 * tan(fov_rad / 2.0));
}

// OG VERSION, DO NOT TOUCH
// float get_ray_length(int map_width, int map_height, int window_width, int window_height, float field_of_view) {
//     float fov_rad;
// 	float vertical_ray_length;
// 	float horizontal_ray_length;
	
// 	// get me the fov in radians
// 	fov_rad = field_of_view * M_PI / 180.0;

//     vertical_ray_length = calculate_vertical_ray_length(map_height, window_height, fov_rad);
//     horizontal_ray_length = calculate_horizontal_ray_length(map_width, window_width, fov_rad);

// 	if (horizontal_ray_length > vertical_ray_length)
// 		return horizontal_ray_length;
// 	else 
// 		return	vertical_ray_length;
// }

float get_ray_length(t_map *map, t_mlx *mlx, float field_of_view) {
    float fov_rad;
	float vertical_ray_length;
	float horizontal_ray_length;
	
	// get me the fov in radians
	fov_rad = field_of_view * M_PI / 180.0;

    vertical_ray_length = calculate_vertical_ray_length(&map->h_map, &mlx->win_height, fov_rad);
    horizontal_ray_length = calculate_horizontal_ray_length(&map->w_map, &mlx->win_width, fov_rad);

	if (horizontal_ray_length > vertical_ray_length)
		return horizontal_ray_length;
	else 
		return	vertical_ray_length;
}
