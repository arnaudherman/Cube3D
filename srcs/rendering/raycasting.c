#include "cub3d-bis.h"

// RESSOURCES : 
// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

void perform_dda(t_ray *ray, t_map *map) 
{
    int hit = 0;
    while (hit == 0) 
	{
        if (ray->sidedist_x < ray->sidedist_y) 
		{
            ray->sidedist_x += ray->dx;
            ray->map_x += ray->x1 * TILE_SIZE;
			if (ray->x1 == -1)
				ray->side = 0;
			else
				ray->side = 1;
        } else {
            ray->sidedist_y += ray->dy;
            ray->map_y += ray->y1 * TILE_SIZE;
			if (ray->y1 == -1)
			{
				ray->side = 2;
				printf("c debug this shit\n");
			}
				
			else
			{
				ray->side = 3;
				printf("d debug this shit\n");
			}
        }
		printf("5 debug this shit\n");
		// TO DO : CORRECT FUCKING PROBLEM HERE
		// TO DO : use of ray->map_x or ray->map_y really ?
		// Previous function was : if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] != '0')
		if (map->map2d[(int)ray->map_y][(int)ray->map_x] != '0')
		printf(" 6 mamamia debug this shit\n");
			hit = 1;
    }
}


void draw_ray(t_data *data) 
{
    int i;
    int x, y;
    float current_x;
    float current_y;

    get_steps(data);
    if (data->ray->steps == 0)
        return;

    get_step_sizes(data);

    // Utiliser les coordonnées du joueur pour initialiser les rayons
    current_x = data->player->x_pos / TILE_SIZE;
    current_y = data->player->y_pos / TILE_SIZE;

    i = 0;
    while (i <= data->ray->steps) 
    {
        x = (int)current_x;
        y = (int)current_y;

        // Vérifier si le rayon a touché un mur
        if (data->map.map2d[y / TILE_SIZE][x / TILE_SIZE] != '0') 
        {
            // Vous pouvez dessiner le mur ou effectuer une autre action ici
            // draw_wall(data, ray);
            break;
        }

        // Dessiner le point du rayon sur la minimap
        my_mlx_pixel_put(data->map2d, x / TILE_SIZE, y / TILE_SIZE, 0xffd55c);

        // Avancer le rayon d'un pas
        current_x += data->ray->step_x;
        current_y += data->ray->step_y;
        i++;
    }
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

        // Calcul des coordonnées de fin du rayon (x2, y2)
        data->ray->x2 = data->player->x_pos + cos(angle_rad) * data->ray->ray_length;
        data->ray->y2 = data->player->y_pos + sin(angle_rad) * data->ray->ray_length;

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

// void draw_ray(t_image *map2d, t_image *world, t_map *map, t_ray *ray, t_player *player) 
// {
//     int i;
//     int x, y;
//     float current_x;
//     float current_y;

//     get_steps(ray);
//     if (ray->steps == 0)
//         return;

//     get_step_sizes(ray);

//     // Utiliser les coordonnées du joueur pour initialiser les rayons
//     current_x = player->x_pos / TILE_SIZE;
//     current_y = player->y_pos / TILE_SIZE;

//     i = 0;
//     while (i <= ray->steps) 
//     {
//         x = (int)current_x;
//         y = (int)current_y;

//         // Vérifier si le rayon a touché un mur
//         if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] != '0') 
//         {
//             // Vous pouvez dessiner le mur ou effectuer une autre action ici
//             // draw_wall(data, ray);
//             break;
//         }

//         // Dessiner le point du rayon sur la minimap
//         my_mlx_pixel_put(map2d, x / TILE_SIZE, y / TILE_SIZE, 0xffd55c);

//         // Avancer le rayon d'un pas
//         current_x += ray->step_x;
//         current_y += ray->step_y;
//         i++;
//     }
// }

// // Trace des rayons depuis la position du joueur pour déterminer ce qu'il voit. 
// // Chaque rayon est tracé selon un certain angle, couvrant ainsi la player fov.
// // Le résultat de ce traçage est utilisé pour dessiner la scène 3D.
// void shoot_rays(t_image *map2d, t_image *world, t_player *player, t_map *map, t_ray *ray) 
// {
//     double start_angle;
//     double angle_increment;
//     double angle_rad;
//     int i;

//     start_angle = player->angle - (player->fov / 2.0);
//     angle_increment = player->fov / WINDOW_WIDTH;
//     i = 0;

//     while (i < WINDOW_WIDTH) 
//     {
//         angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

//         // Calcul des coordonnées de fin du rayon (x2, y2)
//         ray->x2 = player->x_pos + cos(angle_rad) * ray->ray_length;
//         ray->y2 = player->y_pos + sin(angle_rad) * ray->ray_length;

//         // Contrainte des coordonnées aux dimensions de la carte
//         if (ray->x2 < 0) 
//             ray->x2 = 0;
//         if (ray->x2 >= (MAP_WIDTH * TILE_SIZE)) 
//             ray->x2 = (MAP_WIDTH * TILE_SIZE) - 1;
//         if (ray->y2 < 0) 
//             ray->y2 = 0;
//         if (ray->y2 >= (MAP_HEIGHT * TILE_SIZE)) 
//             ray->y2 = (MAP_HEIGHT * TILE_SIZE) - 1;

//         // Initialiser les deltas pour le rayon
//         ray->dx = ray->x2 - player->x_pos;
//         ray->dy = ray->y2 - player->y_pos;

//         // Calcul des directions pour le rayon
//         ray->dir_x = cos(angle_rad);
//         ray->dir_y = sin(angle_rad);

//         draw_ray(map2d, world, map, ray, player);
//         i++;
//     }
// }


// int raycasting(t_data *data) {
//     shoot_rays(data->map2d, data->world, data->player, &data->map, data->ray);
//     return 0;
// }
