/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:17 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:49:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_ray_coordinates(t_ray *ray)
{
	if (ray->sx < ray->sy)
	{
		ray->sx += ray->dx;
		ray->x_map += ray->x_step;
		if (ray->x_step == -1)
			ray->side = 0;
		else
			ray->side = 1;
	}
	else
	{
		ray->sy += ray->dy;
		ray->y_map += ray->y_step;
		if (ray->y_step == -1)
			ray->side = 2;
		else
			ray->side = 3;
	}
}

void	check_wall_hit(t_data *data, t_map *map, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = ray->x_map / data->map2d->tile_size;
	map_y = ray->y_map / data->map2d->tile_size;
	if (map->map2d[map_y][map_x] == '1')
		ray->hit = 1;
	else if (ray->x % 50 == 0)
		my_mlx_pixel_put(data->map2d, ray->x_map, ray->y_map, 0xffe7a0);
}

void	check_coordinates(t_data *data, t_map *map, t_ray *ray)
{
	if (ray->x_map >= 0 && ray->x_map < map->x_map
		* data->map2d->tile_size && ray->y_map >= 0
		&& ray->y_map < map->y_map * data->map2d->tile_size)
	{
		check_wall_hit(data, map, ray);
	}
	else
	{
		printf("map->x_map = %d, map->y_map = %d\n", map->x_map, map->y_map);
		printf("ray->y_map = %d, ray->x_map = %d\n", ray->y_map, ray->x_map);
		printf("map->map2d[ray->y_map][ray->x_map] = %d\n",
			map->map2d[ray->y_map / data->map2d->tile_size][ray->x_map
			/ data->map2d->tile_size]);
		exit(1);
	}
}

void	dda(t_data *data, t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		update_ray_coordinates(ray);
		check_coordinates(data, map, ray);
	}
}
