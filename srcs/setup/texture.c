#include "cub3d.h"

// Use mlx function for xpm format and no leak

void init_texture_img(t_image *texture_img, t_mlx *mlx, char *path) 
{
	// 	texture_img->width = WINDOW_WIDTH;
	// 	texture_img->height = WINDOW_HEIGHT;
    texture_img->img = mlx_xpm_file_to_image(&mlx->mlx_ptr, path, &texture_img->width, &texture_img->height);
    if (!texture_img->img) {
        perror("Error: Failed to load texture image.\n");
        exit(1);
    }
    texture_img->addr = (int *)mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel, 
                    &texture_img->line_length, &texture_img->endian);
	 if (texture_img->addr == NULL) 
     {
		perror("Failed to get image data address\n");
        mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
		perror("Failed to get image data address in init_texture_img\n");
        return ;
    }
    // texture_img->road = NULL;
}

void init_textures(t_data *data, t_mlx *mlx) 
{
	init_texture_img(data->NO, mlx->mlx_ptr, "./assets/north.xpm");
	init_texture_img(data->SO, mlx->mlx_ptr, "./assets/south.xpm");
	init_texture_img(data->WE, mlx->mlx_ptr, "./assets/west.xpm");
	init_texture_img(data->EA, mlx->mlx_ptr, "./assets/east.xpm");
	// init_texture(&texture->floor, mlx, "./assets/floor.xpm", "./assets/north.xpm");
    // init_texture(&texture->ceiling, mlx, "./assets/ceiling.xpm", "./assets/north.xpm");

    return ;
}
