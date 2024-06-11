#include "cub3d.h"

void	draw_vertical_lines(t_image *map2d)
{
	int	x;

	x = 0;
	while (x < map2d->width)
	{
		draw_vertical_line(map2d, x, 0, 0xFFFFFF);
		draw_vertical_line(map2d, x, map2d->height - 1, 0xFFFFFF);
		x += map2d->tile_size;
	}
}

void	draw_horizontal_lines(t_image *map2d)
{
	int	y;

	y = 0;
	while (y < map2d->height)
	{
		draw_horizontal_line(map2d, 0, y, 0xFFFFFF);
		draw_horizontal_line(map2d, map2d->width - 1, y, 0xFFFFFF);
		y += map2d->tile_size;
	}
}

void	draw_vertical_line(t_image *map2d, int x, int start_y, int color)
{
	int	y;

	y = start_y;
	while (y < map2d->height)
	{
		my_mlx_pixel_put(map2d, x, y, color);
		y++;
	}
}

void	draw_horizontal_line(t_image *map2d, int start_x, int y, int color)
{
	int	x;

	x = start_x;
	while (x < map2d->width)
	{
		my_mlx_pixel_put(map2d, x, y, color);
		x++;
	}
}

int	draw_map(t_image *map2d, t_map *map)
{	
	int		x;
	int		y;
	char	tile;

	draw_minimap_bg(map2d, 0xbba498);
	draw_vertical_lines(map2d);
	draw_horizontal_lines(map2d);
	y = 0;
	while (map->map2d[y])
	{
		x = 0;
		while (map->map2d[y][x])
		{
			tile = map->map2d[y][x];
			if (tile == '0' || tile == 'N' || tile == 'S'
				|| tile == 'W' || tile == 'E')
				draw_tile(map2d, x * map2d->tile_size, y
					* map2d->tile_size);
			x++;
		}
		y++;
	}
	return (0);
}
