#include "cub3d-bis.h"

// Fonction pour initialiser les rayons de projection
// static void	init_ray(t_data *data) {
// 	data->ray.step_x = ;
// 	data->ray.step_y = ;
// 	data->ray.line_height = ;
// 	data->ray.draw_start = ;
// 	data->ray.draw_end = ;
// 	data->ray.wall_dist = ;
// 	data->ray.wall_x = ;
// Déterminer la direction du rayon en fonction de l'angle de vue du joueur
// 	data->ray.pov_x = data->player.angle - (data->player.fov / 2);
// 	data->ray.dir_x = cos(data->ray.pov_x);
// 	data->ray.dir_y = sin( data->ray.pov_x);
// Initialiser les autres paramètres des rayons de projection
// 	data->ray.map_x = (int)data->player.x_pos;
// 	data->ray.map_y = (int)data->player.y_pos;
// 	data->ray.deltadist_x = fabs(1 / data->ray.dir_x);
// 	data->ray.deltadist_y = (int)data->player.y_pos;
// 	data->ray.side = ;
// 	data->ray.sidedist_x = fabs(1 / data->ray.dir_x);
// 	data->ray.sidedist_y = fabs(1 / data->ray.dir_y);
// }