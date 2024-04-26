#include "cub3d-bis.h"

int	key_hook_close_window(int keycode, t_data *data)
{
	// // Récupérer les données passées en paramètre
    // t_data *data = (t_data *)param;

    // Si la touche "Escape" est pressée, fermer la fenêtre
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
        exit(EXIT_SUCCESS); // Quitter le programme avec succès
    }
    return (0);
}

// int	render_next_frame(void *YourStruct);
// Prototype
// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
// void mlx_hook(pointeur sur mlx_window, Event, Mask, Function, Struct);
void	event_listener(t_data *data)
{
	// mlx_key_hook(data->mlx_win_ptr, ft_keyboard, data);
	// mlx_mouse_hook(data->mlx_win_ptr, ft_mouse, data);
	// mlx_hook(data->mlx_win_ptr, 17, 0, ft_shutdown, data);
	mlx_key_hook(data->mlx_win_ptr, key_hook_close_window, &data);
	// mlx_loop_hook(data->mlx_ptr, function, data);
	mlx_loop_hook(data->mlx_ptr, draw_map, &data); // Appel de draw_map à chaque boucle MLX
}

