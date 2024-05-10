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

// static void draw_ray(t_data *data)
// {
//     float xinc;
//     float yinc;
//     float step;
//     float distance;
//     int i;

//     int x1 = (int)data->player->x_pos;
//     int y1 = (int)data->player->y_pos;

//     data->ray->dx = cos(data->player->angle);
//     data->ray->dy = sin(data->player->angle);

//     int x2 = x1 + (int)data->ray->dx;
//     int y2 = y1 + (int)data->ray->dy;

//     if(abs(data->ray->dx) > abs(data->ray->dy))
//         step = abs(data->ray->dx);
//     else 
//         step = abs(data->ray->dy);

//     // Vérifier si la valeur de step est nulle pour éviter une division par zéro
//     if (step == 0)
//     {
//         xinc = 0;
//         yinc = 0;
//     }
//     else
//     {
//         // Calculer les incréments pour x et y
//         xinc = (float)data->ray->dx / step;
//         yinc = (float)data->ray->dy / step;
//     }

//     i = 0;
//     while (i < step)
//     {
//         if (data->map.map2d[(int)y1][(int)x1] != '0')
//         {
//             printf("Wall found at (%d, %d)\n", (int)x1, (int)y1);
//             break;
//         }

//         // Calculer la distance entre le point actuel du rayon et le joueur
//         distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

//         // En fonction de la couleur calculée par ma fonction ray_color();
//         my_mlx_pixel_put(&data->image, x1, y1, ray_color(distance));
//         x1 += xinc;
//         y1 += yinc;
//         i++;
//     }
//     // Dessiner les points de contact si un mur est trouvé
//     my_mlx_pixel_put(&data->image, (int)x1, (int)y1, 0xBDEDDF);
// }

// void shoot_rays(t_data *data)
// {
//     // Angle de départ pour tirer les rayons
//     double start_angle = data->player->angle - (data->player->fov / 2.0);
    
//     // Angle entre chaque rayon
//     double angle_increment = data->player->fov / WINDOW_WIDTH; // Un rayon par pixel sur l'écran

//     // Tirer des rayons pour chaque pixel dans la FOV du joueur
//     for (int i = 0; i < WINDOW_WIDTH; i++)
//     {
//         // Calculer l'angle pour ce rayon
//         double angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);
        
//         // Calculer les coordonnées de fin du rayon
//         int x_end = (int)(data->player->x_pos + cos(angle_rad) * RAY_LENGTH);
//         int y_end = (int)(data->player->y_pos + sin(angle_rad) * RAY_LENGTH);
        
//         // Assurez-vous que les coordonnées de fin sont à l'intérieur des limites de la carte
//         if (x_end < 0) x_end = 0;
//         if (x_end >= (MAP_WIDTH * TILE_SIZE)) x_end = (MAP_WIDTH * TILE_SIZE) - 1;
//         if (y_end < 0) y_end = 0;
//         if (y_end >= (MAP_HEIGHT * TILE_SIZE)) y_end = (MAP_HEIGHT * TILE_SIZE) - 1;
        
//         // Mettre à jour les coordonnées du joueur
//         data->player->x_pos = x_end;
//         data->player->y_pos = y_end;
        
//         // Dessiner le rayon
//         draw_ray(data);
//     }
// }

void draw_ray(t_data *data, int x_start, int y_start, int x_end, int y_end)
{
    // Gestion des indices de tableau
    if (x_start < 0 || x_start >= data->map.w_map || y_start < 0 || y_start >= data->map.h_map) return;
    
    int dx = x_end - x_start;
    int dy = y_end - y_start;

    // Determine the sign of the step (i.e., +1 or -1) for each dimension
    int sign_x = (dx > 0) ? 1 : -1;
    int sign_y = (dy > 0) ? 1 : -1;

    // Determine the number of steps required along each dimension
    unsigned int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment for each dimension per step
    float step_x = (float)dx / steps;
    float step_y = (float)dy / steps;

    // Initialize the starting position
    float current_x = x_start;
    float current_y = y_start;

    // Couleur de départ et de fin pour le dégradé
    int color_start = 0xffd55c; // Jaune
    int color_end = 0xffff80; // Vert

    // Calculer la distance entre le point de départ et d'arrivée du rayon
    float distance = sqrt(dx * dx + dy * dy);

    // Draw the ray by iterating through each step
    for (unsigned int i = 0; i <= steps; i++)
    {
        int x = (int)current_x;
        int y = (int)current_y;

        // Check for intersection with walls using DDA algorithm
        if (data->map.map2d[y][x] != '0')
        {
            printf("Wall found at (%d, %d)\n", x, y);
            break;
        }

        // Calculer le dégradé de couleur en fonction de la distance
        int red = ((color_start >> 16) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 16) & 0xFF) * (distance / RAY_LENGTH);
        int green = ((color_start >> 8) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 8) & 0xFF) * (distance / RAY_LENGTH);
        int blue = (color_start & 0xFF) * (1 - distance / RAY_LENGTH) + (color_end & 0xFF) * (distance / RAY_LENGTH);
        int color = (red << 16) | (green << 8) | blue;

        // Dessiner le pixel avec la couleur calculée
        my_mlx_pixel_put(data->image, x, y, color);

        // Move to the next position along each dimension
        current_x += step_x;
        current_y += step_y;
    }
}


