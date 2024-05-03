#include "cub3d-bis.h"

// void	update_pos(t_player *player, float x_pos, float y_pos)
// {
// 	player->x_pos += x_pos;
// 	player->y_pos += y_pos;
// }

// static int	up(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->player.x_pos + data->player.x_dir * SPEED;
// 	new_y = data->player.y_pos + data->player.y_dir * SPEED;
// 	return (is_valid_move(data, new_x, new_y));
// }

// static int	down(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->player.x_pos - data->player.x_dir * SPEED;
// 	new_y = data->player.y_pos - data->player.y_dir * SPEED;
// 	return (is_valid_move(data, new_x, new_y));
// }

// static int	left(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->player.x_pos + data->player.y_dir * SPEED;
// 	new_y = data->player.y_pos - data->player.x_dir * SPEED;
// 	return (is_valid_move(data, new_x, new_y));
// }

// static int	right(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->player.x_pos - data->player.y_dir * SPEED;
// 	new_y = data->player.y_pos + data->player.x_dir * SPEED;
// 	return (is_valid_move(data, new_x, new_y));
// }

// int	move(t_data *data)
// {
// 	int	moved;

// 	moved = 0;
// 	if (data->player.y_move == 1)
// 		moved += up(data);
// 	if (data->player.y_move == -1)
// 		moved += down(data);
// 	if (data->player.x_move == -1)
// 		moved += left(data);
// 	if (data->player.x_move == 1)
// 		moved += right(data);
// 	if (data->player.rotate != 0)
// 		moved += player_rotation(data, data->player.rotate);
// 	return (moved);
// }

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