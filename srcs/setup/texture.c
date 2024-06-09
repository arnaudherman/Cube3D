#include "cub3d.h"

// Use mlx function for xpm format and no leak
// void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

// void	init_texture(t_data *data)
// {
// 	data->texture.NO = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.NO, data->win_height, data->win_height);
// 	data->texture.SO = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.SO, data->win_height, data->win_height);
// 	data->texture.WE = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.WE, data->win_height, data->win_height);
// 	data->texture.EA = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.EA, data->win_height, data->win_height);
// 	data->texture.found = 0;
// 	data->texture.size = TEXTURE;
// }

void init_texture_img(t_image *texture_img, t_mlx *mlx, char *path) 
{
	// 	texture->width = WINDOW_WIDTH;
	// 	texture->height = WINDOW_HEIGHT;
    texture_img->img = mlx_xpm_file_to_image(&mlx->mlx_ptr, path, &texture_img->width, &texture_img->height);
    if (!texture_img->img) {
        perror("Error: Failed to load texture image.\n");
        exit(1);
    }
    texture_img->addr = (int *)mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel, &texture_img->line_length, &texture_img->endian);
	 if (texture_img->addr == NULL) {
		perror("Failed to get image data address\n");
        mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
		perror("Failed to get image data address in init_texture_img\n");
        return ;
    }
    // texture_img->relative_path = NULL;
}

void init_textures(t_texture *texture, t_mlx *mlx) 
{
	init_texture_img(&texture->NO, mlx->mlx_ptr, "./assets/north.xpm");
	init_texture_img(&texture->SO, mlx->mlx_ptr, "./assets/north.xpm");
	init_texture_img(&texture->WE, mlx->mlx_ptr, "./assets/north.xpm");
	init_texture_img(&texture->EA, mlx->mlx_ptr, "./assets/north.xpm");
	// init_texture(&texture->floor, mlx, "./assets/floor.xpm", "./assets/north.xpm");
    // init_texture(&texture->ceiling, mlx, "./assets/ceiling.xpm", "./assets/north.xpm");

    return ;
}
