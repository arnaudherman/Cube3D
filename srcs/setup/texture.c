#include "cub3d-bis.h"

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

// void init_texture_img(t_image *texture_img, t_mlx *mlx, char *path) 
// {
// 	// 	texture->width = WINDOW_WIDTH;
// 	// 	texture->height = WINDOW_HEIGHT;
//     texture_img->img = mlx_xpm_file_to_image(&mlx->mlx_ptr, path, &texture_img->width, &texture_img->height);
//     if (!texture_img->img) {
//         perror("Error: Failed to load texture image.\n");
//         exit(1);
//     }
//     texture_img->addr = (int *)mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel, &texture_img->line_length, &texture_img->endian);
// 	 if (texture_img->addr == NULL) {
// 		perror("Failed to get image data address\n");
//         mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
// 		perror("Failed to get image data address in init_texture_img\n");
//         return ;
//     }
//     // texture_img->relative_path = NULL;
// }

// void init_textures(t_texture *texture, t_mlx *mlx) 
// {
// 	init_texture_img(&texture->NO, mlx->mlx_ptr, "./assets/north.xpm");
// 	init_texture_img(&texture->SO, mlx->mlx_ptr, "./assets/north.xpm");
// 	init_texture_img(&texture->WE, mlx->mlx_ptr, "./assets/north.xpm");
// 	init_texture_img(&texture->EA, mlx->mlx_ptr, "./assets/north.xpm");
// 	// init_texture(&texture->floor, mlx, "./assets/floor.xpm", "./assets/north.xpm");
//     // init_texture(&texture->ceiling, mlx, "./assets/ceiling.xpm", "./assets/north.xpm");

//     return ;
// }

// void init_texture(t_texture *texture, t_mlx *mlx) {
//     // texture->texture_found = 0;
//     // texture->size = 0;
//     // texture->road = NULL;
//     // texture->NO = NULL;
//     // texture->SO = NULL;
//     // texture->WE = NULL;
//     // texture->EA = NULL;
//     // texture->xpm_data = NULL;
//     init_tex_image(&texture->NO, mlx->mlx_ptr);
//     init_tex_image(&texture->SO, mlx->mlx_ptr);
//     init_tex_image(&texture->WE, mlx->mlx_ptr);
//     init_tex_image(&texture->EA, mlx->mlx_ptr);
//     init_tex_image(&texture->floor, mlx->mlx_ptr);
//     init_tex_image(&texture->ceiling, mlx->mlx_ptr);
// }

// void init_texture(t_texture *texture, t_mlx *mlx) {
//     texture->texture_found = 0;
//     texture->size = 0;
//     texture->road = NULL;
//     init_tex_image(&texture->NO, mlx);
//     init_tex_image(&texture->SO, mlx);
//     init_tex_image(&texture->WE, mlx);
//     init_tex_image(&texture->EA, mlx);
//     init_tex_image(&texture->floor, mlx);
//     init_tex_image(&texture->ceiling, mlx);
// }

// void init_texture_img(t_image *texture_img, t_mlx *mlx, const char *path) {
//     texture_img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, (char *)path, &texture_img->width, &texture_img->height);
//     if (!texture_img->img) {
//         fprintf(stderr, "Error: Failed to load texture image from %s\n", path);
//         exit(1);
//     }
//     texture_img->addr = mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel, &texture_img->line_length, &texture_img->endian);
//     if (!texture_img->addr) {
//         fprintf(stderr, "Failed to get image data address for %s\n", path);
//         mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
//         exit(1);
//     }
// }

// void init_textures(t_texture *texture, t_mlx *mlx) {
//     init_texture_img(&texture->NO, mlx, "./assets/north.xpm");
//     init_texture_img(&texture->SO, mlx, "./assets/south.xpm");
//     init_texture_img(&texture->WE, mlx, "./assets/west.xpm");
//     init_texture_img(&texture->EA, mlx, "./assets/east.xpm");
//     // init_texture_img(&texture->floor, mlx, "./assets/floor.xpm");
//     // init_texture_img(&texture->ceiling, mlx, "./assets/ceiling.xpm");
// }

// t_texture *allocate_texture(void)
// {
// 	t_texture *texture; 

// 	texture = malloc(sizeof(t_texture));
//     if (texture == NULL) {
//         perror("Allocation for texture failed\n");
//         exit(EXIT_FAILURE);
//     }
// 	texture->texture_found = 0;
// 	texture->size = 0;
// 	texture->road = NULL;
// 	texture->NO = allocate_image();
// 	texture->SO = allocate_image();
// 	texture->WE = allocate_image();
// 	texture->EA = allocate_image();
// 	texture->floor = allocate_image();
// 	texture->ceiling = allocate_image();

// 	return texture;
// }

void init_image(t_image *img) {
    img->width = 0;
    img->height = 0;
    img->img = NULL;
    img->addr = NULL;
    img->bits_per_pixel = 0;
    img->line_length = 0;
    img->endian = 0;
    img->relative_path = NULL;
}

void init_texture(t_texture *texture) {
    texture->texture_found = 0;
    texture->size = 0;
    texture->road = NULL;
    init_image(&texture->NO);
    init_image(&texture->SO);
    init_image(&texture->WE);
    init_image(&texture->EA);
    init_image(&texture->floor);
    init_image(&texture->ceiling);
}

void init_texture_img(t_image *texture_img, t_mlx *mlx, const char *path) {
    texture_img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, (char *)path, &texture_img->width, &texture_img->height);
    if (!texture_img->img) {
        fprintf(stderr, "Error: Failed to load texture image from %s\n", path);
        exit(1);
    }
    texture_img->addr = mlx_get_data_addr(texture_img->img, &texture_img->bits_per_pixel,
										&texture_img->line_length, &texture_img->endian);
    if (!texture_img->addr) {
        fprintf(stderr, "Failed to get image data address for %s\n", path);
        mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
        exit(1);
    }
}

void init_textures(t_texture *texture, t_mlx *mlx) {
    init_texture_img(&texture->NO, mlx, "./assets/north.xpm");
    init_texture_img(&texture->SO, mlx, "./assets/south.xpm");
    init_texture_img(&texture->WE, mlx, "./assets/west.xpm");
    init_texture_img(&texture->EA, mlx, "./assets/east.xpm");
    // init_texture_img(&texture->floor, mlx, "./assets/floor.xpm");
    // init_texture_img(&texture->ceiling, mlx, "./assets/ceiling.xpm");
}
