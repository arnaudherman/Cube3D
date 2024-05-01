#include "cub3d-bis.h"

// // Allocation d'une structure t_map
// t_map *allocate_map() {
//     t_map *map;
	
// 	map = malloc(sizeof(t_map));
//     if (map == NULL) {
//         perror("Allocation for map failed\n");
//         exit(EXIT_FAILURE);
//     }
//     // Initialisation des membres de la structure ici si nécessaire
//     map->w_map = 0;
//     map->h_map = 0;
//     map->map2d = NULL;
//     map->x_map = 0;
//     map->y_map = 0;
//     map->color = 0;
//     map->ray = NULL; // Attention, t_ray doit être alloué séparément si nécessaire
//     return map;
// }

char map_data[MAP_HEIGHT][MAP_WIDTH] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

int malloc_map2d(t_map *map)
{
    map->map2d = (char **)malloc(map->h_map * sizeof(char *));
    if (map->map2d == NULL) {
        perror("fail in malloc_map2d\n");
        return -1;
    }
    return 0;
}

int fill_map(t_map *map)
{
    int i;

    // Allocation de mémoire pour chaque ligne de la carte 2D
    for (i = 0; i < map->h_map; i++) {
        map->map2d[i] = (char *)malloc((map->w_map + 1) * sizeof(char));
        if (map->map2d[i] == NULL) {
            perror("fail in fill_map\n");
            // Libérer la mémoire allouée pour les lignes précédentes
            while (i > 0) {
                free(map->map2d[--i]);
            }
            free(map->map2d);
            return -1;
        }
    }

    // Remplissage des données de la carte 2D
    for (i = 0; i < map->h_map; i++) {
        for (int j = 0; j < map->w_map; j++) {
            map->map2d[i][j] = map_data[i][j];
        }
        map->map2d[i][map->w_map] = '\0';
    }

    return 0;
}


int init_map(t_map *map)
{
	int i;
    // Initialisation des champs de la structure t_map
    map->w_map = MAP_WIDTH;
    map->h_map = MAP_HEIGHT;

    // Allocation de mémoire pour la carte 2D
    if (malloc_map2d(map) == -1) {
        perror("Failed to allocate memory for map2d\n");
        return -1;
    }
    // Remplissage des données de la carte 2D
    if (fill_map(map) != 0) {
		i = -1;
		// En cas d'échec, libérer la mémoire allouée précédemment
		while (++i < map->h_map)
            free(map->map2d[i]);
        free(map->map2d);
        return -1;
    }
	map->x_map = 0;
    map->y_map = 0;
    map->color = 0x000000;
	map->ray = allocate_ray();

    return 0;
}

