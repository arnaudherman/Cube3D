#include "cub3d-bis.h"

t_image	*allocate_map2d(void)
{
	t_image *map2d;

	if (!(map2d = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	map2d->img = NULL;
	map2d->addr = NULL;
	map2d->bits_per_pixel = 0;
	map2d->line_length = 0;
	map2d->endian = 0;
	map2d->relative_path = NULL;
	return (map2d);
}

int init_map2d(t_image *map2d, t_mlx *mlx)
{
	printf("mlx->mlx_ptr: %p\n", mlx->mlx_ptr);
	// 0x6060000015e0
    map2d->img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (map2d->img == NULL) {
        perror("Failed to create map2d\n");
        return 1;
    }
    map2d->addr = mlx_get_data_addr(map2d->img, &(map2d->bits_per_pixel),
                                         &(map2d->line_length), &(map2d->endian));
    if (map2d->addr == NULL) {
        perror("Failed to get map2d data address\n");
        mlx_destroy_image(mlx->mlx_ptr, map2d->img);
        return 1;
    }
    map2d->relative_path = NULL;
    return 0;
}

t_image	*allocate_world(void)
{
	t_image *world;

	if (!(world = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	world->img = NULL;
	world->addr = NULL;
	world->bits_per_pixel = 0;
	world->line_length = 0;
	world->endian = 0;
	world->relative_path = NULL;
	return (world);
}

int init_world(t_image *world, t_mlx *mlx)
{
	printf("mlx->mlx_ptr: %p\n", mlx->mlx_ptr);
	// 0x6060000015e0
    world->img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (world->img == NULL) {
        perror("Failed to create image\n");
        return 1;
    }
    world->addr = mlx_get_data_addr(world->img, &(world->bits_per_pixel),
                                         &(world->line_length), &(world->endian));
    if (world->addr == NULL) {
        perror("Failed to get image data address\n");
        mlx_destroy_image(mlx->mlx_ptr, world->img);
        return 1;
    }
    world->relative_path = NULL;
    return 0;
}
