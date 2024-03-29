#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

// L'offset mémoire pour un pixel à une certaine position (x, y) dans l'image
// y * line_length : cela détermine la position verticale dans l'image en prenant en compte la longueur de la ligne.
// x * (bits_per_pixel / 8) : cela détermine la position horizontale en prenant en compte le nombre de bits par pixel et le divisant par 8 pour obtenir le nombre d'octets.
// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	init()
// {
// 	glClearColor(0.3, 0.3, 0.3, 0);
// 	gluOrtho2D(0, 1920, 1080, 0);
// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// ft_bzero(&data, sizeof(t_data));
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

// clear and free
// mlx_destroy_display(mlx);
// free(mlx);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "./test.xpm";


	// mlx_init create a xvar struct and return a pointer to it;
	mlx = mlx_init();
	if (mlx == NULL)
		return 1;
	// read from an image (PNG format leaks memory)
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img.win_width, &img.win_height);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// init();
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(mlx, render_next_frame, YourStruct);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}