#include "cub3d-bis.h"

int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);
	// printf("X) After : %d\n",  data->player.x_pos);

	draw_map(data, &data->map);

	draw_player(data);

	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);

	return (0);
}