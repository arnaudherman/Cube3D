// #include "cub3d-bis.h"

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
