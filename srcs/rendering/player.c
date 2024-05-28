#include "cub3d-bis.h"

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

// Le but principal de cette fonction est de calculer et 
// de fournir les limites d'un rectangle centré sur le joueur, 
// de manière à pouvoir dessiner ou effectuer des opérations 
// en relation avec la position et la taille du joueur.
// = trouver toutes coordonnées de pixels à l'intérieur du rectangle.
// static void get_player_bounds(t_player *player, t_ray *ray)
// {
//     int half_size;

//     half_size = player->size / 2;
//     ray->x1 = (int)player->x_pos - half_size;
//     ray->y1 = (int)player->y_pos - half_size;
//     ray->x2 = (int)player->x_pos + half_size;
//     ray->y2 = (int)player->y_pos + half_size;
// }

// // Le but principal de cette fonction est de déterminer où se trouve 
// // la position du joueur (player->x_pos et player->y_pos) par rapport 
// // à un point central donné (x_center et y_center). Les coordonnées locales 
// // obtenues (local_x et local_y) représentent la position relative du joueur 
// // par rapport à ce point central.
// static void get_local_coordinates(t_player *player, int *local_x, int *local_y)
// {
//     *local_x = player->x_move - (int)player->x_pos;
//     *local_y = player->y_move - (int)player->y_pos;
// }

// // Le but principal de cette fonction est de prendre les coordonnées locales 
// // d'un point (local_x, local_y) et de les transformer en de nouvelles 
// // coordonnées (rotated_x, rotated_y) après avoir appliqué une rotation 
// // de angle radians autour de l'origine (0, 0).
// static void rotate_coordinates(t_player *player, int local_x, int local_y)
// {
//     player->x_rotated = (int)(local_x * cos(player->angle) - local_y * sin(player->angle));
//     player->y_rotated = (int)(local_x * sin(player->angle) + local_y * cos(player->angle));
// }

// // but de vérifier si les coordonnées d'un joueur se trouvent à l'intérieur 
// // des limites définies par un rectangle représenté par 
// // les coordonnées x1, y1, x2, et y2 d'un rayon (t_ray).
// static int is_within_bounds(int x, int y, t_ray *ray)
// {
//     return (x >= (int)ray->x1 && x < (int)ray->x2 && y >= (int)ray->y1 && y < (int)ray->y2);
// }

// // local_x, local_y: Ces variables vont contenir les coordonnées locales 
// // du pixel du joueur par rapport à son centre.
// // rotated_x, rotated_y: Elles vont stocker les coordonnées locales du pixel après rotation 
// // autour du centre du joueur selon son angle de vision.
// // global_x, global_y: Ces variables vont contenir les coordonnées globales 
// // du pixel du joueur dans le contexte de l'image.
// static void draw_player_pixel(t_image *image, t_player *player, t_ray *ray)
// {
//     int local_x;
// 	int local_y;
//     int global_x;
// 	int global_y;

// 	// get_local_coordinates est utilisée pour obtenir les coordonnées locales du pixel 
// 	// du joueur par rapport à son centre (player->x_pos, player->y_pos). 
// 	// Ces coordonnées locales représentent la position relative du pixel par rapport au centre du joueur.
//     get_local_coordinates(player, &local_x, &local_y);
// 	// rotate_coordinates est utilisée pour appliquer une rotation aux coordonnées locales du pixel 
// 	// en fonction de l'angle de vision du joueur (player->angle). Cela permet de prendre en compte 
// 	// l'orientation du joueur lors du dessin du pixel.
//     rotate_coordinates(player, local_x, local_y);
// 	// coordonnées locales sont ensuite converties en coordonnées globales en ajoutant les coordonnées 
// 	// du centre du joueur (player->x_pos, player->y_pos). Cela permet de positionner le pixel correctement sur l'image.
//     global_x = player->x_rotated + (int)player->x_pos;
//     global_y = player->y_rotated + (int)player->y_pos;
// 	// vérifier si les coordonnées globales du pixel se trouvent à l'intérieur des limites du joueur. 
// 	// Les limites sont définies par un rectangle centré sur le joueur et de taille player->size.
// 	// Si le pixel se trouve à l'intérieur de ces limites, il est dessiné sur l'image
//     if (is_within_bounds(global_x, global_y, ray))
//     {
//         my_mlx_pixel_put(image, global_x, global_y, player->color);
//     }
// }

// int draw_player(t_image *image, t_player *player, t_ray *ray)
// {
//     get_player_bounds(player, ray);
// 	player->y_move = ray->y1;
//     while (player->y_move < ray->y2)
//     {
// 		player->x_move = ray->x1;
//         while (player->x_move < ray->x2)
//         {
//             draw_player_pixel(image, player, ray);
// 			player->x_move++;
//         }
// 		player->y_move++;
//     }
//     return 0;
// }
