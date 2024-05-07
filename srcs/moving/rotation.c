#include "cub3d-bis.h"

void rotate_left(t_data *data) {
    data->player->angle -= 5;
    
    if (data->player->angle < 0)
        data->player->angle += 360;
    
    data->player->x_dir = cos(data->player->angle * M_PI / 180);
    data->player->y_dir = sin(data->player->angle * M_PI / 180);
}

void rotate_right(t_data *data) {
    data->player->angle += 5;

    if (data->player->angle >= 360)
        data->player->angle -= 360;
    
    data->player->x_dir = cos(data->player->angle * M_PI / 180);
    data->player->y_dir = sin(data->player->angle * M_PI / 180);
}
