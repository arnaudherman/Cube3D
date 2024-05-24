#include "cub3d-bis.h"

// RESSOURCES : 
// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

void draw_line_to_wall(t_data *data) 
{
    double x = data->player->x_pos;
    double y = data->player->y_pos;
    int hit = 0;

    while (!hit) {
        // Calculate end coordinates of the ray (x2, y2)
        double x2 = x + cos(data->ray->angle) * data->ray->ray_length;
        double y2 = y + sin(data->ray->angle) * data->ray->ray_length;

        // Convert to grid coordinates
        int map_x = (int)(x2 / TILE_SIZE);
        int map_y = (int)(y2 / TILE_SIZE);

        // Check map boundaries
        if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
            break;

        // Check collision with a wall
        if (data->map.map2d[map_y][map_x] != '0') {
            hit = 1;
            break;
        }

        // Draw a line from the player's current position (x, y) to the next ray position (x2, y2)
        draw_line(data->player->x_pos, data->player->y_pos, x2, y2);

        // Advance along the ray
        x = x2;
        y = y2;
    }
}

void draw_ray_until_wall(t_data *data, double angle_rad) {
    double x = data->player->x_pos;
    double y = data->player->y_pos;
    int hit = 0;

    while (!hit) {
        // Calcul des coordonnées de fin du rayon (x2, y2)
        double x2 = x + cos(angle_rad) * data->ray->ray_length;
        double y2 = y + sin(angle_rad) * data->ray->ray_length;

        // Conversion en coordonnées de grille
        int map_x = (int)(x2 / TILE_SIZE);
        int map_y = (int)(y2 / TILE_SIZE);

        // Vérification des limites de la carte
        if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
            break;

        // Vérification de la collision avec un mur
        if (data->map.map2d[map_y][map_x] != '0') {
            hit = 1;
            break;
        }

        // Dessiner une ligne du joueur à la position actuelle (x, y)
        // jusqu'à la position du rayon suivant (x2, y2)
        draw_line(data->player->x_pos, data->player->y_pos, x2, y2);

        // Avancer le long du rayon
        x = x2;
        y = y2;
    }
}

void perform_dda(t_data *data) 
{
    int hit = 0;
    while (hit == 0) 
	{
        if (data->ray->sidedist_x < data->ray->sidedist_y) 
		{
            data->ray->sidedist_x += data->ray->dx;
            data->ray->map_x += data->ray->step_x;
            if (data->ray->step_x == -1)
				data->ray->side = 0;
			else
				data->ray->side = 1;
        } 
		else 
		{
            data->ray->sidedist_y += data->ray->dy;
            data->ray->map_y += data->ray->step_y;
			if(data->ray->step_y == -1)
				data->ray->side = 2;
			else
				data->ray->side = 3;
        }

		// Vérification des coordonnées du rayon pour la collision avec le mur
		if (data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE] != '0')
		{
			hit = 1;
			printf("Wall hit at x = %d, y = %d\n", (int)data->ray->map_x, (int)data->ray->map_y);
			break;
		}
	}
}
// DDA perform version
void draw_ray(t_data *data) 
{
    int x, y;
    float distance;
    int corrected_distance;
    // int wall_top;
    // char wall_dir;

    // Update Deltas
    data->ray->dx = abs(data->ray->x2 - data->ray->x1);
    data->ray->dy = abs(data->ray->y2 - data->ray->y1);

    // Calculate steps and step sizes
    data->ray->steps = abs(data->ray->dx) > abs(data->ray->dy) ? abs(data->ray->dx) : abs(data->ray->dy);
    if (data->ray->steps == 0)
        return;

    get_step_sizes(data);
	
    // Initialiser les rayons
    data->ray->map_x = (int)(data->ray->x1);
    data->ray->map_y = (int)(data->ray->y1);

    // Appeler perform_dda pour détecter les collisions
    perform_dda(data);
    // Calculer la distance et les propriétés du mur
    distance = sqrt((data->ray->map_x - data->ray->x1) * (data->ray->map_x - data->ray->x1) + (data->ray->map_y - data->ray->y1) * (data->ray->map_y - data->ray->y1));
    if (distance == 0) 
        distance = 1.0;  // Prevent division by zero
    data->ray->wall_dist = distance;
    corrected_distance = correct_fisheye(distance, data->ray->angle, data->player->angle);
    if (corrected_distance == 0) 
        corrected_distance = 1;  // Prevent division by zero
    data->ray->wall_height = (int)(WALL_HEIGHT / corrected_distance);

    // // Determine the direction of the wall
    // wall_dir = data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE];

    // // Calculate the top of the wall
    // wall_top = (WINDOW_HEIGHT / 2) - (data->ray->wall_height / 2);

    // Draw the wall column
    // draw_wall_column(data->world, data->ray->map_x * TILE_SIZE, data->ray->wall_height);
    draw_wall(data);
}

// Trace des rayons depuis la position du joueur pour déterminer ce qu'il voit. 
// Chaque rayon est tracé selon un certain angle, couvrant ainsi la player fov.
// Le résultat de ce traçage est utilisé pour dessiner la scène 3D.
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

		// ICI je vais initialiser les rayons 
        init_rays(data, i);

        // Calcul des coordonnées de fin du rayon (x2, y2)
        data->ray->x2 = data->player->x_pos + cos(angle_rad) * data->ray->ray_length;
        data->ray->y2 = data->player->y_pos + sin(angle_rad) * data->ray->ray_length;

		// Diviser par TILE_SIZE pour rester dans les limites de la carte
    	data->ray->x2 /= TILE_SIZE;
    	data->ray->y2 /= TILE_SIZE;

        // Contrainte des coordonnées aux dimensions de la carte
        if (data->ray->x2 < 0) 
            data->ray->x2 = 0;
        if (data->ray->x2 >= (MAP_WIDTH * TILE_SIZE)) 
            data->ray->x2 = (MAP_WIDTH * TILE_SIZE) - 1;
        if (data->ray->y2 < 0) 
            data->ray->y2 = 0;
        if (data->ray->y2 >= (MAP_HEIGHT * TILE_SIZE)) 
            data->ray->y2 = (MAP_HEIGHT * TILE_SIZE) - 1;

        // Initialiser les deltas pour le rayon
        data->ray->dx = data->ray->x2 - data->player->x_pos;
        data->ray->dy = data->ray->y2 - data->player->y_pos;

        // Calcul des directions pour le rayon
        data->ray->dir_x = cos(angle_rad);
        data->ray->dir_y = sin(angle_rad);
        draw_ray(data);
        i++;
    }
}

int raycasting(t_data *data) {
    shoot_rays(data);
    return 0;
}
