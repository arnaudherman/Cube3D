#include "cub3d.h"

int	malloc_all(t_data *data)
{
	if (data == NULL)
	{
		perror("t_data pointer is NULL in malloc_all\n");
		return (-1);
	}
	data->keys = allocate_keys();
	data->image = allocate_image();
	data->map2d = allocate_image();
	data->world = allocate_image();
	data->player = allocate_player();
	if (data->keys == NULL)
	{
		printf("Failed to allocate keys\n");
		exit(1);
	}
	if (data->map2d == NULL || data->player == NULL
		|| data->image == NULL || data->world == NULL)
	{
		perror("Malloc of one ore more structures failed in malloc_all\n");
		free_if_malloc_failed(data);
		return (-1);
	}
	return (0);
}

int	init_default_all(t_data *data)
{
	data->mlx = (t_mlx){0};
	data->map = (t_map){0};
	data->fcolors = (t_color_info){0};
	data->ccolors = (t_color_info){0};
	data->NO = (t_image){0};
	data->SO = (t_image){0};
	data->WE = (t_image){0};
	data->EA = (t_image){0};
	if (malloc_all(data) != 0)
	{
		perror("Failed to malloc_all in init_default_all\n");
		return (-1);
	}
	return (0);
}

int	init_custom_all(t_data *data)
{
	if (init_mlx_engine(&data->mlx) != 0)
	{
		perror("Failed to initialize mlx_engine\n");
		return (1);
	}
	if (init_player(data->player) != 0)
	{
		perror("Failed to initialize player\n");
		return (1);
	}
	init_image(data, data->image, &data->mlx.mlx_ptr);
	init_world(data->world, &data->mlx);
	init_image(data, &data->NO, &data->mlx.mlx_ptr);
	init_image(data, &data->SO, &data->mlx.mlx_ptr);
	init_image(data, &data->WE, &data->mlx.mlx_ptr);
	init_image(data, &data->EA, &data->mlx.mlx_ptr);
	return (0);
}
