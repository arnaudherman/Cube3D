#include "../include/cub3d.h"

// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// GO learn vectors

// // https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari
// static void dda_algo(float x1, float y1, float x2, float y2)
// {
//     // Get the Deltas
//     float dx;
//     float dy;
//     float xinc;
//     float xinc;
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

// Fonction pour initialiser les rayons de projection
static void init_raycasting(t_data *data) {
    // Déterminer la direction du rayon en fonction de l'angle de vue du joueur
    data->ray.pov_x = data->player.player_angle - (data->player.fov / 2);
    data->ray.dir_x = cos(data->ray.pov_x);
    data->ray.dir_y = sin( data->ray.pov_x);
    // Initialiser les autres paramètres des rayons de projection
    data->ray.map_x = (int)data->player.x_pos_px;
    data->ray.map_y = (int)data->player.y_pos_px;
    data->ray.deltadist_x = fabs(1 / data->ray.dir_x);
    data->ray.deltadist_y = fabs(1 / data->ray.dir_y);
}

// Fonction pour exécuter l'algorithme DDA
static void perform_dda(t_data *data, t_ray *ray) {
	int hit = 0;
	while (hit == 0) {
		if (ray->sidedist_x < ray->sidedist_y) {
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		} else {
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 ||
		    ray->map_y > data->map.h_map - 0.25 ||
		    ray->map_x > data->map.w_map - 1.25)
			break;
		else if (data->map.map2d[(int)ray->map_y][(int)ray->map_x] != '0')
			hit = 1;
	}
}

// Fonction pour calculer les hauteurs des lignes à dessiner
static void calculate_line_height(t_ray *ray, t_data *data, t_player *player) {
	if (ray->side == 0)
		ray->wall_dist = fabs((ray->map_x - player->x_pos_px + (1 - ray->step_x) / 2) / ray->dir_x);
	else
		ray->wall_dist = fabs((ray->map_y - player->y_pos_px + (1 - ray->step_y) / 2) / ray->dir_y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->y_pos_px + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x_pos_px + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

// Fonction principale du raycasting
int raycasting(t_player *player, t_data *data) {
	t_ray ray;
	int x;
    
    x = 0;
	while (x < data->win_width) {
		init_raycasting(data);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, player);
		//update_texture_pixels(data, &data->texinfo, &ray, x);
		x++;
	}
	return (0);
}

// int main() {
//     // Initialisation des données du jeu
//     t_data game_data;
//     // (à compléter avec l'initialisation des données du jeu)
    
//     // Initialisation des rayons de projection
//     init_raycasting(&game_data);
    
//     // Calcul des intersections avec les murs
//     calculate_wall_intersections(&game_data);
    
//     // Calcul des hauteurs des lignes à dessiner
//     calculate_line_heights(&game_data);
    
//     // Dessin des murs sur l'écran
//     // (à compléter avec la fonction de dessin)
    
//     return 0;
// }
