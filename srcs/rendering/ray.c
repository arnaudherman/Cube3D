#include "cub3d-bis.h"

float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

// void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
// {
// 	for (int y = y_start; y < y_end; y++)
// 	{
// 		for (int x = x_start; x < x_end; x++)
// 		{
// 			my_mlx_pixel_put(image, x, y, 0xe19239);
// 		}
// 	}
// }

// void cast_ray(t_image *image, t_player *player) 
// {
//     int x_start;
// 	int x_end;
// 	int y_start;
// 	int y_end;
	
// 	x_start = (int)(player->x_pos);
//     y_start = (int)(player->y_pos);

// 	double angle_rad = player->angle * (M_PI / 180.0);
	
// 	x_end = x_start + (int)(cos(angle_rad) * RAY_LENGTH);
//     y_end = y_start + (int)(sin(angle_rad) * RAY_LENGTH);
// 	// x_end = x_start + 100;
//     // y_end = y_start + 100;

// 	// // To do : fin du rayon en fonction de l'angle du joueur
// 	// x_end = x_start + (int)cos(degrees_to_radians(player->angle)) * RAY_LENGTH;
//     // y_end = y_start + (int)sin(degrees_to_radians(player->angle)) * RAY_LENGTH;
// 	printf("before draw ray : x_end = %d, y_end = %d\n, angle = %f", x_end, y_end, player->angle);
//     draw_ray(image, x_start, y_start, x_end, y_end);
// }

// TEST
void fov_rays(int hauteur_image, int largeur_image, float fov_horizontal_deg) 
{
    // Convertir le FOV horizontal en radians
    float fov_horizontal_rad = fov_horizontal_deg * M_PI / 180.0;

    // Calculer le rayon horizontal nécessaire pour couvrir toute l'image
    float rayon_horizontal = largeur_image / (2.0 * tan(fov_horizontal_rad / 2.0));

    // Calculer le FOV vertical en fonction du rapport de l'image
    float fov_vertical_rad = 2.0 * atan(tan(fov_horizontal_rad / 2.0) * ((float)hauteur_image / largeur_image));
    float fov_vertical_deg = fov_vertical_rad * 180.0 / M_PI;

    // Calculer le rayon vertical nécessaire pour couvrir toute l'image
    float rayon_vertical = hauteur_image / (2.0 * tan(fov_vertical_rad / 2.0));

    // Afficher les résultats
    printf("Rayon horizontal nécessaire : %f\n", rayon_horizontal);
    printf("Rayon vertical nécessaire : %f\n", rayon_vertical);
    printf("FOV vertical calculé : %f degrés\n", fov_vertical_deg);
}

void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
{
    int x, y;
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    
    // Determine the sign of the step (i.e., +1 or -1) for each dimension
    int sign_x = (dx > 0) ? 1 : -1;
    int sign_y = (dy > 0) ? 1 : -1;
    
    // Determine the number of steps required along each dimension
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // Calculate the increment for each dimension per step
    float step_x = (float)dx / steps;
    float step_y = (float)dy / steps;
    
    // Initialize the starting position
    float current_x = x_start;
    float current_y = y_start;
    
    // Draw the ray by iterating through each step
    for (int i = 0; i <= steps; i++)
    {
        x = (int)current_x;
        y = (int)current_y;
        my_mlx_pixel_put(image, x, y, 0xe19239);
        
        // Move to the next position along each dimension
        current_x += step_x;
        current_y += step_y;
    }
}

void shoot_rays(t_image *image, t_player *player)
{
    // Angle de départ pour tirer les rayons
    double start_angle = player->angle - (player->fov / 2.0);
    
    // Angle entre chaque rayon
    double angle_increment = player->fov / WINDOW_WIDTH; // Un rayon par pixel sur l'écran

    // Tirer des rayons pour chaque pixel dans la FOV du joueur
    for (int i = 0; i < WINDOW_WIDTH; i++)
    {
        // Calculer l'angle pour ce rayon
        double angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);
        
        // Calculer les coordonnées de fin du rayon
        int x_end = (int)(player->x_pos + cos(angle_rad) * RAY_LENGTH);
        int y_end = (int)(player->y_pos + sin(angle_rad) * RAY_LENGTH);
        
        // Assurez-vous que les coordonnées de fin sont à l'intérieur des limites de la carte
        if (x_end < 0) x_end = 0;
        if (x_end >= (MAP_WIDTH * TILE_SIZE)) x_end = (MAP_WIDTH * TILE_SIZE) - 1;
        if (y_end < 0) y_end = 0;
        if (y_end >= (MAP_HEIGHT * TILE_SIZE)) y_end = (MAP_HEIGHT * TILE_SIZE) - 1;
        
        // Dessiner le rayon
        draw_ray(image, (int)(player->x_pos), (int)(player->y_pos), x_end, y_end);
    }
}




// void cast_ray(t_image *image, t_player *player) 
// {
//     int x_start, x_end, y_start, y_end;
    
//     x_start = (int)(player->x_pos);
//     y_start = (int)(player->y_pos);

//     double angle_rad = player->angle * (M_PI / 180.0);
    
//     x_end = x_start + (int)(cos(angle_rad) * RAY_LENGTH);
//     y_end = y_start + (int)(sin(angle_rad) * RAY_LENGTH);

// 	if (x_end < 0) x_end = 0;
//     if (x_end >= (MAP_WIDTH * 64)) x_end = (MAP_WIDTH * 64) - 1;
//     if (y_end < 0) y_end = 0;
//     if (y_end >= (MAP_HEIGHT * 64)) y_end = (MAP_HEIGHT * 64) - 1;
    
//     draw_ray(image, x_start, y_start, x_end, y_end);
// }
