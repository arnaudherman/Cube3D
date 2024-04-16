#include "cub3d-bis.h"

static int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.y_move = 1;
	if (key == XK_a)
		data->player.x_move = -1;
	if (key == XK_s)
		data->player.y_move = -1;
	if (key == XK_d)
		data->player.x_move = 1;
	return (0);
}

static int	key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_w && data->player.y_move == 1)
		data->player.y_move = 0;
	if (key == XK_s && data->player.y_move == -1)
		data->player.y_move = 0;
	if (key == XK_a && data->player.x_move == -1)
		data->player.x_move += 1;
	if (key == XK_d && data->player.x_move == 1)
		data->player.x_move -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static void	wrap_mouse_position(t_data *data, int x, int y)
{
	if (x > data->win_width - MOUSE_BORDER_DISTANCE)
	{
		x = MOUSE_BORDER_DISTANCE;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x < MOUSE_BORDER_DISTANCE)
	{
		x = data->win_width - MOUSE_BORDER_DISTANCE;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
}

static int	mouse_motion(int x, int y, t_data *data)
{
	static int	old_x = WINDOW_WIDTH / 2;

	wrap_mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.has_moved += rotate_player(data, -1);
	else if (x > old_x)
		data->player.has_moved += rotate_player(data, 1);
	old_x = x;
	return (0);
}

void	listen_input(t_data *data)
{
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, quit_cub3d, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, key_release_handler, data);
	if (BONUS)
		mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
			mouse_motion, data);
}