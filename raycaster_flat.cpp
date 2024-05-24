#include "cub3d-bis.h"

void launch_dda(t_data *data) 
{
    int hit = 0;
    while (hit == 0) 
    {
        if (data->ray->dx < data->ray->dy) 
        {
            data->ray->dx += data->ray->dx;
            data->ray->map_x += data->ray->step_x;
            data->ray->side = (data->ray->step_x == -1) ? 0 : 1;
        } 
        else 
        {
            data->ray->dy += data->ray->dy;
            data->ray->map_y += data->ray->step_y;
            data->ray->side = (data->ray->step_y == -1) ? 2 : 3;
        }

        // Vérification des coordonnées du rayon pour la collision avec le mur
        if (data->map.map2d[(int)data->ray->map_y][(int)data->ray->map_x] != '0') {
            hit = 1;
            break;
        }
    }
}

void draw_ray(t_data *data) 
{
    double distance;
    int corrected_distance;

    // Appeler launch_dda pour détecter les collisions
    launch_dda(data);

    // Calculer la distance et les propriétés du mur
    distance = sqrt((data->ray->map_x - data->ray->x1) * (data->ray->map_x - data->ray->x1) + 
                    (data->ray->map_y - data->ray->y1) * (data->ray->map_y - data->ray->y1));
    if (distance == 0) distance = 1.0;  // Prevent division by zero
    data->ray->wall_dist = distance;
    corrected_distance = distance * cos(data->ray->angle - data->player->angle);
    if (corrected_distance == 0) 
		corrected_distance = 1;  // Prevent division by zero
    data->ray->wall_height = (int)(WALL_HEIGHT / corrected_distance);

    // Dessiner la colonne du mur
    draw_wall_column(data, data->ray->map_x * TILE_SIZE, (int)data->ray->wall_height);
}

void shoot_rays(t_data *data) 
{
    double start_angle;
    double angle_increment;
    double angle_rad;
    int i;

    start_angle = data->player->angle - (data->player->fov / 2.0);
    angle_increment = data->player->fov / WINDOW_WIDTH;

	i = 0;
    while (i < WINDOW_WIDTH) 
    {
        angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

        // Initialiser les rayons 
        init_one_ray(data, i);

        // Calcul des coordonnées de fin du rayon (x2, y2)
        data->ray->x2 = data->player->x_pos + cos(angle_rad) * data->ray->ray_length;
        data->ray->y2 = data->player->y_pos + sin(angle_rad) * data->ray->ray_length;

        // Diviser par TILE_SIZE pour rester dans les limites de la carte
        data->ray->x2 /= TILE_SIZE;
        data->ray->y2 /= TILE_SIZE;

        // Contrainte des coordonnées aux dimensions de la carte
        if (data->ray->x2 < 0) 
			data->ray->x2 = 0;
        if (data->ray->x2 >= MAP_WIDTH) 
			data->ray->x2 = MAP_WIDTH - 1;
        if (data->ray->y2 < 0) 
			data->ray->y2 = 0;
        if (data->ray->y2 >= MAP_HEIGHT) 
			data->ray->y2 = MAP_HEIGHT - 1;

        // Initialiser les deltas pour le rayon
        data->ray->dx = fabs(data->ray->x2 - data->player->x_pos);
        data->ray->dy = fabs(data->ray->y2 - data->player->y_pos);

        // Calcul des directions pour le rayon
        data->ray->dir_x = cos(angle_rad);
        data->ray->dir_y = sin(angle_rad);

        // Appeler draw_ray pour tracer le rayon et dessiner la scène
        draw_ray(data);
		i++;
    }
}

void draw_wall_column(t_data *data, int column)
{
	int top;
	int bottom;
	int y;

    top = (WINDOW_HEIGHT - data->ray->wall_height) / 2;
    bottom = top + data->ray->wall_height;

    if (top < 0)
		top = 0;
    if (bottom >= WINDOW_HEIGHT)
		bottom = WINDOW_HEIGHT - 1;

	y = top;
    while (y <= bottom)
    {
        my_mlx_pixel_put(data->world, column, y, 0x451800);
		y++;
    }
}

int raycasting(t_data *data) {
    shoot_rays(data);
    return 0;
}
