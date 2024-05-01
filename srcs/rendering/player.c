#include "cub3d-bis.h"

int	draw_player(t_player *player, t_mlx *mlx)
{
    // Calcul des coordonnées de début et de fin du joueur
    int x_start = (int)(player->x_pos) - (player->size / 2);
	// printf("player->x_pos is : %d\n",  player->x_pos);
	// printf("x_start is : %d\n",  x_start);

    int y_start = (int)(player->y_pos) - (player->size / 2);

    int x_end = x_start + player->size;
    int y_end = y_start + player->size;
    
    // Dessin du joueur
    for (int y = y_start; y < y_end; y++)
    {
        for (int x = x_start; x < x_end; x++)
        {
            // Utilisation de la fonction de dessin de pixel de MLX
            mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win_ptr, x, y, player->color);
        }
    }
	return 0;
}