#include "cub3d-bis.h"

// DO NOT DELETE THIS FUNCTION
// int draw_player(t_image *image, t_player *player) 
// {
//     int x, y;
//     int x_start, x_end;
//     int y_start, y_end;

//     x_start = (int)(player->x_pos) - (player->size / 2);
//     y_start = (int)(player->y_pos) - (player->size / 2);
//     x_end = x_start + player->size;
//     y_end = y_start + player->size;

//     for (y = y_start; y < y_end; y++) {
//         for (x = x_start; x < x_end; x++) {
//             my_mlx_pixel_put(image, x, y, player->color);
//         }
//     }
//     return 0;
// }

// TEST
int draw_player(t_image *image, t_player *player) 
{
    int x, y;
    int x_center = (int)player->x_pos; // Coordonnée x du centre du joueur
    int y_center = (int)player->y_pos; // Coordonnée y du centre du joueur
    int half_size = player->size / 2; // Moitié de la taille du joueur

    // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
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
