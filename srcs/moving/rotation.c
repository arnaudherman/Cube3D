#include "cub3d.h"

// void rotate_left(t_data *data) {
//     data->player->angle -= 5.0;
// 	data->player->x_dir -= 5.0;
// 	data->player->y_dir -= 5.0; 
    
//     if (data->player->angle < 0.0)
//         data->player->angle += 360.0;
    
//     data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
//     data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
// }

// void rotate_right(t_data *data) {
//     data->player->angle += 5.0;

//     if (data->player->angle >= 360.0)
//         data->player->angle -= 360.0;
    
//     data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
//     data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
// }

// TEST
void rotate_left(t_data *data) {
    data->player->angle -= ROTATION;
    
    if (data->player->angle < 0.0)
        data->player->angle += 360.0;
    
    data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
    data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}

void rotate_right(t_data *data) {
    data->player->angle += ROTATION;

    if (data->player->angle >= 360.0)
        data->player->angle -= 360.0;
    
    data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
    data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}

// int	rotate_left_right(t_data *data, double rotspeed)
// {
// 	t_player	*player;
// 	double		tmp_x;

// 	player = &data->player;
// 	tmp_x = player->x_dir;
// 	player->x_dir = player->x_dir * cos(rotspeed) - player->y_dir * sin(rotspeed);
// 	player->y_dir = tmp_x * sin(rotspeed) + player->y_dir * cos(rotspeed);
// 	tmp_x = player->x_plane;
// 	player->x_plane = player->x_plane * cos(rotspeed) - player->y_plane * sin(rotspeed);
// 	player->y_plane = tmp_x * sin(rotspeed) + player->y_plane * cos(rotspeed);
// 	return (1);
// }

// int	rotate_player(t_data *data, double rotdir)
// {
// 	int		moved;
// 	double	rotspeed;

// 	moved = 0;
// 	rotspeed = ROTATION * rotdir;
// 	moved += rotate_left_right(data, rotspeed);
// 	return (moved);
// }