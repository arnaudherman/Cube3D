#include "cub3d-bis.h"

// Fonction pour libérer la mémoire de la carte
void free_map(t_map *map) {
    int i = 0;
    while (i < map->h_map) {
        free(map->map2d[i]);
        i++;
    }
    free(map->map2d);
}