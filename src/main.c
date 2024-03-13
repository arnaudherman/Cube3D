/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:34 by aherman           #+#    #+#             */
/*   Updated: 2024/03/13 21:39:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	// t_data	data;

// 	// if (argc != 2)
// 	// 	ft_error(ERROR_NBR_ARG);
// 	// if (!parsing(argv, &data))
// 	// 	return (0);
// }

int mapX = 8;
int mapY = 8;
int mapS = 64;
int map[] =
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data_mlx	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	init();
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}