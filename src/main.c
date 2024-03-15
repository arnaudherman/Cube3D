#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

void	my_mlx_pixel_put(t_data_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init()
{
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, 1920, 1080, 0);
}

// clear and free
// mlx_destroy_display(mlx);
// free(mlx);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data_mlx	img;

	// mlx_init create a xvar struct and return a pointer to it;
	mlx = mlx_init();
	if (mlx == NULL)
		return 1;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	init();
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}