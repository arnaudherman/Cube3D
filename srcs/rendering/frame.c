#include "cub3d-bis.h"

int	render_next_frame(t_data *data)
{
	// Effacer l'image précédente (peut-être nécessaire si vous dessinez par-dessus)
	// mlx_clear_window(data->mlx_ptr, data->mlx_win_ptr);
	// printf("X) After : %d\n",  data->player.x_pos);

	// Call render functions to draw next frame
	draw_map(&data, &data->map);
		// printf("3) After : %d\n",  data->player.x_pos);

	draw_player(data);

	// Mettre à jour la fenêtre avec la nouvelle image
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->image->img, 0, 0);

	return (0);
}