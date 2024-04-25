#include "cub3d-bis.h"

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

// int init_map(t_data *data)
// {
//     // Allocation de mémoire pour la carte 2D
//     if (malloc_map2d(&data->map) == -1) {
//         perror("Failed to allocate memory for map2d\n");
//         return -1;
//     }

//     // Remplissage des données de la carte 2D
//     fill_map(&data->map);

//     // Initialisation de la couleur de la carte en noir
//     data->map.color = 0x000000;

//     return 0;
// }

// int malloc_map2d(t_map *map)
// {
//     map->map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
//     if (map->map2d == NULL) {
//         perror("fail in malloc_map2d\n");
//         return -1;
//     }
//     return 0;
// }

// void fill_map(t_map *map)
// {
//     for (int i = 0; i < MAP_HEIGHT; i++) {
//         for (int j = 0; j < MAP_WIDTH; j++) {
//             map->map2d[i][j] = map_data[i][j];
//         }
//     }
// }

// void draw_map(t_data *data)
// {
//     // Dessiner les lignes de la carte
//     draw_vertical_lign(data);
//     draw_horizontal_lign(data);

//     // Dessiner les tuiles de la carte
//     for (int y = 0; y < MAP_HEIGHT; y++) {
//         for (int x = 0; x < MAP_WIDTH; x++) {
//             if (data->map.map2d[y][x] == '1') {
//                 // Dessiner une tuile de mur en utilisant la couleur définie
//                 draw_square(data, x * TILE_SIZE, y * TILE_SIZE, data->map.color);
//             }
//             // Ajoutez d'autres conditions pour d'autres types de tuiles si nécessaire
//         }
//     }
// }

// void draw_square(t_data *data, int x, int y, int color)
// {
//     for (int i = 0; i < TILE_SIZE; i++) {
//         for (int j = 0; j < TILE_SIZE; j++) {
//             my_mlx_pixel_put(data, x + i, y + j, color);
//         }
//     }
// }

// void	fill_map(t_map *map)
// {
//     int i;

// 	i = 0;
//     while (i < MAP_HEIGHT) {
//         map->map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char));
//         if (map->map2d[i] == NULL) {
//             perror("fail in fill_map\n");
//             return;
//         }
        
//         int j = 0;
//         while (j < MAP_WIDTH) {
//             map->map2d[i][j] = map_data[i][j];
//             j++;
//         }
//         map->map2d[i][MAP_WIDTH] = '\0';
//         i++;
//     }
// }

// // malloc lign by lign and i += 1 go to next lign
// int	malloc_map2d(t_map *map)
// {
//     map->map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
//     if (map->map2d == NULL) {
// 		perror("fail in init_map\n");
//         return -1;
//     }
// 	return (0);
// }

// int init_map(t_data *data)
// {
//     // Création d'une instance de t_map
//     t_map map;

//     // Initialisation des champs de la structure t_map
//     map.w_map = MAP_WIDTH;
//     map.h_map = MAP_HEIGHT;

//     // Allocation de mémoire pour la carte 2D
//     if (malloc_map2d(&map) == -1) {
//         perror("Failed to allocate memory for map2d\n");
//         return -1;
//     }

//     // Remplissage des données de la carte 2D
//     fill_map(&map);

//     // Initialisation de la couleur de la carte en noir
//     map.color = 0x000000;

//     // Affectation de la structure t_map à l'objet data
//     data->map = map;

//     return 0;
// }

// void fill_map(t_map *map)
// {
//     for (int i = 0; i < MAP_HEIGHT; i++) {
//         for (int j = 0; j < MAP_WIDTH; j++) {
//             map->map2d[i][j] = map_data[i][j];
//         }
//     }
// }

// void draw_map(t_data *data) {
//     // Dessiner les lignes de la carte
//     draw_vertical_lign(data);
//     draw_horizontal_lign(data);

//     // Dessiner les tuiles de la carte
//     for (int y = 0; y < MAP_HEIGHT; y++) {
//         for (int x = 0; x < MAP_WIDTH; x++) {
//             if (data->map.map2d[y][x] == '1') {
//                 // Dessiner une tuile de mur en utilisant la couleur définie
//                 draw_square(data, x * TILE_SIZE, y * TILE_SIZE, data->map.color);
//             }
//             // Ajoutez d'autres conditions pour d'autres types de tuiles si nécessaire
//         }
//     }
// }

// void draw_square(t_data *data, int x, int y, int color)
// {
//     for (int i = 0; i < TILE_SIZE; i++) {
//         for (int j = 0; j < TILE_SIZE; j++) {
//             my_mlx_pixel_put(data, x + i, y + j, data->map.color);
//         }
//     }
// }


// int init_map(t_data *data)
// {
//     // Création d'une instance de t_map
//     t_map map;

//     // Initialisation des champs de la structure t_map
//     map.w_map = MAP_WIDTH;
//     map.h_map = MAP_HEIGHT;

//     // Allocation de mémoire pour la carte 2D
//     if (malloc_map2d(&map) == -1) {
//         perror("Failed to allocate memory for map2d\n");
//         return -1;
//     }

//     // Allocation et remplissage de chaque ligne de la carte 2D
// 	fill_map(&map);
	
//     map.color = 0x000000;

//     // Affectation de la structure t_map à l'objet data
//     data->map = map;

//     return 0;
// }


// // MAP CONSTRUCTOR
// t_map create_map(t_data *data) {
//     t_map map;
//     map.w_map = MAP_WIDTH;
//     map.h_map = MAP_HEIGHT;

//     // Allouer de la mémoire pour la grille
//     map.map2d = (int **)malloc(MAP_HEIGHT * sizeof(int *));
//     if (map.map2d == NULL) {
//         fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la grille\n");
//         exit(EXIT_FAILURE);
//     }

//     // Allouer de la mémoire pour chaque ligne de la grille
//     int i = 0;
//     while (i < MAP_HEIGHT) {
//         map.map2d[i] = (int *)malloc(MAP_WIDTH * sizeof(int));
//         if (map.map2d[i] == NULL) {
//             fprintf(stderr, "Erreur lors de l'allocation de mémoire pour une ligne de la grille\n");
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }

//     // Initialisation de la carte avec des valeurs par défaut (0 pour espace vide)
//     int j = 0;
//     while (j < MAP_WIDTH) {
//         int i = 0;
//         while (i < MAP_HEIGHT) {
//             map.map2d[i][j] = 0;
//             i++;
//         }
//         j++;
//     }

//     return map;
// }



// // MAP LAUNCHER
// int	launch_map(t_data *data) 
// {
//     t_map map;
	
// 	map = create_map(&data);
// 	// TO DO : map already init in init_data main
// 	init_map(&data);
//     free_map(&map);

//     return 0;
// }
