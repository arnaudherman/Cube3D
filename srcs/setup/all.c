#include "cub3d-bis.h"

int malloc_struct(void **ptr, size_t size) {
    *ptr = malloc(size);
    if (*ptr == NULL) {
        perror("Allocation for struct failed\n");
        return -1;
    }
    return 0;
}

int malloc_all(t_data *data) {
    // Allocation de chaque structure
    if (malloc_struct((void **)&(data->image), sizeof(t_image)) == -1 ||
        malloc_struct((void **)&(data->map), sizeof(t_map)) == -1 ||
        malloc_struct((void **)&(data->player), sizeof(t_player)) == -1 ||
        // TO DO : Minimap problem, pointer is : 0x0
        // malloc_struct((void **)&(data->minimap), sizeof(t_minimap)) == -1 ||
        malloc_struct((void **)&(data->ray), sizeof(t_ray)) == -1 ||
        malloc_struct((void **)&(data->texture), sizeof(t_texture)) == -1 ||
        malloc_struct((void **)&(data->color), sizeof(t_color)) == -1) {
        perror("Error while mallocing all structs in malloc_all\n");
        return -1;
    }

    // Vérification si les pointeurs ont été correctement alloués
    if ((&data->image) == NULL || (&data->map) == NULL || (&data->player) == NULL ||
        // TO DO : handle minimap pointer 0x0
        // data->minimap == NULL || 
        (&data->ray) == NULL || (&data->texture) == NULL || (&data->color) == NULL) {
        perror("One or more structure pointers are NULL after malloc_all\n");
        return -1;
    }
	data->player.x_pos = 100;
    return 0;
}


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

int	init_specific_all(t_data *data)
{
	// Handle Image
	init_image(&data->image);
	data->image.img = mlx_new_image(&data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->image.img == NULL) {
        perror("Failed to create image\n");
        return 1;
    }
	data->image.addr = (int *)mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel,
			&data->image.line_length, &data->image.endian);

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

	// Handle MLX
	if (init_mlx_engine(data) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}

	return (0);
}
