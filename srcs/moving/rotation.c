#include "cub3d-bis.h"

void rotate_left(t_data *data) {
    data->player->angle -= 5.0;
	data->player->x_dir -= 5.0;
	data->player->y_dir -= 5.0; 
    
    if (data->player->angle < 0.0)
        data->player->angle += 360.0;
    
    data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
    data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}

void rotate_right(t_data *data) {
    data->player->angle += 5.0;

    if (data->player->angle >= 360.0)
        data->player->angle -= 360.0;
    
    data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
    data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}
