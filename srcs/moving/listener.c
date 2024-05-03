#include "cub3d-bis.h"

int	key_hook_close_window(int keycode, t_data *data)
{
	// // Récupérer les données passées en paramètre
    // t_data *data = (t_data *)param;

    // Si la touche "Escape" est pressée, fermer la fenêtre
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr);
        exit(EXIT_SUCCESS); // Quitter le programme avec succès
    }
    return (0);
}

// void	event_listener(t_data *data)
// {
// 	// mlx_key_hook(data->mlx_win_ptr, ft_keyboard, data);
// 	// mlx_mouse_hook(data->mlx_win_ptr, ft_mouse, data);
// 	// mlx_key_hook(data->mlx.mlx_win_ptr, key_hook_close_window, &data);
// }
