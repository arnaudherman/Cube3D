#include "cub3d-bis.h"

// int		key_press(int key_code, t_data *data)
// {
// 	if (key_code == KEY_W)
// 		data->keys->w = 1;
// 	else if (key_code == KEY_A)
// 		data->keys->a = 1;
// 	else if (key_code == KEY_S)
// 		data->keys->s = 1;
// 	else if (key_code == KEY_D)
// 		data->keys->d = 1;
// 	else if (key_code == KEY_ESC)
// 		data->keys->esc = 1;
// 	else if (key_code == LEFT_ARR)
// 		data->keys->left = 1;
// 	else if (key_code == RIGHT_ARR)
// 		data->keys->right = 1;
// 	return (0);
// }

// int		key_release(int key_code, t_data *data)
// {
// 	if (key_code == KEY_W)
// 		data->keys->w = 0;
// 	else if (key_code == KEY_A)
// 		data->keys->a = 0;
// 	else if (key_code == KEY_S)
// 		data->keys->s = 0;
// 	else if (key_code == KEY_D)
// 		data->keys->d = 0;
// 	else if (key_code == KEY_ESC)
// 		data->keys->esc = 0;
// 	else if (key_code == LEFT_ARR)
// 		data->keys->left = 0;
// 	else if (key_code == RIGHT_ARR)
// 		data->keys->right = 0;
// 	return (0);
// }

// void	event_listener(t_data *data)
// {
// 	if (data->keys->w == 1)
// 		move_forward(data->layout, data->player);
// 	else if (data->keys->a == 1)
// 		move_left(data->layout, data->player);
// 	else if (data->keys->s == 1)
// 		move_backward(data->layout, data->player);
// 	else if (data->keys->d == 1)
// 		move_right(data->layout, data->player);
// 	else if (data->keys->left == 1)
// 		rotate_left(data->player);
// 	else if (data->keys->right == 1)
// 		rotate_right(data->player);
// 	else if (data->keys->esc == 1)
// 		exit_game(data);
// }