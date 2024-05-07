#include "../include/cub3d-bis.h"

// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// GO learn vectors

// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari
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

// // Fonction pour exécuter l'algorithme DDA
// static void perform_dda(t_data *data) {
// 	int hit = 0;
// 	while (hit == 0) {
// 		if (data->ray.sidedist_x < data->ray.sidedist_y) {
// 			data->ray.sidedist_x += data->ray.deltadist_x;
// 			data->ray.map_x += data->ray.step_x;
// 			data->ray.side = 0;
// 		} else {
// 			data->ray.sidedist_y += data->ray.deltadist_y;
// 			data->ray.map_y += data->ray.step_y;
// 			data->ray.side = 1;
// 		}
// 		if (data->ray.map_y < 0.25 || data->ray.map_x < 0.25 ||
// 		    data->ray.map_y > data->map.h_map - 0.25 ||
// 		    data->ray.map_x > data->map.w_map - 1.25)
// 			break;
// 		else if (data->map.map2d[(int)data->ray.map_y][(int)data->ray.map_x] != '0')
// 			hit = 1;
// 	}
// }

// // Fonction pour calculer les hauteurs des lignes à dessiner
// static void calculate_line_height(t_data *data) 
// {
// 	if (data->ray.side == 0)
// 		data->ray.wall_dist = fabs((data->ray.map_x - data->player.x_pos + (1 - data->ray.step_x) / 2) / data->ray.dir_x);
// 	else
// 		data->ray.wall_dist = fabs((data->ray.map_y - data->player.y_pos + (1 - data->ray.step_y) / 2) / data->ray.dir_y);
// 	data->ray.line_height = (int)(data->win_height / data->ray.wall_dist);
// 	data->ray.draw_start = -data->ray.line_height / 2 + data->win_height / 2;
// 	if (data->ray.draw_start < 0)
// 		data->ray.draw_start = 0;
// 	data->ray.draw_end = data->ray.line_height / 2 + data->win_height / 2;
// 	if (data->ray.draw_end >= data->win_height)
// 		data->ray.draw_end = data->win_height - 1;
// 	if (data->ray.side == 0)
// 		data->ray.wall_x = data->player.y_pos + data->ray.wall_dist * data->ray.dir_y;
// 	else
// 		data->ray.wall_x = data->player.x_pos + data->ray.wall_dist * data->ray.dir_x;
// 	data->ray.wall_x -= floor(data->ray.wall_x);
// }

// int launch_raycasting(t_data *data) {
    
// 	while (data->ray.step_x < data->win_width)
// 	{
// 		perform_dda(&data);
//     	// Calcul des intersections avec les murs
//     	// calculate_wall_intersection(&data);
    
//     	// Calcul des hauteurs des lignes à dessiner
//     	calculate_line_height(&data);
// 		// Edit textures
// 		// update_texture_pixels(&data);
// 		data->ray.step_x++;	
// 	}
//     return 0;
// }

int raycasting(t_data *data)
{
	cast_ray(data->image, data->player);	
	return 0;
}