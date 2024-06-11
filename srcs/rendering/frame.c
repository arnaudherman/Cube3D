#include "cub3d.h"

void	draw_world_bg(t_image *world, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(world, x, y, color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(world, x, y, 0xFFD700);
			x++;
		}
		y++;
	}
}

int	draw_player(t_image *image, t_player *player)
{
    int x, y;
    int x_center = (int)player->x_pos;
    int y_center = (int)player->y_pos;
    int half_size = player->size / 2;

    int x_start = x_center - half_size;
    int y_start = y_center - half_size;
    int x_end = x_center + half_size;
    int y_end = y_center + half_size;

    // Dessiner le joueur en parcourant les pixels du rectangle
    for (y = y_start; y < y_end; y++) {
        for (x = x_start; x < x_end; x++) {
            // Calcul des coordonnées du pixel dans le repère local du joueur
            // en soustrayant les coordonnées du centre du joueur
            int local_x = x - x_center;
            int local_y = y - y_center;

            // Rotation des coordonnées locales en fonction de l'angle du joueur
            int rotated_x = (int)(local_x * cos(player->angle) - local_y * sin(player->angle));
            int rotated_y = (int)(local_x * sin(player->angle) + local_y * cos(player->angle));

            // Ajout des coordonnées du centre du joueur pour obtenir les coordonnées globales
            int global_x = rotated_x + x_center;
            int global_y = rotated_y + y_center;

            // Dessiner le pixel seulement s'il est à l'intérieur du rectangle représentant le joueur
            if (global_x >= x_start && global_x < x_end && global_y >= y_start && global_y < y_end) {
                my_mlx_pixel_put(image, global_x, global_y, player->color);
            }
        }
    }
    return 0;
}

// Use mlx_put_image_to_window() with a recycled image that you have cleared
// to display the image on the window instead of mlx_clear_window()
int	render_next_frame(t_data *data)
{
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
	memset(data->world->addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT
		* (data->world->bits_per_pixel / 8));
	draw_map(data->map2d, &data->map);
	key_move(data, data->map2d->tile_size);
	draw_player(data->map2d, data->player);
	draw_world_bg(data->world, 0x0057B8);
	raycasting(data, data->player, &data->mlx);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr,
		data->world->img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr,
		data->map2d->img, 20, 20);
	return (0);
}
