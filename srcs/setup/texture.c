#include "cub3d.h"

// Use mlx function for xpm format for no leak
void	init_texture_img(t_image *texture_img, t_mlx *mlx, char *path)
{
	texture_img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&texture_img->width, &texture_img->height);
	if (!texture_img->img)
	{
		perror("Error: Failed to load texture image.\n");
		exit(EXIT_FAILURE);
	}
	texture_img->addr = (int *)mlx_get_data_addr(texture_img->img,
			&texture_img->bits_per_pixel, &texture_img->line_length,
			&texture_img->endian);
	if (texture_img->addr == NULL)
	{
		perror("Failed to get image data address\n");
		mlx_destroy_image(mlx->mlx_ptr, texture_img->img);
		perror("Failed to get image data address in init_texture_img\n");
		exit(EXIT_FAILURE);
	}
}

int	get_pixel_color(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

//  
void	set_texture_on_image(t_data *data, t_image *texture, t_ray *ray)
{
	// int		x_texture_pos;
	int		y_texture_pos;
	int		y;
	float	relative_height;
	int		color;


	ray->y = ray->draw_start;
	// position the ray hit the wall in the tile
	// ray->wall_x = ray->side ? data->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x
	
	// ray->wall_x = (data->player->x_pos + ray->ray_length
	// 			* cos(ray->ray_angle)) / 50;
	// ray->wall_x -= floor(ray->wall_x);
	// ray->tex_x = (int)((ray->wall_x) * (double)ray->texture.size.x);
	// x_texture_pos = ray->x_text;

	y = ray->draw_start;
	// 	y < ray->draw_end);
	while (y < ray->draw_end)
	{
		relative_height = (WINDOW_HEIGHT / ray->line_height);
		y_texture_pos = (y - ray->draw_start) * relative_height
			* texture->height / WINDOW_HEIGHT;
		color = get_pixel_color(texture, ray->x_text, y_texture_pos);
		my_mlx_pixel_put(data->world, ray->x, y, color);
		y++;
	}
}
