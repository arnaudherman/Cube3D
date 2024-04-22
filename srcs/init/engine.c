#include "cub3d-bis.h"

int	init_mlx_engine(t_data *data)
{
	data->fd = 0;
	data->mlx_ptr = NULL;
	data->mlx_win_ptr = NULL;
	data->win_height = WINDOW_HEIGHT;
	data->win_width = WINDOW_WIDTH;
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