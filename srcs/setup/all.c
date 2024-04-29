#include "cub3d-bis.h"

int malloc_struct(t_data **data) {
    *data = malloc(sizeof(t_data));
    if (*data == NULL) {
        perror("Allocation for struct failed\n"); 
        return -1;
    }
    return 0;
}

int	malloc_all(t_data *data)
{
	if (malloc_struct(&(data->image)) == -1 ||
		malloc_struct(&(data->map)) == -1 ||
        malloc_struct(&(data->player)) == -1 ||
        malloc_struct(&(data->minimap)) == -1 ||
		malloc_struct(&(data->ray)) == -1 ||
		malloc_struct(&(data->texture)) == -1 ||
		malloc_struct(&(data->color)) == -1) {
		perror("error while mallocing all structs in malloc_all\n");
        return -1;
    }
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
	// Malloc all struct bro
	malloc_all(data);

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
