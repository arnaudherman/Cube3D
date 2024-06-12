/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:02 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:04 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h_map)
	{
		free(map->map2d[i]);
		i++;
	}
	free(map->map2d);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_if_malloc_failed(t_data *data)
{
	free(data->map2d);
	free(data->world);
	free(data->player);
	free(data->keys);
	free(data->image);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->map2d);
	free(data->world);
	free(data->player);
	free(data->keys);
	free(data->ray);
	while (i < data->map.h_map)
	{
		free(data->map.map2d[i]);
		i++;
	}
	free(data->map.map2d);
}
