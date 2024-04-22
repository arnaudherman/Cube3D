#include "cub3d-bis.h"

void	init_map(t_data *data)
{
	char map_data[MAP_WIDTH][MAP_HEIGHT] = {
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
    data->map.map2d = malloc(MAP_WIDTH * sizeof(char *));
    if (data->map.map2d == NULL) {
        // Gestion de l'erreur d'allocation de mémoire
		// mlx_destroy_display(data->mlx_ptr); // Clean up
        // (à implémenter selon les besoins)
        return;
    }

    int i = 0;
    while (i < MAP_WIDTH)
    {
        data->map.map2d[i] = malloc(MAP_HEIGHT * sizeof(char));
        if (data->map.map2d[i] == NULL) {
            // Gestion de l'erreur d'allocation de mémoire
            // (à implémenter selon les besoins)
            return;
        }
        
        int j = 0;
        while (j < MAP_HEIGHT)
        {
            data->map.map2d[i][j] = map_data[i][j];
            j++;
        }
        i++;
    }
}