#include "cub3d.h"

// Main function to clean used ressources
// int clean_all(t_data *data)
// {
// 	// Liberer dabord la memoire liee au struct bro
// 	free_map(&data->map);
// 	mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);	
// 	mlx_destroy_display(data->mlx_ptr);
// 	return (0);
// }

// void free_structs(t_data *data) {
//     // Libérer la mémoire de la structure image
//     mlx_destroy_image(data->mlx_ptr, data->image.img);
//     free(data->image.addr);

//     // Libérer la mémoire de la structure map
//     for (int i = 0; i < data->map.h_map; i++) {
//         free(data->map.map2d[i]);
//     }
//     free(data->map.map2d);

//     // Libérer la mémoire de la structure minimap
//     for (int i = 0; i < data->minimap.size; i++) {
//         free(data->minimap.map[i]);
//     }
//     free(data->minimap.map);
//     free(data->minimap.img);

//     // Ajuster pour libérer d'autres structures si nécessaire

//     // Libérer la mémoire de la structure principale
//     free(data);
// }

void	free_if_malloc_failed(t_data *data)
{
    // Libération de la mémoire allouée dynamiquement
    free(data->map2d);
	free(data->world);
    free(data->player);
    free(data->keys);
    free(data->ray);
    free(data->texture);
    free(data->color);
}


void	free_all(t_data *data)
{
    // Free pointers 
    free(data->map2d);
	free(data->world);
    free(data->player);
    free(data->keys);
    free(data->ray);
    free(data->texture);
    free(data->color);
	// Free instances
	for (int i = 0; i < data->map.h_map; ++i) {
        free(data->map.map2d[i]);
    }
    free(data->map.map2d);
}