#include "cub3d-bis.h"

// MAP INITIALISER
void	init_map(t_data *data)
{
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

    // Définition des dimensions de la carte
    data->map.w_map = MAP_WIDTH;
    data->map.h_map = MAP_HEIGHT;

    // Allocation de mémoire pour la carte 2D
    data->map.map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
    if (data->map.map2d == NULL) {
        // Gestion de l'erreur d'allocation de mémoire
		perror("fail in init_map\n");
		// mlx_destroy_display(data->mlx_ptr); // Clean up
        // (à implémenter selon les besoins)
        return;
    }

    int i = 0;
    while (i < MAP_HEIGHT)
    {
        data->map.map2d[i] = (char *)malloc(MAP_WIDTH + 1 * sizeof(char));
        if (data->map.map2d[i] == NULL) {
            // Gestion de l'erreur d'allocation de mémoire
            // (à implémenter selon les besoins)
            return;
        }
        
        int j = 0;
        while (j < MAP_WIDTH)
        {
            data->map.map2d[i][j] = '0';
            j++;
        }
		data->map.map2d[i][j] = '\0';
        i++;
    }
}

// MAP CONSTRUCTOR
t_map create_map(t_data *data) {
    t_map map;
    map.w_map = MAP_WIDTH;
    map.h_map = MAP_HEIGHT;

    // Allouer de la mémoire pour la grille
    map.map2d = (int **)malloc(MAP_HEIGHT * sizeof(int *));
    if (map.map2d == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la grille\n");
        exit(EXIT_FAILURE);
    }

    // Allouer de la mémoire pour chaque ligne de la grille
    int i = 0;
    while (i < MAP_HEIGHT) {
        map.map2d[i] = (int *)malloc(MAP_WIDTH * sizeof(int));
        if (map.map2d[i] == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation de mémoire pour une ligne de la grille\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Initialisation de la carte avec des valeurs par défaut (0 pour espace vide)
    int j = 0;
    while (j < MAP_WIDTH) {
        int i = 0;
        while (i < MAP_HEIGHT) {
            map.map2d[i][j] = 0;
            i++;
        }
        j++;
    }

    return map;
}



// MAP LAUNCHER
int	launch_map(t_data &data) 
{
    t_map map = creat_map(&data);
    // Initialiser la carte avec des valeurs (1 pour les murs, 0 pour les espaces vides)
    map.map2d[1][1] = 1; // Exemple : placer un mur à la position (1, 1)

    // Utilisation de la carte...

    // Libérer la mémoire lorsque vous avez terminé avec la carte
    freeMap(&map);

    return 0;
}
