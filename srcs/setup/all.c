#include "cub3d-bis.h"

void check_if_malloc_failed(t_data *data) {
 	if (data->map2d == NULL || data->world == NULL ||
		data->player == NULL || data->keys == NULL ||
        data->ray == NULL || data->color == NULL ||
		data->NO == NULL || data->SO == NULL ||
		data->WE == NULL || data->EA == NULL ||
		data->floor == NULL || data->ceiling == NULL ) {
		perror("Malloc of one ore more structures failed in malloc_all\n");
		free_if_malloc_failed(data);
        return ;
		exit(EXIT_FAILURE);
    }
}

int malloc_all(t_data *data) {
	if (data == NULL) {
        perror("t_data pointer is NULL in malloc_all\n");
        return -1;
    }    
	data->map2d = allocate_image();
	data->world = allocate_image();
	data->NO = allocate_image();
	data->SO = allocate_image();
	data->WE = allocate_image();
	data->EA = allocate_image();
	data->floor = allocate_image();
	data->ceiling = allocate_image();
    data->player = allocate_player();
	data->keys = allocate_keys();
    // data->ray = allocate_ray();
    data->color = allocate_color();	

	check_if_malloc_failed(data);
   
    return 0;
}

int init_default_all(t_data *data)
{
	data->mlx = (t_mlx){0};
    data->map = (t_map){0};
	data->fcolors = (t_color){0};
	data->ccolors = (t_color){0};

	// Handle dynamic allocation structs on the heap
	malloc_all(data);

    return 0;
}

int init_images(t_data *data)
{
	// Image 1
	if (init_map2d(data->map2d, &data->mlx) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	// Image 2
	if (init_world(data->world, &data->mlx) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	// Images for textures
	if (init_all_textures(data, &data->mlx) != 0) {
		perror("Failed to initialize NO\n");
		return 1;
	}
}

int	init_custom_all(t_data *data)
{
	
	if (init_mlx_engine(&data->mlx) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}

	init_images(data);

	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	if (init_player(data->player) != 0) {
		perror("Failed to initialize player\n");
		return 1;
	}

	return 0;
}
