#include "cub3d-bis.h"

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

int	malloc_map2d(t_map *map)
{
    map->map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    if (map->map2d == NULL) {
		perror("fail in init_map\n");
        return -1;
    }
	return (0);
}

// Mmalloc lign by lign and i += 1 go to next lign
void	fill_map(t_map *map)
{
    int i;

	i = 0;
    while (i < MAP_HEIGHT) {
        map->map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char));
        if (map->map2d[i] == NULL) {
            perror("fail in fill_map\n");
            return;
        }
        
        int j = 0;
        while (j < MAP_WIDTH) {
            map->map2d[i][j] = map_data[i][j];
            j++;
        }
        map->map2d[i][MAP_WIDTH] = '\0';
        i++;
    }
}

int init_map(t_data *data)
{
    // Création d'une instance de t_map
    t_map map;

    // Initialisation des champs de la structure t_map
    map.w_map = MAP_WIDTH;
    map.h_map = MAP_HEIGHT;

    // Allocation de mémoire pour la carte 2D
    map.map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    if (map.map2d == NULL) {
        perror("Failed to allocate memory for map2d\n");
        return -1;
    }

    // Allocation et remplissage de chaque ligne de la carte 2D
    for (int i = 0; i < MAP_HEIGHT; i++) {
        map.map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char));
        if (map.map2d[i] == NULL) {
            perror("Failed to allocate memory for map2d row\n");
            // Si l'allocation échoue, libérez la mémoire précédemment allouée
            for (int j = 0; j < i; j++) {
                free(map.map2d[j]);
            }
            free(map.map2d);
            return -1;
        }
        // Copie des données de map_data dans la carte 2D
        for (int j = 0; j < MAP_WIDTH; j++) {
            map.map2d[i][j] = map_data[i][j];
        }
        map.map2d[i][MAP_WIDTH] = '\0'; // Ajout du caractère de fin de chaîne
    }

    // Initialisation des autres champs de la structure t_map
    map.x_map = 0;
    map.y_map = 0;
    map.color = 0;

    // Affectation de la structure t_map à l'objet data
    data->map = map;

    return 0;
}


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
