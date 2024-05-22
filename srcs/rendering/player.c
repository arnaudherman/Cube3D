#include "cub3d-bis.h"

float correct_fisheye(float distance, float ray_angle, float player_angle) 
{
    float angle_difference;
	float corrected_distance;
	
	angle_difference = ray_angle - player_angle;
    corrected_distance = distance * cos(angle_difference);
    return corrected_distance;
}

int draw_player(t_image *image, t_player *player) 
{
    int x, y;
    int x_center = (int)player->x_pos;
    int y_center = (int)player->y_pos;
    int half_size = player->size / 2;

    int x_start = x_center - half_size;
    int y_start = y_center - half_size;
    int x_end = x_center + half_size;
    int y_end = y_center + half_size;

    // Dessiner le joueur en parcourant les pixels du rectangle
    for (y = y_start; y < y_end; y++) {
        for (x = x_start; x < x_end; x++) {
            // Calcul des coordonnées du pixel dans le repère local du joueur
            // en soustrayant les coordonnées du centre du joueur
            int local_x = x - x_center;
            int local_y = y - y_center;

            // Rotation des coordonnées locales en fonction de l'angle du joueur
            int rotated_x = (int)(local_x * cos(player->angle) - local_y * sin(player->angle));
            int rotated_y = (int)(local_x * sin(player->angle) + local_y * cos(player->angle));

            // Ajout des coordonnées du centre du joueur pour obtenir les coordonnées globales
            int global_x = rotated_x + x_center;
            int global_y = rotated_y + y_center;

            // Dessiner le pixel seulement s'il est à l'intérieur du rectangle représentant le joueur
            if (global_x >= x_start && global_x < x_end && global_y >= y_start && global_y < y_end) {
                my_mlx_pixel_put(image, global_x, global_y, player->color);
            }
        }
    }
    return 0;
}
