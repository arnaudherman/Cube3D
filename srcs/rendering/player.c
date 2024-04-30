#include "cub3d-bis.h"

int	draw_player(t_data *data)
{
    // Calcul des coordonnées de début et de fin du joueur
    int x_start = (int)(data->player->x_pos) - (data->player->size / 2);
	// printf("data->player->x_pos is : %d\n",  data->player->x_pos);
	// printf("x_start is : %d\n",  x_start);

    int y_start = (int)(data->player->y_pos) - (data->player->size / 2);

    int x_end = x_start + data->player->size;
    int y_end = y_start + data->player->size;
    
    // Dessin du joueur
    for (int y = y_start; y < y_end; y++)
    {
        for (int x = x_start; x < x_end; x++)
        {
            // Utilisation de la fonction de dessin de pixel de MLX
            mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, x, y, data->player->color);
        }
    }
	return 0;
}