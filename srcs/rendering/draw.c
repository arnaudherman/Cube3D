// #include "../include/cub3d-bis.h"

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


// void	draw_vertical_lign(t_data *data)
// {
//     while (data->map.x_map <= MAP_WIDTH * TILE_SIZE) {
//         my_mlx_pixel_put(data, data->map.x_map, 0, 0xFFFFFF); // Ligne en haut
//         my_mlx_pixel_put(data, data->map.x_map, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Ligne en bas
//         data->map.x_map += TILE_SIZE;
//     }
// }

// void	draw_horizontal_lign(t_data *data)
// {
//     while (data->map.y_map <= MAP_HEIGHT * TILE_SIZE) {
//         my_mlx_pixel_put(data, 0, data->map.y_map, 0xFFFFFF); // Ligne à gauche
//         my_mlx_pixel_put(data, MAP_WIDTH * TILE_SIZE, data->map.y_map, 0xFFFFFF); // Ligne à droite
//         data->map.y_map += TILE_SIZE;
//     }
// }