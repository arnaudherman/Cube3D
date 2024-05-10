#include "cub3d-bis.h"

// Fonction pour dessiner un mur
void draw_wall(t_image *image, t_ray *ray, int x2, int y2, t_map *map)
{
    // Calculer la distance entre le joueur et le mur
    float distance = sqrt((ray->wall_x - ray->x) * (ray->wall_x - ray->x) + (ray->wall_y - ray->y) * (ray->wall_y - ray->y));

    // Calculer la hauteur du mur en fonction de la distance
    int wall_height = (int)(WALL_HEIGHT / distance);

    // Dessiner le mur
    // (Utilise une fonction de dessin de mur appropriée selon ta méthode de rendu)
    // draw_wall_texture(image, wall_x, wall_y, wall_height, map);
}

// void draw_walls(t_data *data) {
//     int column = 0;
//     float angle = data->player.angle - (FOV / 2); // Angle de vision du joueur
    
//     while (column < WINDOW_WIDTH) {
//         // Calculez la distance au mur dans la direction actuelle
//         float distance_to_wall = calculate_distance_to_wall(data, angle);

//         // Calculez la hauteur du mur sur l'écran en fonction de la distance
//         int wall_height = calculate_wall_height(data, distance_to_wall);

//         // Dessinez la colonne de mur sur l'écran
//         int top = (WINDOW_HEIGHT - wall_height) / 2; // Début vertical du mur
//         int bottom = top + wall_height; // Fin vertical du mur
//         int y = top;
//         while (y < bottom) {
//             my_mlx_pixel_put(data, column, y, 0x808080); // Dessiner le mur
//             y++;
//         }

//         // Passez à la colonne de pixel suivante et ajustez l'angle pour correspondre à la colonne suivante
//         column++;
//         angle += (F_GETPROTECTIONLEVEL / WINDOW_WIDTH);
//     }
// }

// void draw_ceiling(t_data *data) {
//     int x = 0;
//     while (x < WINDOW_WIDTH) {
//         int y = 0;
//         while (y < WINDOW_HEIGHT / 2) {
//             my_mlx_pixel_put(data, x, y, CEILING); // Remplacez CEILING_COLOR par la couleur choisie pour le plafond
//             y++;
//         }
//         x++;
//     }
// }

// void draw_floor(t_data *data) {
//     int x = 0;
//     while (x < WINDOW_WIDTH) {
//         int y = WINDOW_HEIGHT / 2;
//         while (y < WINDOW_HEIGHT) {
//             my_mlx_pixel_put(data, x, y, FLOOR); // Remplacez FLOOR_COLOR par la couleur choisie pour le sol
//             y++;
//         }
//         x++;
//     }
// }