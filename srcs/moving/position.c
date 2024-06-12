/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:11 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:47:12 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->x_map || y >= map->y_map)
		return (true);
	return (map->map2d[y][x] == '1');
}

bool	player_wall_collision(t_map *map, int tile_size, double x, double y)
{
	int	x_tile_left;
	int	x_tile_right;
	int	y_tile_top;
	int	y_tile_bottom;

	x_tile_left = (int)((x - 24 / 2) / tile_size);
	x_tile_right = (int)((x + 24 / 2) / tile_size);
	y_tile_top = (int)((y - 24 / 2) / tile_size);
	y_tile_bottom = (int)((y + 24 / 2) / tile_size);
	if (is_wall(map, x_tile_left, (int)(y / tile_size)) ||
		is_wall(map, x_tile_right, (int)(y / tile_size)) ||
		is_wall(map, (int)(x / tile_size), y_tile_top) ||
		is_wall(map, (int)(x / tile_size), y_tile_bottom))
	{
		return (true);
	}
	return (false);
}
