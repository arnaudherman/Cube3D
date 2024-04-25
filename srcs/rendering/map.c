// #include "cub3d-bis.h"

// // L'offset mémoire pour un pixel à une certaine position (x, y) dans l'image
// // y * line_length : cela détermine la position verticale dans l'image en prenant en compte la longueur de la ligne.
// // x * (bits_per_pixel / 8) : cela détermine la position horizontale en prenant en compte le nombre de bits par pixel et le divisant par 8 pour obtenir le nombre d'octets.
// // int offset = (y * line_length + x * (bits_per_pixel / 8));
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
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
//   while (data->map.y_map <= MAP_HEIGHT * TILE_SIZE) {
//         my_mlx_pixel_put(data, 0, data->map.y_map, 0xFFFFFF); // Ligne à gauche
//         my_mlx_pixel_put(data, MAP_WIDTH * TILE_SIZE, data->map.y_map, 0xFFFFFF); // Ligne à droite
//         data->map.y_map += TILE_SIZE;
//     }
// }

// // draw_square(data, x * TILE_SIZE, y * TILE_SIZE)
// void draw_square(t_data *data)
// {
//     int i;
//     int j;

// 	// init_map_bis(data);

//     i = 0;
//     while (i < MAP_WIDTH)
//     {
//         j = 0;
//         while (j < MAP_HEIGHT)
//         {
//             my_mlx_pixel_put(data, data->map.x_map + i, data->map.y_map + j, data->map.color);
//             j++;
//         }
//         i++;
//     }
// }

// void draw_map(t_data *data) {
//     // Draw ligns
// 	draw_vertical_lign(data);
// 	draw_horizontal_lign(data);

//     // Draw tiles
//     int y = 0;
//     while (y < MAP_HEIGHT) {
//         int x = 0;
//         while (x < MAP_WIDTH) {
//             if (data->map.map2d[y][x] == '1') {
//                 // Dessiner une tile de mur (si map2d[y][x] est '1', cela signifie que c'est un mur)
//                 draw_square(data);
//             }
//             // Ajoutez d'autres conditions pour d'autres types de tiles si nécessaire
//             x++;
//         }
//         y++;
//     }
// }
