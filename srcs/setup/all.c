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

int malloc_all(t_data *data) {
	if (data == NULL) {
        perror("t_data pointer is NULL in malloc_all\n");
        return -1;
    }    
	data->image = allocate_image();
    data->player = allocate_player();
	data->keys = allocate_keys();
    data->ray = allocate_ray();
    data->texture = allocate_texture();
    data->color = allocate_color();

    if (data->image == NULL || data->player == NULL ||
        data->ray == NULL || data->texture == NULL || 
		data->color == NULL || data->keys == NULL) {
		perror("Malloc of one ore more structures failed in malloc_all\n");
		free_if_malloc_failed(data);
        return -1;
    }
    return 0;
}

int init_default_all(t_data *data)
{
	// memset(&data, 0, sizeof(data)); // attention jeune les pointeurs non définis sur des allocations de mémoire valides
    // *data = (t_data){0};
	// if (!(data = (t_data *)malloc(sizeof(t_data))))
	// 	return (NULL);
	// Init no pointer structure
	data->mlx = (t_mlx){0};
    data->map = (t_map){0};
	data->minimap = (t_minimap){0};

	// Malloc
	if (malloc_all(data) != 0) {
        perror("Failed to malloc_all in init_default_all\n");
        return -1;
    }

	// // Init pointer structures
	// *data->image = (t_image){0};
    // *data->player = (t_player){0};
    // *data->ray = (t_ray){0};
    // *data->texture = (t_texture){0};
    // *data->color = (t_color){0};
    return 0;
}

int	init_custom_all(t_data *data)
{
	// Handle MLX
	if (init_mlx_engine(&data->mlx) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}

	// Handle Image
	if (init_image(data->image, &data->mlx) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}
	
	// Handle Map
	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	// Handle Player
	if (init_player(data->player) != 0) {
		perror("Failed to initialize player\n");
		return 1;
	}
	return 0;
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
// 	return (0);
// }
