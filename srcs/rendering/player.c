#include "cub3d-bis.h"

// int draw_player(t_player *player, t_mlx *mlx) {
//     int x, y;
//     int x_start, x_end;
//     int y_start, y_end;
	
//     // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
//     x_start = (int)(player->x_pos) - (player->size / 2);
//     y_start = (int)(player->y_pos) - (player->size / 2);
//     x_end = x_start + player->size;
//     y_end = y_start + player->size;
// 	printf("in render after draw : x_pos : %d\n", x_start);
// 	printf("in render after draw : y_pos : %d\n", y_start);

//     // Vérification des limites de la fenêtre
//     if (x_start < 0) x_start = 0;
//     if (y_start < 0) y_start = 0;
//     if (x_end > mlx->win_width) x_end = mlx->win_width;
//     if (y_end > mlx->win_height) y_end = mlx->win_height;

//     // Dessiner le joueur en parcourant les pixels du rectangle
//     for (y = y_start; y < y_end; y++) {
//         for (x = x_start; x < x_end; x++) {
//             my_mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win_ptr, x, y, player->color);
//         }
//     }
    
//     return 0;
// }

int draw_player(t_image *image, t_player *player) {
    int x, y;
    int x_start, x_end;
    int y_start, y_end;

	// printf("player x_pos : %f\n", player->x_pos);
	// printf("player y_pos : %f\n", player->y_pos);

    // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
    x_start = (int)(player->x_pos) - (player->size / 2);
    y_start = (int)(player->y_pos) - (player->size / 2);
    x_end = x_start + player->size;
    y_end = y_start + player->size;

    // // Vérification des limites de l'image
    // if (x_start < 0) x_start = 0;
    // if (y_start < 0) y_start = 0;
    // if (x_end > 640) x_end = 640;
    // if (y_end > 640) y_end = 640;

    // Dessiner le joueur en parcourant les pixels du rectangle
    for (y = y_start; y < y_end; y++) {
        for (x = x_start; x < x_end; x++) {
            my_mlx_pixel_put(image, x, y, 0x7FFF00);
        }
    }
    
    return 0;
}


// POURQUOI ICI x_pos est 0 et y_pos est 0

// int draw_player(t_image *image, t_player *player) 
// {
//     int x, y;
//     int x_start, x_end;
//     int y_start, y_end;

// 	printf("ain render after draw : x_pos : %d\n", x_start);
// 	printf("ain render after draw : y_pos : %d\n", y_start);
	
//     // Calcul des coordonnées de début et de fin du rectangle représentant le joueur
//     x_start = (int)(player->x_pos) - (player->size / 2);
//     y_start = (int)(player->y_pos) - (player->size / 2);
//     x_end = x_start + player->size;
//     y_end = y_start + player->size;
// 	printf("in render after draw : x_pos : %d\n", x_start);
// 	printf("in render after draw : y_pos : %d\n", y_start);

//     // TO DO : faire les vérification des limites de la fenêtre

//     // Dessiner le joueur en parcourant les pixels du rectangle
//     for (y = y_start; y < y_end; y++) {
//         for (x = x_start; x < x_end; x++) {
//             my_mlx_pixel_put(image, x, y, player->color);
//         }
//     }
    
//     return 0;
// }