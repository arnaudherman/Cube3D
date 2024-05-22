#include "cub3d-bis.h"

// From player to wall hit
// void	get_wall_dist(t_player *player, t_ray *ray)
// {
//     float dx;
// 	float dy;

// 	dx = ray->x_end - player->x_pos;
//     dy = ray->y_end - player->y_pos;
//     ray->wall_dist = sqrt(dx * dx + dy * dy);
// }
void calculate_delta_dist(t_ray *ray) {
    ray->dx = (ray->dir_x == 0) ? 0 : fabs(1 / ray->dir_x);
    ray->dy = (ray->dir_y == 0) ? 0 : fabs(1 / ray->dir_y);
}

void calculate_side_dist(t_ray *ray, t_player *player) {
    if (ray->dir_x < 0) {
        ray->x = -1;
        ray->sidedist_x = (player->x_pos - ray->map_x) * ray->dx;
    } else {
        ray->x = 1;
        ray->sidedist_x = (ray->map_x - player->x_pos + 1.0) * ray->dx;
    }
    if (ray->dir_y < 0) {
        ray->y = -1;
        ray->sidedist_y = (player->y_pos - ray->map_y) * ray->dy;
    } else {
        ray->y = 1;
        ray->sidedist_y = (ray->map_y - player->y_pos + 1.0) * ray->dy;
    }
}

void perform_dda(t_ray *ray, t_map *map) {
    int hit = 0;
    while (hit == 0) {
        if (ray->sidedist_x < ray->sidedist_y) {
            ray->sidedist_x += ray->dx;
            ray->map_x += ray->x;
            ray->side = (ray->x == -1) ? 0 : 1;
        } else {
            ray->sidedist_y += ray->dy;
            ray->map_y += ray->y;
            ray->side = (ray->y == -1) ? 2 : 3;
        }
		// TO DO use : map->map2d[y / TILE_SIZE][x / TILE_SIZE]
        if (map->map2d[ray->y][ray->x] > '0') 
			hit = 1;
    }
}


void get_wall_dist(t_player *player, t_ray *ray) {
    if (ray->side == 0 || ray->side == 1)
        ray->wall_dist = (ray->map_x - player->x_pos + (1 - ray->x) / 2) / ray->dir_x;
    else
        ray->wall_dist = (ray->map_y - player->y_pos + (1 - ray->y) / 2) / ray->dir_y;
}


void	get_wall_height(t_ray *ray)
{
	if (ray->wall_dist == 0)
		ray->wall_dist = 1;
	ray->wall_height = (int)(WALL_HEIGHT / ray->wall_dist);
}


void draw_wall_column(t_image *world, int column, int wall_height)
{
	int top;
	int bottom;
	int y;

    top = (WINDOW_HEIGHT - wall_height) / 2;
    bottom = top + wall_height;

    if (top < 0)
		top = 0;
    if (bottom >= WINDOW_HEIGHT)
		bottom = WINDOW_HEIGHT - 1;

	y = top;
    while (y <= bottom)
    {
        my_mlx_pixel_put(world, column, y, 0xBBA498);
		y++;
    }
}

void draw_wall(t_data *data, t_ray *ray) 
{
	int column;

	column = 0;
    while (column < WINDOW_WIDTH) {
        ray->dir_x = data->player->x_dir + data->player->x_plane * ray->camera_x;
        ray->dir_y = data->player->y_dir + data->player->y_plane * ray->camera_x;

        ray->map_x = (int)data->player->x_pos;
        ray->map_y = (int)data->player->y_pos;

        calculate_delta_dist(ray);
        calculate_side_dist(ray, data->player);

        perform_dda(ray, &data->map);
        get_wall_dist(data->player, ray);
        get_wall_height(ray);

        draw_wall_column(data->world, column, ray->wall_height);
		column++;
    }
}

// Fresh
// void draw_wall(t_data *data, t_ray *ray)
// {
//     for (int column = 0; column < WINDOW_WIDTH; column++)
//     {
//         // Calcul de l'angle du rayon pour chaque colonne
//         float ray_angle = data->player->angle - (FOV / 2.0) + ((float)column / (float)WINDOW_WIDTH) * FOV;
        
//         // Initialiser les coordonnées du rayon
//         ray->x_start = data->player->x_pos;
//         ray->y_start = data->player->y_pos;
//         ray->angle = ray_angle;

//         // Calculer la distance au mur
//         get_wall_dist(data->player, ray);
        
//         // Calculer la hauteur du mur en fonction de la distance
//         get_wall_height(ray);
        
//         // Dessiner la colonne du mur
//         draw_wall_column(data->world, column, ray->wall_height);
//     }
// }

// OG
// void draw_wall(t_data *data, int x, int y, int wall_height) 
// {
//     float ray_angle;
//     t_ray ray;
//     int column;

// 	// column = 0;
// 	// while (column < WINDOW_WIDTH) // Parcourir chaque colonne de l'écran
	
// 	column = x * TILE_SIZE; // Convertir la position x en pixels de l'image
//     while (column < (x + 1) * TILE_SIZE) // Parcourir chaque colonne du mur
// 	{
//         ray_angle = data->player->angle - FOV / 2.0 + ((float)column / (float)WINDOW_WIDTH) * FOV;
        
//         // Initialize ray starting position
//         ray.x_start = data->player->x_pos;
//         ray.y_start = data->player->y_pos;
//         ray.angle = ray_angle;

//         get_wall_dist(data->player, &ray);
        
//         get_wall_height(&ray);
        
//         draw_wall_column(data->world, column, wall_height);
// 		// draw_wall(data, ray);
// 		// set_color_on_image(game, ray);
        
//         column++;
//     }
// }

// void draw_wall(t_data *data, int x, int y, int wall_height) 
// {
//     float ray_angle;
//     t_ray ray;
//     int column;

//     column = x * TILE_SIZE; // Convertir la position x en pixels de l'image
//     while (column < (x + 1) * TILE_SIZE) // Parcourir chaque colonne du mur
//     {
//         ray_angle = data->player->angle - FOV / 2.0 + ((float)column / (float)WINDOW_WIDTH) * FOV;
        
//         // Initialize ray starting position
//         ray.x_start = data->player->x_pos;
//         ray.y_start = data->player->y_pos;
//         ray.angle = ray_angle;

//         get_wall_dist(data->player, &ray);
        
//         get_wall_height(&ray);
        
//         draw_wall_column(data->world, column, wall_height);
        
//         column++; // Incrémenter la valeur de column pour passer à la colonne suivante
//     }
// }

