#include "cub3d.h"

// int ray_color(float distance, float ray_length) 
// {
//     int color_start = 0xffd55c; // Jaune
//     int color_end = 0xffff80; // Vert

// 	// color depending on ray length
//     int red = ((color_start >> 16) & 0xFF) * (1 - distance / ray_length) + ((color_end >> 16) & 0xFF) * (distance / ray_length);
//     int green = ((color_start >> 8) & 0xFF) * (1 - distance / ray_length) + ((color_end >> 8) & 0xFF) * (distance / ray_length);
//     int blue = (color_start & 0xFF) * (1 - distance / ray_length) + (color_end & 0xFF) * (distance / ray_length);
//     int color = (red << 16) | (green << 8) | blue;

//     return color;
// }


// Draw ray with colors 
// void draw_ray(t_image *image, int x1, int y1, int x2, int y2, t_map *map, t_ray *ray)
// {
// 	int i;
//     int x, y;
//     int dx = x2 - x1;
//     int dy = y2 - y1;

//     // Determine the sign of the step (i.e., +1 or -1) for each dimension
//     int sign_x = (dx > 0) ? 1 : -1;
//     int sign_y = (dy > 0) ? 1 : -1;

//     // Determine the number of steps required along each dimension
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     // Calculate the increment for each dimension per step
//     float step_x = (float)dx / steps;
//     float step_y = (float)dy / steps;

//     // Initialize the starting position
//     float current_x = x1;
//     float current_y = y1;

// 	// TO DO : x2 and y2 already passed in paramater
//     // int x2 = x1 + (int)data->ray->dx;
//     // int y2 = y1 + (int)data->ray->dy;

//     // Couleur de départ et de fin pour le dégradé
//     int color_start = 0xffd55c; // Jaune
//     int color_end = 0xffff80; // Vert

//     // Draw the ray by iterating through each step
// 	i = 0;
//     while (i <= steps)
//     {
//         x = (int)current_x;
//         y = (int)current_y;
		
// 		// Yooooo, here x = 240 and y = 240, divide by 64 to get the right position
//         if (map->map2d[y / 64][x / 64] != '0')
//         {
//             printf("Wall found at (%d, %d)\n", x, y);
//             break;
//         }

//         // Calculer la distance entre le point actuel du rayon et le joueur
//         float distance = sqrt((current_x - x1) * (current_x - x1) + (current_y - y1) * (current_y - y1));

// 		// TO DO : failed to extract color code part to ray_color function
// 		// int color = ray_color(distance, ray->ray_length);
//         // // Calculer le dégradé de couleur en fonction de la distance
//         int red = ((color_start >> 16) & 0xFF) * (1 - distance / ray->ray_length) + ((color_end >> 16) & 0xFF) * (distance / ray->ray_length);
//         int green = ((color_start >> 8) & 0xFF) * (1 - distance / ray->ray_length) + ((color_end >> 8) & 0xFF) * (distance / ray->ray_length);
//         int blue = (color_start & 0xFF) * (1 - distance / ray->ray_length) + (color_end & 0xFF) * (distance / ray->ray_length);
//         int color = (red << 16) | (green << 8) | blue;


//         // Dessiner le pixel avec la couleur calculée
//         my_mlx_pixel_put(image, x, y, color);

//         // Move to the next position along each dimension
//         current_x += step_x;
//         current_y += step_y;
// 		i++;
//     }
// }