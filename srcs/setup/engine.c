#include "cub3d.h"

int	init_mlx_engine(t_mlx *mlx)
{
	mlx->fd = 0;
	mlx->win_height = WINDOW_HEIGHT;
	mlx->win_width = WINDOW_WIDTH;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (1);
	mlx->mlx_win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Hello Cub3D!");
	if (!mlx->mlx_win_ptr)
		return (err("Youuuu failed to create a winnnndooooow\n"));
	return (0);
}
