#include "cub3d-bis.h"

// Get fov in radians
float convert_horizontal_fov_to_radians(float fov_horizontal_deg) {
    return fov_horizontal_deg * M_PI / 180.0;
}

// Calcul horizontal radius to cover whole image
float calculate_horizontal_radius(int image_width, float fov_horizontal_rad) {
    if (tan(fov_horizontal_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return image_width / (2.0 * tan(fov_horizontal_rad / 2.0));
}

// Calcul vertical fov in function of image ratio
float calculate_vertical_fov(int image_height, int image_width, float fov_horizontal_rad) {
    float vertical_fov_rad;
	
	vertical_fov_rad = 2.0 * atan2(tan(fov_horizontal_rad / 2.0) * image_height, image_width);

    return vertical_fov_rad * 180.0 / M_PI;
}

// Calcul vertical radius to cover whole image
float calculate_vertical_radius(int image_height, float fov_vertical_rad) {
    if (tan(fov_vertical_rad / 2.0) == 0.0) {
        return 0.0; // Prévenir la division par zéro
    }
    return image_height / (2.0 * tan(fov_vertical_rad / 2.0));
}

// Get fov in rays radians
// void fov_rays(int image_height, int image_width, float fov_horizontal_deg) {
// 	float fov_horizontal_rad;
//     float horizontal_radius;
//     float vertical_fov;
//     float vertical_fov_rad;
//     float vertical_radius;

//     fov_horizontal_rad = convert_horizontal_fov_to_radians(fov_horizontal_deg);
//     horizontal_radius = calculate_horizontal_radius(image_width, fov_horizontal_rad);
//     vertical_fov = calculate_vertical_fov(image_height, image_width, fov_horizontal_rad);
//     vertical_fov_rad = convert_horizontal_fov_to_radians(vertical_fov);
//     vertical_radius = calculate_vertical_radius(image_height, vertical_fov_rad);
// }