void shoot_rays(t_data *data)
{
    if (data == NULL) return; // Vérifier les paramètres
    
    // Angle de départ pour tirer les rayons
    double start_angle = data->player->angle - (data->player->fov / 2.0);
    
    // Angle entre chaque rayon
    double angle_increment = data->player->fov / WINDOW_WIDTH; // Un rayon par pixel sur l'écran

    // Tirer des rayons pour chaque pixel dans la FOV du joueur
    for (unsigned int i = 0; i < WINDOW_WIDTH; i++)
    {
        // Calculer l'angle pour ce rayon
        double angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);
        
        // Calculer les coordonnées de fin du rayon
        int x_end = (int)(data->player->x_pos + cos(angle_rad) * RAY_LENGTH);
        int y_end = (int)(data->player->y_pos + sin(angle_rad) * RAY_LENGTH);
        
        // Assurez-vous que les coordonnées de fin sont à l'intérieur des limites de la carte
        if (x_end < 0) x_end = 0;
        if (x_end >= data->map.w_map) x_end = data->map.w_map - 1;
        if (y_end < 0) y_end = 0;
        if (y_end >= data->map.h_map) y_end = data->map.h_map - 1;
        
        // Dessiner le rayon
        draw_ray(data, (int)(data->player->x_pos), (int)(data->player->y_pos), x_end, y_end);
    }
}



// WORKING Z NOT DELETE
// IMPLEMENT DDA ALGORITHM FOR RAYCASTING
// void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end, t_data *data)
// {
//     int x, y;
//     int dx = x_end - x_start;
//     int dy = y_end - y_start;

//     // Determine the sign of the step (i.e., +1 or -1) for each dimension
//     int sign_x = (dx > 0) ? 1 : -1;
//     int sign_y = (dy > 0) ? 1 : -1;

//     // Determine the number of steps required along each dimension
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     // Calculate the increment for each dimension per step
//     float step_x = (float)dx / steps;
//     float step_y = (float)dy / steps;

//     // Initialize the starting position
//     float current_x = x_start;
//     float current_y = y_start;

//     // Couleur de départ et de fin pour le dégradé
//     int color_start = 0xffd55c; // Jaune
//     int color_end = 0xffff80; // Vert

//     // Draw the ray by iterating through each step
//     for (int i = 0; i <= steps; i++)
//     {
//         x = (int)current_x;
//         y = (int)current_y;

//         // Check for intersection with walls using DDA algorithm
//         if (data->map.map2d[y][x] != '0')
//         {
//             printf("Wall found at (%d, %d)\n", x, y);
//             break;
//         }

//         // Calculer la distance entre le point actuel du rayon et le joueur
//         float distance = sqrt((current_x - x_start) * (current_x - x_start) + (current_y - y_start) * (current_y - y_start));

//         // Calculer le dégradé de couleur en fonction de la distance
//         int red = ((color_start >> 16) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 16) & 0xFF) * (distance / RAY_LENGTH);
//         int green = ((color_start >> 8) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 8) & 0xFF) * (distance / RAY_LENGTH);
//         int blue = (color_start & 0xFF) * (1 - distance / RAY_LENGTH) + (color_end & 0xFF) * (distance / RAY_LENGTH);
//         int color = (red << 16) | (green << 8) | blue;

//         // Dessiner le pixel avec la couleur calculée
//         my_mlx_pixel_put(image, x, y, color);

//         // Move to the next position along each dimension
//         current_x += step_x;
//         current_y += step_y;
//     }
// }


