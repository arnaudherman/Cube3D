// #include "cub3d-bis.h"

// void init_map(t_data *data)
// {
// 	// TO DO : Allouez et initialisez votre carte
//     data->map.map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
//     int i = 0;
//     while (i < MAP_HEIGHT) {
//         data->map.map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char)); // +1 pour le caractère de fin de chaîne '\0'
//         int j = 0;
//         while (j < MAP_WIDTH) {
//             // Initialiser votre carte selon votre logique (par exemple, '1' pour un mur, '0' pour vide, etc.)
//             data->map.map2d[i][j] = '0'; // Par défaut, supposons que toutes les cases sont vides
//             j++;
//         }
//         data->map.map2d[i][j] = '\0'; // Terminer la chaîne de caractères
//         i++;
// 	}
// }

// void init_my_map()
// {
// 	int map2d[MAP_WIDTH][MAP_HEIGHT] = {
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//         {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
//         {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
//         {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
//         {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
//         {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
//         {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
//         {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
//         {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//     };

// 	int rows = sizeof(map2d)/sizeof(map2d[0]);
// 	int columns = sizeof(map2d[0])/sizeof(map2d[0][0]);

// 	printf("rows: %d\n", rows);
// 	printf("columns: %d\n", columns);
// }

// void draw_square(void *mlx_ptr, void *win_ptr, t_player *player, t_data *data, t_map *map)
// {
//     int i;
//     int j;

// 	init_my_map();

//     i = 0;
//     while (i < MAP_WIDTH)
//     {
//         j = 0;
//         while (j < MAP_HEIGHT)
//         {
//             my_mlx_pixel_put(data, player->x_pos + i, player->y_pos + j, map->color);
//             j++;
//         }
//         i++;
//     }
// }

// // TO DO : USE draw_map(data.mlx_ptr, data.win_ptr, data.player);

// void draw_map(void *mlx_ptr, void *win_ptr, t_player player) {
//     int x = 0;
//     int y = 0;
// 	t_map *map;

// 	map = (t_map *)malloc(sizeof(t_map));

//     // Dessiner les lignes verticales
//     while (x <= MAP_WIDTH * TILE_SIZE) {
//         mlx_pixel_put(mlx_ptr, win_ptr, x, 0, 0xFFFFFF); // Ligne en haut
//         mlx_pixel_put(mlx_ptr, win_ptr, x, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Ligne en bas
//         x += TILE_SIZE;
//     }

//     // Dessiner les lignes horizontales
//     while (y <= MAP_HEIGHT * TILE_SIZE) {
//         mlx_pixel_put(mlx_ptr, win_ptr, 0, y, 0xFFFFFF); // Ligne à gauche
//         mlx_pixel_put(mlx_ptr, win_ptr, MAP_WIDTH * TILE_SIZE, y, 0xFFFFFF); // Ligne à droite
//         y += TILE_SIZE;
//     }

//     // Dessiner les tiles
//     y = 0;
//     while (y < MAP_HEIGHT) {
//         x = 0;
//         while (x < MAP_WIDTH) {
//             if (map->map2d[y][x] == 1) {
//                 // Dessiner une tile de mur (si map2d[y][x] est 1, cela signifie que c'est un mur)
//                 draw_square(mlx_ptr, win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
//             }
//             // Ajoutez d'autres conditions pour d'autres types de tiles si nécessaire
//             x++;
//         }
//         y++;
//     }
//     // Dessiner le joueur
//     draw_player(mlx_ptr, win_ptr, &player);
// }
