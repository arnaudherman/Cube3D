#include "cub3d-bis.h"

int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);
	

	// HERE in render nexxt frame line_length = 7680, bits_per_pixel = 32

	draw_map(data->image, &data->map);

	draw_player(&data);

	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);
	
	return (0);
}