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

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->image.img, 0, 0);
	mlx_loop_hook(data->mlx_ptr, &render_next_frame, data);
	return (0);
}
