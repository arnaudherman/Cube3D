#include "cub3d-bis.h"

// // RESSOURCES : 
// // Raycasting : https://lodev.org/cgtutor/raycasting.html
// // DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// // Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// // https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

// // void draw_line(t_ray *ray, t_image *map2d) 
// // {
// // 	int sx, sy, err;
// // 	int e2;

// //     ray->dx = abs(ray->x2 - ray->x1);
// //     ray->dy = abs(ray->y2 - ray->y1);

// //     if (ray->x1 < ray->x2) 
// // 		sx = 1;
// //     else sx = -1;
    
// //     if (ray->y1 < ray->y2) 
// // 		sy = 1;
// //     else sy = -1;
    
// //     err = ray->dx - ray->dy;

// //     while (1) 
// // 	{
// //         my_mlx_pixel_put(map2d, ray->x1, ray->y1, 0x9A6C7D);
// //         if (ray->x1 == ray->x2 && ray->y1 == ray->y2) 
// // 			break;
// //         e2 = 2 * err;
// //         if (e2 > -ray->dy) { 
// // 			err -= ray->dy; 
// // 			ray->x1 += sx; 
// // 		}
// //         if (e2 < ray->dx) { 
// // 			err += ray->dx; 
// // 			ray->y1 += sy; 
// // 		}
// //     }
// // }


// // void draw_line_to_wall(t_data *data) 
// // {
// //     double x = data->player->x_pos;
// //     double y = data->player->y_pos;
// //     int hit = 0;

// //     while (!hit) {
// //         // Calculate end coordinates of the ray (x2, y2)
// //         double x2 = x + cos(data->ray->angle) * data->ray->ray_length;
// //         double y2 = y + sin(data->ray->angle) * data->ray->ray_length;

// //         // Convert to grid coordinates
// //         int map_x = (int)(x2 / TILE_SIZE);
// //         int map_y = (int)(y2 / TILE_SIZE);

// //         // Check map boundaries
// //         if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
// //             break;

// //         // Check collision with a wall
// //         if (data->map.map2d[map_y][map_x] != '0') {
// //             hit = 1;
// //             break;
// //         }

// //         // Draw a line from the player's current position (x, y) to the next ray position (x2, y2)
// //         draw_line(data->ray, data->map2d);

// //         // Advance along the ray
// //         x = x2;
// //         y = y2;
// //     }
// // }

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
// 			printf("Wall hit at x = %d, y = %d\n", (int)data->ray->map_x, (int)data->ray->map_y);
// 			break;
// 		}
// 	}
// }
// // DDA perform version
// void draw_ray(t_data *data) 
// {
//     int x, y;
//     float distance;
//     int corrected_distance;
//     // int wall_top;
//     // char wall_dir;

//     // Update Deltas
//     data->ray->dx = abs(data->ray->x2 - data->ray->x1);
//     data->ray->dy = abs(data->ray->y2 - data->ray->y1);

//     // Calculate steps and step sizes
//     data->ray->steps = abs(data->ray->dx) > abs(data->ray->dy) ? abs(data->ray->dx) : abs(data->ray->dy);
//     if (data->ray->steps == 0)
//         return;

//     get_step_sizes(data);
	
//     // Initialiser les rayons
//     data->ray->map_x = (int)(data->ray->x1);
//     data->ray->map_y = (int)(data->ray->y1);

//     // Appeler perform_dda pour détecter les collisions
//     perform_dda(data);
//     // Calculer la distance et les propriétés du mur
//     distance = sqrt((data->ray->map_x - data->ray->x1) * (data->ray->map_x - data->ray->x1) + (data->ray->map_y - data->ray->y1) * (data->ray->map_y - data->ray->y1));
//     if (distance == 0) 
//         distance = 1.0;  // Prevent division by zero
//     data->ray->wall_dist = distance;
//     corrected_distance = correct_fisheye(distance, data->ray->angle, data->player->angle);
//     if (corrected_distance == 0) 
//         corrected_distance = 1;  // Prevent division by zero
//     data->ray->wall_height = (int)(WALL_HEIGHT / corrected_distance);

//     // // Determine the direction of the wall
//     // wall_dir = data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE];

//     // // Calculate the top of the wall
//     // wall_top = (WINDOW_HEIGHT / 2) - (data->ray->wall_height / 2);

//     // Draw the wall column
//     // draw_wall_column(data->world, data->ray->map_x * TILE_SIZE, data->ray->wall_height);
//     draw_wall(data);
// }

// // Trace des rayons depuis la position du joueur pour déterminer ce qu'il voit. 
// // Chaque rayon est tracé selon un certain angle, couvrant ainsi la player fov.
// // Le résultat de ce traçage est utilisé pour dessiner la scène 3D.
// void shoot_rays(t_data *data) 
// {
//     double start_angle;
//     double angle_increment;
//     double angle_rad;

//     start_angle = data->player->angle - (data->player->fov / 2.0);
//     angle_increment = data->player->fov / WINDOW_WIDTH;
    
// 	data->ray->ray_index = 0;
//     while (data->ray->ray_index < WINDOW_WIDTH) 
//     {
//         angle_rad = (start_angle + data->ray->ray_index * angle_increment) * (M_PI / 180.0);

// 		// HERE i init my rays through the
//         init_one_ray(data);

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
//         data->ray->ray_index++;
//     }
// }

void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->x_pos - ray->map_x) * ray->dx;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->x_pos) * ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->y_pos - ray->map_y) * ray->dy;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->y_pos) * ray->dy;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square 
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->dx;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->dy;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map.h_map - 0.25
			|| ray->map_x > data->map.w_map - 1.25)
			break ;
		else if (data->map.map2d[(int)ray->map_y][(int)ray->map_x] > '0')
			hit = 1;
	}
}

static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->dx);
	else
		ray->wall_dist = (ray->sidedist_y - ray->dy);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->y_pos + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x_pos + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

// CHECK : data->win_width remplaced by WINDOW_WIDTH
int	raycasting(t_player *player, t_data *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = data->ray;
	// while (x < )
	while (x < WINDOW_WIDTH)
	{
		init_one_ray(x, ray, player);
		set_dda(&ray, player);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, player);
		// update_texture_pixels(data, &data->texinfo, &ray, x);
		x++;
	}
	return 0;
}
