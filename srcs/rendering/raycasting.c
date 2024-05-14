#include "../include/cub3d-bis.h"

float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

// void draw_world(t_image *image, t_map *map, t_player *player, t_ray *ray)
// {

// }

// RESSOURCES : 
// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

// **********************************************************
// Try to decompose the raycasting algorithm into smaller functions
// From player to wall hit
// float calculate_distance(t_player *player, t_ray *ray)
// {
//     float dx = ray->x_end - player->x_pos;
//     float dy = ray->y_end - player->y_pos;
//     float distance = sqrt(dx * dx + dy * dy);
//     return distance;
// }

// // Increment each step
// static void calculate_step_increment(t_ray *ray)
// {
//     if (fabs(ray->dx) > fabs(ray->dy))
//         ray->step = fabs(ray->dx);
//     else 
//         ray->step = fabs(ray->dy);

//     ray->xinc = ray->dx / ray->step;
//     ray->yinc = ray->dy / ray->step;
// }

// static void dda_algorithm(t_data *data)
// {
//     int i;
// 	i = 0;
//     data->ray->x = (float)data->player->x_pos;
//     data->ray->y = (float)data->player->y_pos;

//     calculate_step_increment(data->ray);

//     while (i < data->ray->step)
//     {
//         if (data->map.map2d[data->ray->y / 64][data->ray->x / 64] != '0')
//         {
//             printf("Wall found at (%d, %d)\n", data->ray->x, data->ray->y);
//             break;
//         }
		
//         float distance = calculate_distance(data->player, data->ray);

//         my_mlx_pixel_put(&data->image, data->ray->x, data->ray->y, ray_color(distance));

//         data->ray->x += data->ray->xinc;
//         data->ray->y += data->ray->yinc;
//         i++;
//     }

//     if (data->map.map2d[data->ray->y][data->ray->x] != '0')
//         my_mlx_pixel_put(&data->image, data->ray->x, data->ray->y, 0xBDEDDF);
// }
// **********************************************************

// **********************************************************
// THIRD VERSION 
// TO DO : USE INTS INSTEAD OF FLOATS for map coordinates x1, y1, x2, y2
// static void dda_algo(t_data *data)
// {
//     float xinc;
//     float yinc;
//     float step;
//	   float distance;
//     int i;

//     float x1 = (float)data->player->x_pos;
//     float y1 = (float)data->player->y_pos;

//     data->ray->dx = cos(data->player->angle);
//     data->ray->dy = sin(data->player->angle);

// 	float x2 = x1 + data->ray->dx;
// 	float y2 = y1 + data->ray->dy;

//     if(abs(data->ray->dx) > abs(data->ray->dy))
//         step = abs(data->ray->dx);
//     else 
//         step = abs(data->ray->dy);

// 	// TO DO : passer de double a float check
// 	// conversion peut entraîner une perte de précision
//     xinc = (float)data->ray->dx / step;
//     yinc = (float)data->ray->dy / step;

//     i = 0;
//     while (i < step)
//     {
//         if (data->map.map2d[(int)y1][(int)x1] != '0')
//         {
//             printf("Wall found at (%d, %d)\n", (int)x1, (int)y1);
//             break;
//         }

// 		// Calculer la distance entre le point actuel du rayon et le joueur
//         distance = delta_player_hits(data->player, data->ray);

//         // En fonction de la couleur calculee par ma fonct ray_color();
//         my_mlx_pixel_put(&data->image, x1, y1, ray_color(distance));
//         x1 += xinc;
//         y1 += yinc;
//         i++;
//     }
// 	// Draw hits here if wall found
//     my_mlx_pixel_put(&data->image, (int)x1, (int)y1, 0xBDEDDF);
// }
// **********************************************************


// **********************************************************
// SECOND VERSION
// (x1, y1) is player position, (x2, y2) is the intersection point
// static void dda_algo(t_data *data, float x2, float y2)
// {
//     float dx;
//     float dy;
//     float xinc;
//     float yinc;
//     float step;
//     int i;

