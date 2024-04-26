#include "cub3d-bis.h"

int	init_mlx_engine(t_data *data)
{
	data->fd = 0;
	data->win_height = WINDOW_HEIGHT;
	data->win_width = WINDOW_WIDTH;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return 1;	
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Cub3D!");
	if (!data->mlx_win_ptr)
		return err("What the fuck is that\n");
	data->image.img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.line_length,
								&data->image.endian);
	draw_map(&data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->image.img, 0, 0);

	return (0);
}