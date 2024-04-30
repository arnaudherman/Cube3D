#include "cub3d-bis.h"

// int check_allocations(t_data *data) 
// {
//     if (data->image == NULL || data->player == NULL || data->minimap == NULL ||
//         data->ray == NULL || data->texture == NULL || data->color == NULL) {
       
//         perror("You failed to allocate memory for 1 or + struct in check_allocations\n");
        
//         free(data->image);
//         // free(data->map); // Libérez la mémoire si vous avez alloué la structure map
//         free(data->player);
//         free(data->minimap);
//         free(data->ray);
//         free(data->texture);
//         free(data->color);
//         return -1;
//     }
//     return 0;
// }


// int malloc_all(t_data *data) {
//     // Allocation dynamique pour les membres de t_data
//     data->image = malloc(sizeof(t_image));
//     data->map = malloc(sizeof(t_map));
//     data->player = malloc(sizeof(t_player));
//     data->minimap = malloc(sizeof(t_minimap));
//     data->ray = malloc(sizeof(t_ray));
//     data->texture = malloc(sizeof(t_texture));
//     data->color = malloc(sizeof(t_color));

//     // Vérifiez si l'allocation a réussi
//     if (data->image == NULL || data->map == NULL || data->player == NULL ||
//         data->minimap == NULL || data->ray == NULL || data->texture == NULL || data->color == NULL) {
//         // Gestion de l'échec de l'allocation
//         // Assurez-vous de libérer toute mémoire allouée précédemment avant de retourner -1
//         return -1;
//     }
//     return 0;
// }


int init_default_all(t_data *data)
{
    // Initialise toutes les instances de t_data à zéro
    *data = (t_data){0};
    // Initialise les membres de la structure t_data à zéro ou à NULL
    data->image = (t_image){0};
    data->map = (t_map){0}; 
    data->player = (t_player){0};
    data->minimap = (t_minimap){0};
    data->ray = (t_ray){0};
    data->texture = (t_texture){0};
    data->color = (t_color){0};
    return 0;
}

int	init_data_all(t_data *data)
{
	// Handle MLX
	if (init_mlx_engine(data) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}

	// Handle Image
	if (init_image(&data->image) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}
	
	// Handle Map
	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	// Handle Player
	if (init_player(&data->player) != 0) {
		perror("Failed to initialize player\n");
		return 1;
	}

	// // Handle Minimap
	// if (init_minimap(&data->minimap) != 0) {
	// 	perror("Failed to initialize minimap\n");
	// 	return 1;
	// }

	// // Handle Ray
	// if (init_ray(&data->ray) != 0) {
	// 	perror("Failed to initialize ray\n");
	// 	return 1;
	// }

	// // Handle Texture
	// if (init_texture(&data->texture) != 0) {
	// 	perror("Failed to initialize texture\n");
	// 	return 1;
	// }

	// // Handle Color
	// if (init_color(&data->color) != 0) {
	// 	perror("Failed to initialize color\n");
	// 	return 1;
	// }

	

	return (0);
}
