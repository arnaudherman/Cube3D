#include "cub3d-bis.h"

float get_ray_length(int map_width, int map_height, int window_width, int window_height) 
{
    // Convert the field of view from degrees to radians
    float fov_rad = FOV * M_PI / 180.0;

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

void draw_ray(t_image *map2d, t_image *world, int x1, int y1, int x2, int y2, t_map *map, t_ray *ray, t_data *data) {
    int i;
	int x, y;
    int dx, dy;
	int steps;
	float step_x;
	float step_y;
	float current_x;
	float current_y;
	float distance;
	int corrected_distance;

	dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    if (steps == 0) {
        return;
    }

    step_x = (float)dx / steps;
    step_y = (float)dy / steps;

    current_x = x1;
    current_y = y1;

	i = 0;
    while (i <= steps) {
        x = (int)current_x;
        y = (int)current_y;

        if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] != '0') {
            distance = sqrt((current_x - x1) * (current_x - x1) + (current_y - y1) * (current_y - y1));
            if (distance == 0) {
                distance = 1.0;  // Prevent division by zero
            }
            ray->wall_dist = distance;
            corrected_distance = correct_fisheye(distance, data->ray->angle, data->player->angle);
            if (corrected_distance == 0) {
                corrected_distance = 1;  // Prevent division by zero
            }
            ray->wall_height = (int)(WALL_HEIGHT / corrected_distance);

			// TO DO : extern function for wall direction
			// Determine the direction of the wall (example, you may need to adapt this part)
			char wall_dir = map->map2d[y / TILE_SIZE][x / TILE_SIZE];

			// TO DO : extern function for wall top
            int wall_top = (WINDOW_HEIGHT / 2) - (ray->wall_height / 2);

			// // TO DO : extern function to draw the wall column with texture
            // render_wall_texture(world, x * TILE_SIZE, ray->wall_height, wall_top, /*&*/data->texture, wall_dir);
            // break;

			// TO DO : delete soon because of render_wall_texture
            draw_wall_column(world, x * TILE_SIZE, ray->wall_height);
            break;
        }

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
