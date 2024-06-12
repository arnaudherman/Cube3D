#include "cub3d.h"

t_image	*allocate_image(void)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
	{
		perror("Failed to allocate t_image");
		return (NULL);
	}
	image->width = 0;
	image->height = 0;
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->road = NULL;
	image->texture_found = 0;
	image->tile_size = 0;
	return (image);
}

int	init_map2d(t_image *map2d, t_mlx *mlx, int nb_tiles_x, int nb_tiles_y)
{
	map2d->width = 320;
	map2d->height = map2d->width;
	if (nb_tiles_x > nb_tiles_y)
		map2d->tile_size = map2d->width / nb_tiles_x;
	else
		map2d->tile_size = map2d->height / nb_tiles_y;
	map2d->img = mlx_new_image(mlx->mlx_ptr, map2d->width, map2d->height);
	if (map2d->img == NULL)
	{
		perror("Failed to create map2d\n");
		return (1);
	}
	map2d->addr = mlx_get_data_addr(map2d->img, &(map2d->bits_per_pixel),
			&(map2d->line_length), &(map2d->endian));
	if (map2d->addr == NULL)
	{
		perror("Failed to get map2d data address\n");
		mlx_destroy_image(mlx->mlx_ptr, map2d->img);
		return (1);
	}
	map2d->road = NULL;
	return (0);
}

int	init_world(t_image *world, t_mlx *mlx)
{
	world->width = WINDOW_WIDTH;
	world->height = WINDOW_HEIGHT;
	world->img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (world->img == NULL)
	{
		perror("Failed to create image\n");
		return (1);
	}
	world->addr = mlx_get_data_addr(world->img, &(world->bits_per_pixel),
			&(world->line_length), &(world->endian));
	if (world->addr == NULL)
	{
		perror("Failed to get image data address\n");
		mlx_destroy_image(mlx->mlx_ptr, world->img);
		return (1);
	}
	world->road = NULL;
	return (0);
}

int	init_image(t_data *data, t_image *image, t_mlx *mlx)
{
	image->img = mlx_new_image(&mlx->mlx_ptr, data->mlx.win_width,
			data->mlx.win_height);
	if (!image->img)
	{
		write(2, "Erreur: Impossible de créer l'image.\n", 37);
		return (-1);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
	{
		write(2, "Erreur: Impossible d'obtenir les données de l'image.\n", 55);
		return (-1);
	}
	return (0);
}
