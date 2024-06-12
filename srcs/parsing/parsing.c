/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:48 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:53:50 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_file(char *fname, char *name)
{
	int		fd;
	char	*s1;

	s1 = ft_strrchr(fname, '.');
	if (!s1 || ft_strcmp(s1, name) != 0)
		ft_error(ERROR_MAP_EXT);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	close(fd);
}

void	hoockgps(t_data *data)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = data->map.map2d;
	while (ptr[j] != NULL)
	{
		i = 0;
		while (ptr[j][i] != '\0')
		{
			if (ptr[j][i] == 'N' || ptr[j][i] == 'S'
			|| ptr[j][i] == 'W' || ptr[j][i] == 'E')
			{
				data->player->x_pos = i * (320 / data->map.y_map);
				data->player->y_pos = j * (320 / data->map.x_map);
				data->player->direction = ptr[j][i];
			}
			i++;
		}
		j++;
	}
}

int	parsing(char *fname, t_data *data)
{
	ft_check_file(fname, ".cub");
	len_map(fname, data);
	found_textures_data(fname, data, &data->mlx);
	color_data(fname, data);
	check_map(fname, data);
	hoockgps(data);
	return (0);
}
