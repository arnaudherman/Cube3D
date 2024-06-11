#include "cub3d.h"

// get_pixel_color
// int get_pixel_color(t_image *img, int x, int y)
// {
// 	char *dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

// void draw_sprite_image(t_image *texture_img, t_image *surface_img, int x, int y)
// {
// 	int i;
// 	int j;
// 	int color;

// 	i = 0;
// 	while (i < texture_img->width)
// 	{
// 		j = 0;
// 		while (j < texture_img->height)
// 		{
// 			color = get_pixel_color(texture_img, i, j);
// 			if (color != 0)
// 				my_mlx_pixel_put(surface_img, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }



void	set_wall(t_data *data, t_ray *ray)
{
	int		text_x;
	t_image	*texture_img;

	// TO DO : DEBUG ALL IMAGES VALUES LOOKING GOOD
	texture_img = &data->WE;
	// write(1, "WE TEST :\n", 11); // DEBUG
	// print_image_info(texture_img); // DEBUG
	if (ray->side == 1)
	{
		texture_img = &data->EA;
		// write(1, "EA TEST :\n", 11); // DEBUG
		// print_image_info(texture_img); // DEBUG
	}
	else if (ray->side == 2)
	{
		texture_img = &data->NO;
		// write(1, "NO TEST : \n", 11); // DEBUG
		// print_image_info(texture_img); // DEBUG
	}
	else if (ray->side == 3)
	{
		texture_img = &data->SO;
		// write(1, "SO TEST : \n", 11); // DEBUG
		// print_image_info(texture_img); // DEBUG
	}

	text_x = (int)(ray->wall_x * (double)texture_img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		text_x = texture_img->width - text_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		text_x = texture_img->width - text_x - 1;
	ray->x_text = text_x;
	// set_texture_image_road(texture_img, ray);
	// print_image_info(texture_img); // DEBUG
	// exit(1); // DEBUG
	set_texture_on_image(data, texture_img, ray);
	// draw_sprite_image(texture_img, data->world, 1000, 100);
}



void	draw_col(t_data *data, t_mlx *mlx, t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + mlx->win_height / 2;
	ray->draw_end = ray->line_height / 2 + mlx->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= mlx->win_height)
		ray->draw_end = mlx->win_height - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wall_x = data->player->y_pos +
			ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player->x_pos +
			ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	set_wall(data, ray);
	// set_color_on_image(data, ray);
}


// WORKING DO NOT TOUCH
// void draw_col(t_data *data, t_mlx *mlx, t_ray *ray)
// {
//     int y;
//     int color;

//     y = ray->draw_start;
//     while (y < ray->draw_end)
//     {
//         if (ray->side == 0)
//             color = 0x420f2a;
//         else if (ray->side == 1)
//             color = 0x79563D;
//         else if (ray->side == 2)
//             color = 0x906c7b;
//         else if (ray->side == 3)
//             color = 0xc1ac91;
//         my_mlx_pixel_put(data->world, ray->x, y, color);
//         y++;
//     }
// }
