#include "cub3d-bis.h"

int	draw_player(t_player *player, t_mlx *mlx)
{
    // Calcul des coordonnées de début et de fin du joueur
	int x;
	int y;
    int x_start;
	int x_end;
	int y_start;
	int y_end;


	x_start = (int)(player->x_pos) - (player->size / 2);
    y_start = (int)(player->y_pos) - (player->size / 2);

	// printf("player->x_pos is : %d\n",  player->x_pos);
	// printf("x_start is : %d\n",  x_start);
	// printf("y_start is : %d\n",  y_start);

    x_end = x_start + player->size;
    y_end = y_start + player->size;

    // Dessin du joueur
    for (y = y_start; y < y_end; y++)
    {
        for (x = x_start; x < x_end; x++)
        {
            // Utilisation de la fonction de dessin de pixel de MLX
            mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win_ptr, x, y, player->color);
        }
    }
	return 0;
}