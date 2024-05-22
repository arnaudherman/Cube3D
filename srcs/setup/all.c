#include "cub3d-bis.h"

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
    data->ray = allocate_ray();
    data->color = allocate_color();	

    if (data->map2d == NULL || data->world == NULL ||
		data->player == NULL || data->keys == NULL ||
        data->ray == NULL || data->color == NULL ||
		data->NO == NULL || data->SO == NULL ||
		data->WE == NULL || data->EA == NULL ||
		data->floor == NULL || data->ceiling == NULL ) {
		perror("Malloc of one ore more structures failed in malloc_all\n");
		free_if_malloc_failed(data);
        return -1;
    }
    return 0;
}

// New syntax try
// int malloc_all(t_data *data) {
//     data->map2d = (t_image *)malloc(sizeof(t_image));
//     data->world = (t_image *)malloc(sizeof(t_image));
//     data->player = (t_player *)malloc(sizeof(t_player));
//     data->keys = (t_keys *)malloc(sizeof(t_keys));
//     data->ray = (t_ray *)malloc(sizeof(t_ray));
//     data->color = (t_color *)malloc(sizeof(t_color));
//     data->texture = (t_texture *)malloc(sizeof(t_texture));

//     if (!data->map2d || !data->world || !data->player || !data->keys || !data->ray || !data->color || !data->texture) {
//         perror("Failed to allocate memory in malloc_all\n");
//         return -1;
//     }

//     return 0;
// }


int init_default_all(t_data *data)
{
	data->mlx = (t_mlx){0};
    data->map = (t_map){0};
	data->fcolors = (t_color){0};
	data->ccolors = (t_color){0};

	if (malloc_all(data) != 0) {
        perror("Failed to malloc_all in init_default_all\n");
        return -1;
    }
	// init_texture(data->texture);
    // init_textures(data->texture, &data->mlx);
    return 0;
}
 
int	init_custom_all(t_data *data)
{
	
	if (init_mlx_engine(&data->mlx) != 0) {
		perror("Failed to initialize mlx_engine\n");
		return 1;
	}

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
	// Image 3++
	if (init_all_textures(data, &data->mlx) != 0) {
		perror("Failed to initialize NO\n");
		return 1;
	}

	if (init_map(&data->map) != 0) {
		perror("Failed to initialize map\n");
		return 1;
	}

	if (init_player(data->player) != 0) {
		perror("Failed to initialize player\n");
		return 1;
	}

	if (init_rays(data->ray, data->player) != 0) {
		perror("Failed to initialize rays\n");
		return 1;
	}

	return 0;
}
