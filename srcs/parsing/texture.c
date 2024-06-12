/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 16:20:45 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_texture_line(char *line, t_data *data, t_mlx *mlx)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		save_texture_data(&data->no, line, mlx);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		save_texture_data(&data->so, line, mlx);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		save_texture_data(&data->we, line, mlx);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		save_texture_data(&data->ea, line, mlx);
}

void	check_missing_textures(t_data *data)
{
	if (data->no.texture_found == 0 || data->so.texture_found == 0
		|| data->we.texture_found == 0 || data->ea.texture_found == 0)
	{
		ft_error(ERROR_MISSING_TEXT);
	}
}

void	found_textures_data(char *fname, t_data *data, t_mlx *mlx)
{
	int		fd;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	line = get_next_line(fd);
	while (line != NULL)
	{
		handle_texture_line(line, data, mlx);
		line = get_next_line(fd);
	}
	close(fd);
	check_missing_textures(data);
}
