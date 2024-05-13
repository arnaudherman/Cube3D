#include "cub3d-bis.h"

// CONVERSION BETWEEN DEGRESS AND RADIANS
float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

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

// DRAW RAY SUCCESS
void draw_ray(t_image *image, int x1, int y1, int x2, int y2, t_map *map)
{
    int x, y;
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Determine the sign of the step (i.e., +1 or -1) for each dimension
    int sign_x = (dx > 0) ? 1 : -1;
    int sign_y = (dy > 0) ? 1 : -1;

    // Determine the number of steps required along each dimension
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment for each dimension per step
    float step_x = (float)dx / steps;
    float step_y = (float)dy / steps;

    // Initialize the starting position
    float current_x = x1;
    float current_y = y1;

	// TO DO : x2 and y2 already passed in paramater
    // int x2 = x1 + (int)data->ray->dx;
    // int y2 = y1 + (int)data->ray->dy;

    // Couleur de départ et de fin pour le dégradé
    int color_start = 0xffd55c; // Jaune
    int color_end = 0xffff80; // Vert

    // Draw the ray by iterating through each step
    for (int i = 0; i <= steps; i++)
    {
        x = (int)current_x;
        y = (int)current_y;
		
		// Yooooo, here x = 240 and y = 240, divide by 64 to get the right position
        if (map->map2d[y / 64][x / 64] != '0')
        {
            printf("Wall found at (%d, %d)\n", x, y);
            break;
        }

        // Calculer la distance entre le point actuel du rayon et le joueur
        float distance = sqrt((current_x - x1) * (current_x - x1) + (current_y - y1) * (current_y - y1));

        // Calculer le dégradé de couleur en fonction de la distance
        int red = ((color_start >> 16) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 16) & 0xFF) * (distance / RAY_LENGTH);
        int green = ((color_start >> 8) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 8) & 0xFF) * (distance / RAY_LENGTH);
        int blue = (color_start & 0xFF) * (1 - distance / RAY_LENGTH) + (color_end & 0xFF) * (distance / RAY_LENGTH);
        int color = (red << 16) | (green << 8) | blue;

        // Dessiner le pixel avec la couleur calculée
        my_mlx_pixel_put(image, x, y, color);

        // Move to the next position along each dimension
        current_x += step_x;
        current_y += step_y;
    }
}

void shoot_rays(t_image *image, t_player *player, t_map *map)
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
        draw_ray(image, (int)(player->x_pos), (int)(player->y_pos), x_end, y_end, map);
    }
}
