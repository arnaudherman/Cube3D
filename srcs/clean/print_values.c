/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:30 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:38 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("Map:\n");
	printf("  f_spawn: %d\n", map->f_spawn);
	printf("  w_map: %d\n", map->w_map);
	printf("  h_map: %d\n", map->h_map);
	printf("  x_map: %d\n", map->x_map);
	printf("  y_map: %d\n", map->y_map);
	printf("  color: %u\n", map->color);
	if (map->map2d != NULL)
	{
		printf("  map2d:\n");
		while (i < map->h_map)
		{
			if (map->map2d[i] != NULL)
				printf("    row %d: %s\n", i, map->map2d[i]);
			else
				printf("    row %d: NULL\n", i);
			i++;
		}
	}
	else
		printf("  map2d is NULL\n");
}

void	print_ray_info(t_ray *ray)
{
	printf("Ray Info:\n");
	printf("x: %d\n", ray->x);
	printf("y: %d\n", ray->y);
	printf("x_map: %d\n", ray->x_map);
	printf("y_map: %d\n", ray->y_map);
	printf("x_step: %d\n", ray->x_step);
	printf("y_step: %d\n", ray->y_step);
	printf("hit: %d\n", ray->hit);
	printf("side: %d\n", ray->side);
	printf("line_height: %d\n", ray->line_height);
	printf("draw_start: %d\n", ray->draw_start);
	printf("draw_end: %d\n", ray->draw_end);
	printf("x_text: %d\n", ray->x_text);
	printf("y_text: %d\n", ray->y_text);
	printf("wall_x: %f\n", ray->wall_x);
	printf("z_index: %p\n", (void *)ray->z_index);
	printf("camera_x: %f\n", ray->camera_x);
	printf("wall_dist: %f\n", ray->wall_dist);
	printf("dir_x: %f\n", ray->dir_x);
	printf("dir_y: %f\n", ray->dir_y);
	printf("sx: %f\n", ray->sx);
	printf("sy: %f\n", ray->sy);
	printf("dx: %f\n", ray->dx);
	printf("dy: %f\n", ray->dy);
}

void	print_ray_texture_info(t_data *data, t_ray *ray, t_image *texture)
{
	int	data_index;
	int	texture_index;

	printf("Ray Coordinates: x = %d, y = %d\n", ray->x, ray->y);
	printf("Texture Coordinates: x_text = %d, y_text = %d\n",
		ray->x_text, ray->y_text);
	printf("Data Image Line Length: %d\n", data->image->line_length);
	printf("Data Image Bits Per Pixel: %d\n", data->image->bits_per_pixel);
	printf("Texture Line Length: %d\n", texture->line_length);
	printf("Texture Bits Per Pixel: %d\n", texture->bits_per_pixel);
	data_index = ray->y * data->image->line_length + ray->x
		* data->image->bits_per_pixel / 8;
	texture_index = ray->y_text * texture->line_length + ray->x_text
		* (texture->bits_per_pixel / 8);
	printf("Data Index: %d\n", data_index);
	printf("Texture Index: %d\n", texture_index);
}

void	print_image_info(t_image *image)
{
	if (image == NULL)
	{
		printf("Image structure is NULL\n");
		return ;
	}
	printf("Image Info:\n");
	printf("  Width: %d\n", image->width);
	printf("  Height: %d\n", image->height);
	printf("  Bits per pixel: %d\n", image->bits_per_pixel);
	printf("  Line length: %d\n", image->line_length);
	printf("  Endian: %d\n", image->endian);
	printf("  Img pointer: %p\n", image->img);
	printf("  DATA Addr: %p\n", image->addr);
	printf("  Road: %s\n", image->road);
	printf("  Texture found: %d\n", image->texture_found);
}
