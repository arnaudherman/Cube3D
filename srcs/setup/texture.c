#include "cub3d.h"

// Use mlx function for xpm format and no leak

void	init_texture_img(t_image *texture_img, void *mlx_ptr, char *path) 
{
    texture_img->img = mlx_xpm_file_to_image(mlx_ptr, path, &texture_img->width, &texture_img->height);
    if (!texture_img->img) {
        perror("Error: Failed to load texture image.\n");
        exit(EXIT_FAILURE);
    }
    texture_img->addr = (int *)mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel, 
                    &texture_img->line_length, &texture_img->endian);
    if (texture_img->addr == NULL) {
        perror("Failed to get image data address\n");
        mlx_destroy_image(mlx_ptr, texture_img->img);
        perror("Failed to get image data address in init_texture_img\n");
        exit(EXIT_FAILURE);
    }
}

void	init_textures(t_data *data, void *mlx_ptr) 
{
	init_texture_img(&data->NO, mlx_ptr, "./assets/north.xpm");
	init_texture_img(&data->SO, mlx_ptr, "./assets/south.xpm");
	init_texture_img(&data->WE, mlx_ptr, "./assets/west.xpm");
	init_texture_img(&data->EA, mlx_ptr, "./assets/east.xpm");
	// init_texture(&texture->floor, mlx, "./assets/floor.xpm", "./assets/north.xpm");
    // init_texture(&texture->ceiling, mlx, "./assets/ceiling.xpm", "./assets/north.xpm");

    return ;
}

// TO DO : TEMP FUNC : DELETE WHEN PARSING LINKED
void	set_texture_image_road(t_image *texture_img, t_ray *ray)
{
	if (ray->side == 1)
		texture_img->road = "./assets/east.xpm";
	else if (ray->side == 2)
		texture_img->road = "./assets/north.xpm";
	else if (ray->side == 3)	
		texture_img->road = "./assets/south.xpm";
	else
		texture_img->road = "./assets/west.xpm";
}
