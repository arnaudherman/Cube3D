#include "cub3d-bis.h"

// int	key_hook_close_window(int key, t_data *data)
// {
// 	// // Récupérer les données passées en paramètre
//     // t_data *data = (t_data *)param;

//     if (key == ESC_KEY)
//     {
//         mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
//         exit(EXIT_SUCCESS); // Quitter le programme avec succès
//     }
//     return (0);
// }

// Handle key press events && exit game
void	event_listener(t_data *data)
{
	mlx_hook(data->mlx.mlx_win_ptr, KEY_PRESS, 1L << 0, key_press, data);
	mlx_hook(data->mlx.mlx_win_ptr, KEY_RELEASE, 1L << 1, key_release, data);
	mlx_hook(data->mlx.mlx_win_ptr, 17, 1L << 17, exit_game, data);

	// TO DO : or close window 
	// mlx_key_hook(data->mlx.mlx_win_ptr, key_hook_close_window, &data);

	// mlx_key_hook(data->mlx_win_ptr, ft_keyboard, data);
	// mlx_mouse_hook(data->mlx_win_ptr, ft_mouse, data);
	// mlx_key_hook(data->mlx.mlx_win_ptr, key_hook_close_window, &data);
}


// int key_hook(int key, t_player *player, t_data *data) {
//     update_player_position(&player, key);
//     draw_map(data->image, &data->map);
//     return (0);
// }