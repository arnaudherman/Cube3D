#include "cub3d-bis.h"

void fov_rays(int hauteur_image, int largeur_image, float fov_horizontal_deg) 
{
    
    float fov_horizontal_rad;
	float rayon_horizontal;
	float fov_vertical_rad;
	float fov_vertical_deg;
	float rayon_vertical;

	// Converti ma FOV horizontal en radians
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

void calculate_steps(int x1, int y1, int x2, int y2, int *dx, int *dy, int *steps) 
{
    *dx = x2 - x1;
    *dy = y2 - y1;
    *steps = abs(*dx) > abs(*dy) ? abs(*dx) : abs(*dy);
}

void calculate_step_sizes(int dx, int dy, float *step_x, float *step_y, int steps) 
{
    *step_x = (float)dx / steps;
    *step_y = (float)dy / steps;
}

char get_wall_direction(int x, int y, t_map *map) {
    return map->map2d[y / TILE_SIZE][x / TILE_SIZE];
}

int calculate_wall_height(float current_x, float current_y, int x1, int y1, t_ray *ray, t_data *data) {
    float distance = sqrt((current_x - x1) * (current_x - x1) + (current_y - y1) * (current_y - y1));
    if (distance == 0) {
        distance = 1.0;  // Prévenir la division par zéro
    }
    ray->wall_dist = distance;
    int corrected_distance = correct_fisheye(distance, data->ray->angle, data->player->angle);
    if (corrected_distance == 0) {
        corrected_distance = 1;  // Prévenir la division par zéro
    }
    return (int)(WALL_HEIGHT / corrected_distance);
}

int get_wall_top(int wall_height) {
    return (WINDOW_HEIGHT / 2) - (wall_height / 2);
}

void draw_ray(t_image *map2d, t_image *world, int x1, int y1, int x2, int y2, t_map *map, t_ray *ray, t_data *data) {
    int i;
    int x, y;
    int dx, dy;
    int steps;
    float step_x;
    float step_y;
    float current_x;
    float current_y;

    calculate_steps(x1, y1, x2, y2, &dx, &dy, &steps);
    if (steps == 0) {
        return;
    }

    calculate_step_sizes(dx, dy, &step_x, &step_y, steps);

    current_x = x1;
    current_y = y1;

    i = 0;
    while (i <= steps) {
        x = (int)current_x;
        y = (int)current_y;

		// if (draw_3d_world(map, world, x, y, current_x, current_y, x1, y1, ray, data))
		// 	break;
		// draw_wall(data, &ray);
        my_mlx_pixel_put(map2d, x, y, 0xffd55c);

        current_x += step_x;
        current_y += step_y;
        i++;
    }
}

void shoot_rays(t_image *map2d, t_image *world, t_player *player, t_map *map, t_ray *ray, t_data *data) {
    double start_angle;
	double angle_increment;
	double angle_rad;
	int i;
	int x_end;
	int y_end;

	start_angle = player->angle - (player->fov / 2.0);
    angle_increment = player->fov / WINDOW_WIDTH;
	i = 0;
    while (i < WINDOW_WIDTH) {
        angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

        x_end = (int)(player->x_pos + cos(angle_rad) * ray->ray_length);
        y_end = (int)(player->y_pos + sin(angle_rad) * ray->ray_length);

        if (x_end < 0) x_end = 0;
        if (x_end >= (MAP_WIDTH * TILE_SIZE)) x_end = (MAP_WIDTH * TILE_SIZE) - 1;
        if (y_end < 0) y_end = 0;
        if (y_end >= (MAP_HEIGHT * TILE_SIZE)) y_end = (MAP_HEIGHT * TILE_SIZE) - 1;

        draw_ray(map2d, world, (int)(player->x_pos), (int)(player->y_pos), x_end, y_end, map, ray, data);
		i++;
    }
}

int raycasting(t_data *data) {
    shoot_rays(data->map2d, data->world, data->player, &data->map, data->ray, data);
    return 0;
}


// Bresenham Algorithm Test
// void draw_ray(t_image *map2d, t_image *world, int x1, int y1, int x2, int y2, t_map *map, t_ray *ray, t_data *data)
// {
//     int x, y;
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1; 
//     int err = dx - dy;
//     int e2;

//     while (1) 
//     {
//         // Trace le pixel sur la carte 2D
//         my_mlx_pixel_put(map2d, x1, y1, 0xffd55c);

//         // Vérifie si le rayon a rencontré un mur
//         if (map->map2d[y1 / TILE_SIZE][x1 / TILE_SIZE] != '0') 
//         {
//             // Calcule la distance au mur
//             float distance = sqrt((x1 - x1) * (x1 - x1) + (y1 - y1) * (y1 - y1));
//             ray->wall_dist = distance;
//             ray->wall_height = (int)(WALL_HEIGHT / distance);

//             // Dessine la colonne de mur correspondante dans le monde 3D
//             draw_wall_column(world, x1, ray->wall_height);
//             break;
//         }

//         // Si le rayon atteint la position finale (aucun mur rencontré), sortir de la boucle
//         if (x1 == x2 && y1 == y2) 
//             break;

//         // Calcul de l'erreur pour décider du prochain pixel à tracer
//         e2 = 2 * err;
//         if (e2 > -dy) 
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) 
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }