#include "cub3d-bis.h"

// void	init_map(t_data *data)
// {
// 	char map_data[MAP_HEIGHT][MAP_WIDTH] = {
//         {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
//         {'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
//         {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
//         {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
//         {'1', '0', '1', '1', '1', '1', '0', '1', '0', '1'},
//         {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
//         {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
//         {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
//         {'1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
//         {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
//     };

//     // Définition des dimensions de la carte
//     data->map.w_map = MAP_WIDTH;
//     data->map.h_map = MAP_HEIGHT;

//     // Allocation de mémoire pour la carte 2D
//     data->map.map2d = (char **)malloc(MAP_HEIGHT * sizeof(char *));
//     if (data->map.map2d == NULL) {
//         // Gestion de l'erreur d'allocation de mémoire
// 		perror("fail in init_map\n");
// 		// mlx_destroy_display(data->mlx_ptr); // Clean up
//         // (à implémenter selon les besoins)
//         return;
//     }

//     int i = 0;
//     while (i < MAP_HEIGHT)
//     {
//         data->map.map2d[i] = (char *)malloc(MAP_WIDTH + 1 * sizeof(char));
//         if (data->map.map2d[i] == NULL) {
//             // Gestion de l'erreur d'allocation de mémoire
//             // (à implémenter selon les besoins)
//             return;
//         }
        
//         int j = 0;
//         while (j < MAP_WIDTH)
//         {
//             data->map.map2d[i][j] = '0';
//             j++;
//         }
// 		data->map.map2d[i][j] = '\0';
//         i++;
//     }
// }

void init_map(t_data *data)
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
        perror("fail in init_map\n");
        return;
    }

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        data->map.map2d[i] = (char *)malloc((MAP_WIDTH + 1) * sizeof(char));
        if (data->map.map2d[i] == NULL) {
            // Gestion de l'erreur d'allocation de mémoire
            // (à implémenter selon les besoins)
            return;
        }
        // Copier les données de map_data dans data->map.map2d
        memcpy(data->map.map2d[i], map_data[i], MAP_WIDTH);
        // Terminer la chaîne de caractères avec '\0'
        data->map.map2d[i][MAP_WIDTH] = '\0';
    }
}