// // WORKING Z NOT DELETE
// void shoot_rays(t_image *image, t_player *player)
// {
//     // Angle de départ pour tirer les rayons
//     double start_angle = player->angle - (player->fov / 2.0);
    
//     // Angle entre chaque rayon
//     double angle_increment = player->fov / WINDOW_WIDTH; // Un rayon par pixel sur l'écran

//     // Tirer des rayons pour chaque pixel dans la FOV du joueur
//     for (int i = 0; i < WINDOW_WIDTH; i++)
//     {
//         // Calculer l'angle pour ce rayon
//         double angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);
        
//         // Calculer les coordonnées de fin du rayon
//         int x_end = (int)(player->x_pos + cos(angle_rad) * RAY_LENGTH);
//         int y_end = (int)(player->y_pos + sin(angle_rad) * RAY_LENGTH);
        
//         // Assurez-vous que les coordonnées de fin sont à l'intérieur des limites de la carte
//         if (x_end < 0) x_end = 0;
//         if (x_end >= (MAP_WIDTH * TILE_SIZE)) x_end = (MAP_WIDTH * TILE_SIZE) - 1;
//         if (y_end < 0) y_end = 0;
//         if (y_end >= (MAP_HEIGHT * TILE_SIZE)) y_end = (MAP_HEIGHT * TILE_SIZE) - 1;
        
//         // Dessiner le rayon
//         draw_ray(image, (int)(player->x_pos), (int)(player->y_pos), x_end, y_end);
//     }
// }

// NOT DELETE
// void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
// {
//     int x, y;
//     int dx = x_end - x_start;
//     int dy = y_end - y_start;
    
//     // Determine the sign of the step (i.e., +1 or -1) for each dimension
//     int sign_x = (dx > 0) ? 1 : -1;
//     int sign_y = (dy > 0) ? 1 : -1;
    
//     // Determine the number of steps required along each dimension
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
//     // Calculate the increment for each dimension per step
//     float step_x = (float)dx / steps;
//     float step_y = (float)dy / steps;
    
//     // Initialize the starting position
//     float current_x = x_start;
//     float current_y = y_start;

//     // Couleur de départ et de fin pour le dégradé
//     int color_start = 0xffd55c; // Jaune
//     int color_end = 0xffff80; // Vert

//     // Draw the ray by iterating through each step
//     for (int i = 0; i <= steps; i++)
//     {
//         x = (int)current_x;
//         y = (int)current_y;

//         // Calculer la distance entre le point actuel du rayon et le joueur
//         float distance = sqrt((current_x - x_start) * (current_x - x_start) + (current_y - y_start) * (current_y - y_start));
        
//         // Calculer le dégradé de couleur en fonction de la distance
//         int red = ((color_start >> 16) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 16) & 0xFF) * (distance / RAY_LENGTH);
//         int green = ((color_start >> 8) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 8) & 0xFF) * (distance / RAY_LENGTH);
//         int blue = (color_start & 0xFF) * (1 - distance / RAY_LENGTH) + (color_end & 0xFF) * (distance / RAY_LENGTH);
//         int color = (red << 16) | (green << 8) | blue;
        
//         // Dessiner le pixel avec la couleur calculée
//         my_mlx_pixel_put(image, x, y, color);
        
//         // Move to the next position along each dimension
//         current_x += step_x;
//         current_y += step_y;
//     }
// }



// NOT DELETE
// void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
// {
//     int x, y;
//     int dx = x_end - x_start;
//     int dy = y_end - y_start;
    
//     // Determine the sign of the step (i.e., +1 or -1) for each dimension
//     int sign_x = (dx > 0) ? 1 : -1;
//     int sign_y = (dy > 0) ? 1 : -1;
    
//     // Determine the number of steps required along each dimension
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
//     // Calculate the increment for each dimension per step
//     float step_x = (float)dx / steps;
//     float step_y = (float)dy / steps;
    
//     // Initialize the starting position
//     float current_x = x_start;
//     float current_y = y_start;
    
//     // Draw the ray by iterating through each step
//     for (int i = 0; i <= steps; i++)
//     {
//         x = (int)current_x;
//         y = (int)current_y;
//         my_mlx_pixel_put(image, x, y, 0xe19239);
        
//         // Move to the next position along each dimension
//         current_x += step_x;
//         current_y += step_y;
//     }
// }

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

