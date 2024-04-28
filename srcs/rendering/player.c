#include "cub3d-bis.h"

int	draw_player(t_data *data)
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int y;
	int x;

	x_start = data->player.x_pos - (data->player.size / 2);
	y_start = data->player.y_pos - (data->player.size / 2);
	x_end = x_start + data->player.size;
    y_end = y_start + data->player.size;
	
	for (int y = y_start; y < y_end; y++)
    {
        for (int x = x_start; x < x_end; x++)
        {
            my_mlx_pixel_put(data, x, y, data->player.color);
        }
    }
	
	return 0;
}
