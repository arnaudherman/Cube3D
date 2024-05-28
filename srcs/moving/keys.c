#include "cub3d-bis.h"

int		key_press(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys->w = 1;
	else if (key == KEY_A)
		data->keys->a = 1;
	else if (key == KEY_S)
		data->keys->s = 1;
	else if (key == KEY_D)
		data->keys->d = 1;
	else if (key == KEY_ESC)
		data->keys->esc = 1;
	else if (key == LEFT_ARR)
		data->keys->left = 1;
	else if (key == RIGHT_ARR)
		data->keys->right = 1;
	// printf("press key = %d\n", data->keys->w);
	return (0);
}

int		key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys->w = 0;
	else if (key == KEY_A)
		data->keys->a = 0;
	else if (key == KEY_S)
		data->keys->s = 0;
	else if (key == KEY_D)
		data->keys->d = 0;
	else if (key == KEY_ESC)
		data->keys->esc = 0;
	else if (key == LEFT_ARR)
		data->keys->left = 0;
	else if (key == RIGHT_ARR)
		data->keys->right = 0;
	// printf("release key = %d\n", data->keys->w);
	return (0);
}

void	key_move(t_data *data)
{
	printf("move key = %d\n", data->keys->w);
	if (data->keys->w == 1)
		go_up(data);
	else if (data->keys->a == 1)
		go_left(data);
	else if (data->keys->s == 1)
		go_down(data);
	else if (data->keys->d == 1)
		go_right(data);
	else if (data->keys->left == 1)
		rotate_left(data);
	else if (data->keys->right == 1)
		rotate_right(data);
	else if (data->keys->esc == 1)
		exit_game(data);
	if (player_wall_collision(&data->map, data->player->x_pos, data->player->y_pos))
		printf("Collision détectée!\n");
	else
		printf("Aucune collision.\n");
}

// static int	key_press(int key, t_data *data)
// {
// 	if (key == XK_Escape)
// 		quit_cub3d(data);
// 	if (key == XK_Left)
// 		data->player.rotate -= 1;
// 	if (key == XK_Right)
// 		data->player.rotate += 1;
// 	if (key == XK_w)
// 		data->player.y_move = 1;
// 	if (key == XK_a)
// 		data->player.x_move = -1;
// 	if (key == XK_s)
// 		data->player.y_move = -1;
// 	if (key == XK_d)
// 		data->player.x_move = 1;
// 	return (0);
// }

// static int	key_release(int key, t_data *data)
// {
// 	if (key == XK_Escape)
// 		quit_cub3d(data);
// 	if (key == XK_w && data->player.y_move == 1)
// 		data->player.y_move = 0;
// 	if (key == XK_s && data->player.y_move == -1)
// 		data->player.y_move = 0;
// 	if (key == XK_a && data->player.x_move == -1)
// 		data->player.x_move += 1;
// 	if (key == XK_d && data->player.x_move == 1)
// 		data->player.x_move -= 1;
// 	if (key == XK_Left && data->player.rotate <= 1)
// 		data->player.rotate = 0;
// 	if (key == XK_Right && data->player.rotate >= -1)
// 		data->player.rotate = 0;
// 	return (0);
// }

// static void	wrap_mouse_position(t_data *data, int x, int y)
// {
// 	if (x > data->win_width - MOUSE_BORDER_DISTANCE)
// 	{
// 		x = MOUSE_BORDER_DISTANCE;
// 		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
// 	}
// 	if (x < MOUSE_BORDER_DISTANCE)
// 	{
// 		x = data->win_width - MOUSE_BORDER_DISTANCE;
// 		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
// 	}
// }

// static int	mouse_motion(int x, int y, t_data *data)
// {
// 	static int	old_x = WINDOW_WIDTH / 2;

// 	wrap_mouse_position(data, x, y);
// 	if (x == old_x)
// 		return (0);
// 	else if (x < old_x)
// 		data->player.has_moved += rotate_player(data, -1);
// 	else if (x > old_x)
// 		data->player.has_moved += rotate_player(data, 1);
// 	old_x = x;
// 	return (0);
// }

