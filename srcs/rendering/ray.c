#include "cub3d-bis.h"

float get_ray_length(int map_width, int map_height, int window_width, int window_height, float field_of_view) 
{
    // Convert the field of view from degrees to radians
    float fov_rad = field_of_view * M_PI / 180.0;

    // Calculate the horizontal and vertical field of view
    float horizontal_fov = fov_rad;
	// TO DO : check if use of atan2 is better
    float vertical_fov = 2.0 * atan(tan(fov_rad / 2.0) * ((float)window_height / window_width));

    // Calculate the horizontal and vertical ray lengths
    float horizontal_ray_length = map_width / (2.0 * tan(horizontal_fov / 2.0));
    float vertical_ray_length = map_height / (2.0 * tan(vertical_fov / 2.0));

    // Choose the larger of the two ray lengths
    float ray_length = (horizontal_ray_length > vertical_ray_length) ? horizontal_ray_length : vertical_ray_length;

    return ray_length;
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
void draw_ray(t_image *image, int x1, int y1, int x2, int y2, t_map *map, t_ray *ray,  t_data *data)
{
	int i;
    int x, y;
    int dx = x2 - x1;
    int dy = y2 - y1;

	// TO DO : delete ???
    // Determine the sign of the step (i.e., +1 or -1) for each dimension
    // int sign_x = (dx > 0) ? 1 : -1;
    // int sign_y = (dy > 0) ? 1 : -1;

    // Determine the number of steps required along each dimension
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment for each dimension per step
    float step_x = (float)dx / steps;
    float step_y = (float)dy / steps;

    // Initialize the starting position
    float current_x = x1;
    float current_y = y1;

    // Draw the ray by iterating through each step
	i = 0;
    while (i <= steps)
    {
        x = (int)current_x;
        y = (int)current_y;
		
		// Yooooo, here x = 240 and y = 240, divide by 64 to get the right position
        if (map->map2d[y / 64][x / 64] != '0')
        {
            printf("Wall found at (%d, %d)\n", (x / 64), (y / 64));
			draw_wall(data, x, y);
            break;
        }

        // Calculer la distance entre le point actuel du rayon et le joueur
        float distance = sqrt((current_x - x1) * (current_x - x1) + (current_y - y1) * (current_y - y1));

        my_mlx_pixel_put(image, x, y, 0xffd55c);

        // Move to the next position along each dimension
        current_x += step_x;
        current_y += step_y;
		i++;
    }
}

void shoot_rays(t_image *image, t_player *player, t_map *map, t_ray *ray, t_data *data)
{
	int i;
	double start_angle;
	double angle_increment;
	double angle_rad;

    // Start angle to shoot my rays
    start_angle = player->angle - (player->fov / 2.0);
    
    // Angle bewteen each ray (one ray per pixel in the FOV of the player)
    angle_increment = player->fov / WINDOW_WIDTH;

	i = 0;
    while (i < WINDOW_WIDTH)
    {
        // Calculer l'angle pour ce rayon
        angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);
        
        // Calculer les coordonnées de fin du rayon
        int x_end = (int)(player->x_pos + cos(angle_rad) * ray->ray_length);
        int y_end = (int)(player->y_pos + sin(angle_rad) * ray->ray_length);
        
        // Assurez-vous que les coordonnées de fin sont à l'intérieur des limites de la carte
        if (x_end < 0) x_end = 0;
        if (x_end >= (MAP_WIDTH * TILE_SIZE)) x_end = (MAP_WIDTH * TILE_SIZE) - 1;
        if (y_end < 0) y_end = 0;
        if (y_end >= (MAP_HEIGHT * TILE_SIZE)) y_end = (MAP_HEIGHT * TILE_SIZE) - 1;
        
        draw_ray(image, (int)(player->x_pos), (int)(player->y_pos), x_end, y_end, map, ray, data);
		i++;
    }
}

int raycasting(t_data *data)
{
	printf("angle, %f\n", data->player->angle);
	printf("fov, %f\n", data->player->fov);
	shoot_rays(data->image, data->player, &data->map, data->ray, data);
	// cast_ray(data->image, data->player);	
	return 0;
}