#include "cub3d-bis.h"

// DO NOT DELETE THIS FUNCTION
int draw_player(t_image *image, t_player *player) {
    int x, y;
    int x_start, x_end;
    int y_start, y_end;

    // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
    x_start = (int)(player->x_pos) - (player->size / 2);
    y_start = (int)(player->y_pos) - (player->size / 2);
    x_end = x_start + player->size;
    y_end = y_start + player->size;

    // Dessiner le joueur en parcourant les pixels du rectangle
    for (y = y_start; y < y_end; y++) {
        for (x = x_start; x < x_end; x++) {
            my_mlx_pixel_put(image, x, y, player->color);
        }
    }
    
    return 0;
}


    // x_start = (int)(player->x_pos - (player->size / 2) * cos_angle - (player->size / 2) * sin_angle);
    // y_start = (int)(player->y_pos - (player->size / 2) * cos_angle + (player->size / 2) * sin_angle);
    // x_end = x_start + player->size * cos_angle;
    // y_end = y_start + player->size * sin_angle;


// TEST FUNCTION FOR PLAYER ROTATION
// int draw_player(t_image *image, t_player *player) {
//     int x, y;
//     int x_start, x_end;
//     int y_start, y_end;
//     int border_width = 20; // Largeur de la bordure en pixels
//     unsigned int border_color = 0x601aa9; // Couleur de la bordure (blanc)

//     // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
//     x_start = (int)(player->x_pos) - (player->size / 2);
//     y_start = (int)(player->y_pos) - (player->size / 2);
//     x_end = x_start + player->size;
//     y_end = y_start + player->size;

//     // Dessiner le carré représentant le joueur
//     for (y = y_start; y < y_end; y++) {
//         for (x = x_start; x < x_end; x++) {
//             // Dessiner le carré du joueur
//             my_mlx_pixel_put(image, x, y, player->color);

//             // Dessiner une ligne sur le côté droit du carré pour mieux visualiser la rotation
//             if (x == x_end - 1 || x == x_end - border_width) {
//                 my_mlx_pixel_put(image, x + 1, y, border_color);
//             }
//         }
//     }
    
//     return 0;
// }

