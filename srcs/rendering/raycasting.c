#include "cub3d-bis.h"

// void draw_line(int x1, int y1, int x2, int y2, t_data *data) 
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx, sy, err, e2;
    
//     if (x1 < x2) sx = 1; else sx = -1;
//     if (y1 < y2) sy = 1; else sy = -1;
    
//     err = dx - dy;
    
//     while (1) 
//     {
//         // Dessiner le pixel
//         my_mlx_pixel_put(data->map2d, x1, y1, 0xffd55c);
        
//         if (x1 == x2 && y1 == y2) break;
        
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

// // Fonction pour dessiner une ligne à partir du joueur dans la direction actuelle de son regard
// void draw_line_from_player(t_data *data) 
// {
//     // Coordonnées de départ du joueur
//     int x1 = data->player->x_pos;
//     int y1 = data->player->y_pos;

//     // Longueur de la ligne (vous pouvez ajuster cette valeur selon vos besoins)
//     int line_length = get_ray_length(data->player);

//     // Calcul des coordonnées de fin de la ligne en utilisant la direction actuelle du joueur
//     int x2 = x1 + line_length * cos(data->player->angle * M_PI / 180.0);
//     int y2 = y1 + line_length * sin(data->player->angle * M_PI / 180.0);

//     // Dessiner la ligne
//     draw_line(x1, y1, x2, y2, data);
// }

// // RESSOURCES : 
// // Raycasting : https://lodev.org/cgtutor/raycasting.html
// // DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// // Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// // https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

// void perform_dda(t_data *data) 
// {
//     int hit = 0;
//     while (hit == 0) 
// 	{
//         if (data->ray->sidedist_x < data->ray->sidedist_y) 
// 		{
//             data->ray->sidedist_x += data->ray->dx;
//             data->ray->map_x += data->ray->step_x;
//             if (data->ray->step_x == -1)
// 				data->ray->side = 0;
// 			else
// 				data->ray->side = 1;
//         } 
// 		else 
// 		{
//             data->ray->sidedist_y += data->ray->dy;
//             data->ray->map_y += data->ray->step_y;
// 			if(data->ray->step_y == -1)
// 				data->ray->side = 2;
// 			else
// 				data->ray->side = 3;
//         }

// 		// Vérification des coordonnées du rayon pour la collision avec le mur
// 		if (data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE] != '0')
// 		{
// 			hit = 1;
// 			break;
// 		}
// 	}
// }

// void draw_ray(t_data *data) 
// {
//     int i;
//     int x, y;
//     float current_x;
//     float current_y;

//     get_steps(data);
//     if (data->ray->steps == 0)
//         return;

//     get_step_sizes(data);

//     // Utiliser les coordonnées du joueur pour initialiser les rayons
//     current_x = data->player->x_pos / TILE_SIZE;
//     current_y = data->player->y_pos / TILE_SIZE;

//     // Utiliser les coordonnées de début du rayon
//     x = data->ray->x1;
//     y = data->ray->y1;

//     i = 0;
//     while (i <= data->ray->steps) 
//     {
//         int hit_wall = 0; // Variable pour vérifier si un mur est touché
//         while (!hit_wall) // Continuer tant qu'aucun mur n'est touché
//         {
//             // perform_dda(data);
//             my_mlx_pixel_put(data->map2d, data->ray->map_x, data->ray->map_y, 0xffd55c);
// 			draw_line_from_player(data);
//             // Vérifier si un mur est touché
//             if (data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE] != '0')
// 			{
//                 hit_wall = 1;
// 				// printf("wall cordinates x = %d, y = %d\n", (int)data->ray->map_x / TILE_SIZE, (int)data->ray->map_y / TILE_SIZE);
// 			}
//         }

//         // Avancer le rayon d'un pas
//         current_x += data->ray->step_x;
//         current_y += data->ray->step_y;

//         // Mise à jour des coordonnées pour le prochain pas du rayon
//         x = (int)current_x;
//         y = (int)current_y;

//         i++;
//     }
// }


// // Trace des rayons depuis la position du joueur pour déterminer ce qu'il voit. 
// // Chaque rayon est tracé selon un certain angle, couvrant ainsi la player fov.
// // Le résultat de ce traçage est utilisé pour dessiner la scène 3D.
// void shoot_rays(t_data *data) 
// {
//     double start_angle;
//     double angle_increment;
//     double angle_rad;
//     int i;

//     start_angle = data->player->angle - (data->player->fov / 2.0);
//     angle_increment = data->player->fov / WINDOW_WIDTH;
    
// 	i = 0;
//     while (i < WINDOW_WIDTH) 
//     {
//         angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

// 		// Initialiser les données du rayon
//         init_rays(data, i);

//         // Calcul des coordonnées de fin du rayon (x2, y2)
//         data->ray->x2 = data->player->x_pos + cos(angle_rad) * data->ray->ray_length;
//         data->ray->y2 = data->player->y_pos + sin(angle_rad) * data->ray->ray_length;

// 		// Diviser par TILE_SIZE pour rester dans les limites de la carte
//     	data->ray->x2 /= TILE_SIZE;
//     	data->ray->y2 /= TILE_SIZE;

//         // Contrainte des coordonnées aux dimensions de la carte
//         if (data->ray->x2 < 0) 
//             data->ray->x2 = 0;
//         if (data->ray->x2 >= (MAP_WIDTH * TILE_SIZE)) 
//             data->ray->x2 = (MAP_WIDTH * TILE_SIZE) - 1;
//         if (data->ray->y2 < 0) 
//             data->ray->y2 = 0;
//         if (data->ray->y2 >= (MAP_HEIGHT * TILE_SIZE)) 
//             data->ray->y2 = (MAP_HEIGHT * TILE_SIZE) - 1;

//         // Initialiser les deltas pour le rayon
//         data->ray->dx = data->ray->x2 - data->player->x_pos;
//         data->ray->dy = data->ray->y2 - data->player->y_pos;

//         // Calcul des directions pour le rayon
//         data->ray->dir_x = cos(angle_rad);
//         data->ray->dir_y = sin(angle_rad);

//         draw_ray(data);
//         i++;
//     }
// }

// int raycasting(t_data *data) {
//     shoot_rays(data);
//     return 0;
// }

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
