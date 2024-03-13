/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:48:53 by aherman           #+#    #+#             */
/*   Updated: 2024/03/11 14:46:25 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//check si le fichier map est en cub et que le fichier peut etre open et renvoie le fd
int	ft_check_file(char *fname, char *name)
{
	int		fd;
	char	*s1;

	s1 = ft_strrchr(fname, '.');
	if (s1 && !ft_strcmp(s1, name))
		ft_error(ERROR_MAP_EXT);
	else if (!fname || !s1)
		return (0);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	return (fd);
}

void	process_textures_and_colors(char *file_d, t_data *data)
{
	len_map(file_d, data);
	if (parse_textures(file_d, data) != 0)
		fail("error parse_textures");
	convert_colors(data);
	free(data->colors.f_color);
	free(data->colors.c_color);
}

//main du parsing
int	parsing(char *argv[], t_data *data)
{
	data->fd = ft_check_file(argv[1], ".cub");
	process_textures_and_colors(argv[1], data);
	initialize_map(data);
	fill_validate_and_close_map(argv[1], data, data->fd);
	return (0);
}