// 	// Temporary coordinates
// 	float x = (float)data->player->x_pos;
//     float y = (float)data->player->y_pos;

// 	// Get the Deltas
//     dx = x2 - (float)data->player->x_pos;
//     dy = y2 - (float)data->player->y_pos;

// 	// Get the number of steps
//     if(abs(dx) > abs(dy))
//         step = abs(dx);
//     else 
//         step = abs(dy);

//     // Get the incrementations
//     xinc = dx / step;
//     yinc = dy / step;

//     i = 0;
//     // Draw pixel
//     while (i < step)
//     {
//         my_mlx_pixel_put(&data->image, (int)x, (int)y, 0xBDEDDF);
//         x += xinc;
//     	y += yinc;
//         i++;
//     }
// }
// **********************************************************


// **********************************************************
// FIRST VERSION
// static void dda_algo(float x1, float y1, float x2, float y2)
// {
//     // Get the Deltas
//     float dx;
//     float dy;
//     float xinc;
//     float yinc;
//     float step;
//     int i;

//     dx = x2 - x1;
//     dy = y2 - y1;
//     if(abs(dx) > abs(dy))
//         step = abs(dx);
//     else 
//         step = abs(dy);
//     // Get the incrementations
//     xinc = dx / step;
//     yinc = dy / step;
//     i = 1;
//     // Draw pixel
//     while (i <= step)
//     {
//         putpixel(x1, y1);
//         x1 = x1 + xinc;
//         y1 = y1 + yinc;
//         i++;
//     }
// }

// Fonction pour exécuter l'algorithme DDA
// static void perform_dda(t_data *data) 
// {
// 	int hit;
	
// 	hit = 0;
// 	while (hit == 0) {
// 		if (data->ray->sidedist_x < data->ray->sidedist_y) {
// 			data->ray->sidedist_x += data->ray->dx;
// 			data->ray->map_x += data->ray->step_x;
// 			data->ray->side = 0;
// 		} else {
// 			data->ray->sidedist_y += data->ray->dy;
// 			data->ray->map_y += data->ray->step_y;
// 			data->ray->side = 1;
// 		}
// 		if (data->ray->map_y < 0.25 || data->ray->map_x < 0.25 ||
// 		    data->ray->map_y > data->map.h_map - 0.25 ||
// 		    data->ray->map_x > data->map.w_map - 1.25)
// 			break;
// 		else if (data->map.map2d[(int)data->ray->map_y][(int)data->ray->map_x] != '0')
// 			hit = 1;
// 	}
// }
// **********************************************************

// Fonction pour calculer les hauteurs des lignes à dessiner
// static void calculate_line_height(t_data *data) 
// {
// 	if (data->ray->side == 0)
// 		data->ray->wall_dist = fabs((data->ray->map_x - data->player->x_pos + (1 - data->ray->step_x) / 2) / data->ray->dir_x);
// 	else
// 		data->ray->wall_dist = fabs((data->ray->map_y - data->player->y_pos + (1 - data->ray->step_y) / 2) / data->ray->dir_y);
// 	data->ray->line_height = (int)(data->mlx.win_height / data->ray->wall_dist);
// 	data->ray->draw_start = -data->ray->line_height / 2 + data->mlx.win_height / 2;
// 	if (data->ray->draw_start < 0)
// 		data->ray->draw_start = 0;
// 	data->ray->draw_end = data->ray->line_height / 2 + data->mlx.win_height / 2;
// 	if (data->ray->draw_end >= data->mlx.win_height)
// 		data->ray->draw_end = data->mlx.win_height - 1;
// 	if (data->ray->side == 0)
// 		data->ray->wall_x = data->player->y_pos + data->ray->wall_dist * data->ray->dir_y;
// 	else
// 		data->ray->wall_x = data->player->x_pos + data->ray->wall_dist * data->ray->dir_x;
// 	data->ray->wall_x -= floor(data->ray->wall_x);
// }
