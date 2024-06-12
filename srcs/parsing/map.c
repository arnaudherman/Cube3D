/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:39 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:48:40 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_map_lines(int fd_cub, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = ignore_texture(fd_cub);
	while (line && i < data->map.y_map)
	{
		data->map.map2d[i] = malloc(strlen(line) + 1);
		if (!data->map.map2d[i])
		{
			ft_error("Memory allocation failed");
			return (NULL);
		}
		strcpy(data->map.map2d[i], line);
		i++;
		if (i < data->map.y_map)
			line = get_next_line(fd_cub);
	}
	data->map.map2d[i] = (NULL);
	return (1);
}

int	allocate_map_memory(t_data *data)
{
	data->map.map2d = malloc(sizeof (char *) * (data->map.y_map + 1));
	if (!data->map.map2d)
	{
		ft_error("Memory allocation failed");
		return (0);
	}
	return (1);
}

void	check_map(char *fname, t_data *data)
{
	int	fd_cub;

	fd_cub = open(fname, O_RDONLY);
	if (fd_cub < 0)
	{
		ft_error("Error opening file");
		return ;
	}
	if (!allocate_map_memory(data))
	{
		close(fd_cub);
		return ;
	}
	if (!read_map_lines(fd_cub, data))
	{
		close(fd_cub);
		return ;
	}
	close(fd_cub);
	process_map(data);
}
