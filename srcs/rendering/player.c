#include "cub3d-bis.h"

int	draw_player(t_data *data)
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int y;
	int x;

	x_start = data->player.x_pos;
	printf("effae%d\n",  data->player.x_pos);
	printf("effae%d\n",  x_start);

	y_start = data->player.y_pos;

	x_end = x_start + data->player.size;
    y_end = y_start + data->player.size;
	
	for (int y = y_start; y < y_end; y++)
    {
        for (int x = x_start; x < x_end; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x7FFF00);
        }
    }
	
	return 0;
}

// int draw_player(t_data *data)
// {
//     int player_size = data->player.size;
//     int player_color = data->player.color;
//     int player_x = (int)data->player.x_pos;
//     int player_y = (int)data->player.y_pos;

//     // Dessiner un carré représentant le joueur
//     for (int y = player_y - player_size / 2; y < player_y + player_size / 2; y++)
//     {
//         for (int x = player_x - player_size / 2; x < player_x + player_size / 2; x++)
//         {
//             my_mlx_pixel_put(data, x, y, player_color);
//         }
//     }
// 	return 0;
// }