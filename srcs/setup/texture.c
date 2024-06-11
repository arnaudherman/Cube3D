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

//  texture->width / data->map2d->tile_size * (ray->x % data->map2d->tile_size); // THIS HAS PROBLEM
void	set_texture_on_image(t_data *data, t_image *texture, t_ray *ray)
{
	int		x_texture_pos;
	int		y_texture_pos;
	int		y;
	float	relative_height;
	int		color;

	ray->y = ray->draw_start;
	x_texture_pos = (ray->wall_x - floor(ray->wall_x)) * texture->width;
	printf("x_texture_pos : %d   ++ ray->x %d\n", x_texture_pos, ray->x);
	y = ray->draw_start;
	printf("y, ray->draw_end : %d, %d %d\n", y, ray->draw_end,
		y < ray->draw_end);
	while (y < ray->draw_end)
	{
		relative_height = (WINDOW_HEIGHT / ray->line_height);
		y_texture_pos = (y - ray->draw_start) * relative_height
			* texture->height / WINDOW_HEIGHT;
		if (y % 100 == 0)
		{
			printf("y_texture_pos : %d\t\t texture->height %d\n",
				y_texture_pos, texture->height);
			printf("ray->draw_end %d, ray->draw_start %d\n",
				ray->draw_end, ray->draw_start);
			printf("y %d\n", y);
		}
		color = get_pixel_color(texture, x_texture_pos, y_texture_pos);
		my_mlx_pixel_put(data->world, ray->x, y, color);
		y++;
	}
}
