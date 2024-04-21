#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

int	init_mlx_engine(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return 1;
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, (data->win_width + 1) * TILE_SIZE, (data->win_height + 1) * TILE_SIZE, "Hello Cub3D!");
	data->image.img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.line_length,
								&data->image.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	// Put image to window
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->image.img, 0, 0);

	// 	Main events loop
	mlx_loop(data->mlx_ptr);
	return (0);
}

// void	init_game(t_data *data)
// {

// }

// void	init_image(t_data *data)
// {
		// data->image.img = 0;
		// data->image.addr = 0;
		// data->image.bits_per_pixel = 0;
		// data->image.line_length = 0;
		// data->image.endian = 0;
		// data->image.relative_path = "./test.xpm";
// }


void	init_map(t_data *data)
{
	char map_data[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
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

// void	init_player(t_data *data)
// {
		// data->player.x_pos = 0;
		// data->player.y_pos = 0;
		// data->player.x_move = 0;
		// data->player.y_move = 0;
		// data->player.x_dir = 0;
		// data->player.y_dir = 0;
		// data->player.x_plane = 0;
		// data->player.y_plane = 0;
		// data->player.speed = SPEED;
		// data->player.angle = 0;
		// data->player.fov = FOV;
		// data->player.rotate = ROTATION;
		// data->player.direction = 0;
		// data->player.size = 0;
		// data->player.color = 0;
		// data->player.has_moved = 0;
// }

// void	init_textures(t_data *data)
// {

// }

void	init_data(t_data *data)
{
	data->fd = 0;
	data->mlx_ptr = NULL;
	data->mlx_win_ptr = NULL;
	data->win_height = WINDOW_HEIGHT;
	data->win_width = WINDOW_WIDTH;
	init_mlx_engine(&data);
	// init_image(&data->image);
	init_map(&data->map);
	// init_minimap(&data->minimap);
	// init_player(&data->player);
	// init_ray(&data->ray);
	// init_texture(&data->texture);
	// init_color(&data->color);
}