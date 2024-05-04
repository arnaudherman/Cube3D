#include "cub3d-bis.h"

int	go_up(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos + data->player->x_dir * SPEED;
	y_new = data->player->y_pos + data->player->y_dir * SPEED;
	return (good_move(data, x_new, y_new));
}

int	go_left(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos + data->player->y_dir * SPEED;
	y_new = data->player->y_pos - data->player->x_dir * SPEED;
	return (good_move(data, x_new, y_new));
}

int	go_down(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos - data->player->x_dir * SPEED;
	y_new = data->player->y_pos - data->player->y_dir * SPEED;
	return (good_move(data, x_new, y_new));
}

int	go_right(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos - data->player->y_dir * SPEED;
	y_new = data->player->y_pos + data->player->x_dir * SPEED;
	return (good_move(data, x_new, y_new));
}

int	move(t_data *data)
{
	int	go;

	go = 0;
	if (data->player->y_move == 1)
		go += go_up(data);
	if (data->player->y_move == -1)
		go += go_down(data);
	if (data->player->x_move == -1)
		go += go_left(data);
	if (data->player->x_move == 1)
		go += go_right(data);
	// if (data->player->rotate != 0)
	// 	go += go_rotate(data, data->player->rotate);
	return (go);
}

// void	move_forward(t_layout *layout, t_player *player)
// {
// 	if (layout->map[(int)(player->pos_y)]
// 		[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
// 		set_position(player, player->dir_x * player->mov_speed, 0);
// 	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
// 		[(int)(player->pos_x)] == 0)
// 		set_position(player, 0, player->dir_y * player->mov_speed);
// }

// void	move_backward(t_layout *layout, t_player *player)
// {
// 	if (layout->map[(int)(player->pos_y)]
// 		[(int)(player->pos_x - player->dir_x * player->mov_speed)] == 0)
// 		set_position(player, -(player->dir_x * player->mov_speed), 0);
// 	if (layout->map[(int)(player->pos_y - player->dir_y * player->mov_speed)]
// 		[(int)(player->pos_x)] == 0)
// 		set_position(player, 0, -(player->dir_y * player->mov_speed));
// }

// void	move_right(t_layout *layout, t_player *player)
// {
// 	if (layout->map[(int)(player->pos_y)]
// 		[(int)(player->pos_x + player->plan_x * player->mov_speed)] == 0)
// 		set_position(player, player->plan_x * player->mov_speed, 0);
// 	if (layout->map[(int)(player->pos_y + player->plan_y * player->mov_speed)]
// 		[(int)(player->pos_x)] == 0)
// 		set_position(player, 0, player->plan_y * player->mov_speed);
// }

// void	move_left(t_layout *layout, t_player *player)
// {
// 	if (layout->map[(int)(player->pos_y)]
// 		[(int)(player->pos_x - player->plan_x * player->mov_speed)] == 0)
// 		set_position(player, -(player->plan_x * player->mov_speed), 0);
// 	if (layout->map[(int)(player->pos_y - player->plan_y * player->mov_speed)]
// 		[(int)(player->pos_x)] == 0)
// 		set_position(player, 0, -(player->plan_y * player->mov_speed));
// }