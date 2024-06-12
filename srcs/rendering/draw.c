#include "cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_image *map2d, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map2d->tile_size)
	{
		j = 0;
		while (j < map2d->tile_size)
		{
			my_mlx_pixel_put(map2d, x + i, y + j, 0xb6d7a8);
			j++;
		}
		i++;
	}
}

void	draw_vertical_lign(t_data *data, int tile_size)
{
	while (data->map.x_map <= data->map.x_map * tile_size)
	{
		my_mlx_pixel_put(data, data->map.x_map, 0, 0xFFFFFF);
		my_mlx_pixel_put(data, data->map.x_map, data->map.y_map
			* tile_size, 0xFFFFFF);
		data->map.x_map += tile_size;
	}
}
