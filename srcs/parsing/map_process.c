/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:19 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:48:20 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_start_end_wrapper(t_data *data, int i)
{
	if (i < data->map.y_map)
	{
		check_start_end(data->map.map2d[i]);
		check_start_end_wrapper(data, i + 1);
	}
}

void	check_down_wrapper(t_data *data, int i)
{
	if (i < data->map.y_map - 1)
	{
		check_down(data->map.map2d[i], data->map.map2d[i + 1]);
		check_down_wrapper(data, i + 1);
	}
}

void	check_zero_wrapper(t_data *data, int i)
{
	if (i < data->map.y_map - 1)
	{
		check_zero(data->map.map2d[i], data->map.map2d[i + 1]);
		check_zero_wrapper(data, i + 1);
	}
}

void	process_map(t_data *data)
{
	remove_newline(data->map.map2d);
	complet_string_with_space(data->map.map2d, data->map.x_map);
	check_start_end_wrapper(data, 0);
	only_space_or_one(data->map.map2d[0]);
	only_space_or_one(data->map.map2d[data->map.y_map - 1]);
	check_upper(data->map.map2d[0], data->map.map2d[1]);
	check_down_wrapper(data, 1);
	check_zero_wrapper(data, 1);
}
