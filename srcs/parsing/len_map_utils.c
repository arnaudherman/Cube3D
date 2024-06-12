/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:38 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:47:44 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_auth_char(char *line, t_data *data)
{
	char	*ptr;
	int		len;

	ptr = line;
	while (line && *ptr)
	{
		if (!(*ptr == '0' || *ptr == '1' || *ptr == 'N' || *ptr == 'S'
				|| *ptr == 'W' || *ptr == 'E' || *ptr == ' ' || *ptr == '\t'))
		{
			printf("ERROR : %c\n", *ptr);
			return (1);
		}
		if (*ptr == 'N' || *ptr == 'S'
			|| *ptr == 'W' || *ptr == 'E')
			data->map.f_spawn++;
		ptr++;
	}
	len = ft_strlen(line);
	if (len > data->map.x_map)
		data->map.x_map = len;
	return (0);
}

int	process_line(char *line, t_data *data)
{
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, "\n");
	if (check_auth_char(trimmed_line, data))
	{
		free(trimmed_line);
		ft_error("char bizarre found");
		return (1);
	}
	data->map.y_map++;
	return (0);
}

char	*read_and_filter_line(int fd_cub, char **ptr)
{
	char	*line;

	line = get_next_line(fd_cub);
	if (!line)
		ft_error(ERROR_MAP_LTEX);
	*ptr = line;
	while (**ptr == ' ' || **ptr == '\t')
		(*ptr)++;
	return (line);
}

char	*ignore_texture(int fd_cub)
{
	char	*line;
	char	*ptr;

	while (1)
	{
		line = read_and_filter_line(fd_cub, &ptr);
		if (ft_strncmp(ptr, "NO ", 3) == 0 || ft_strncmp(ptr, "SO ", 3) == 0
			|| ft_strncmp(ptr, "WE ", 3) == 0 || ft_strncmp(ptr, "EA ", 3) == 0
			|| ft_strncmp(ptr, "F ", 2) == 0 || ft_strncmp(ptr, "C ", 2) == 0)
		{
			free(line);
			continue ;
		}
		if (!(*ptr == '0' || *ptr == '1' || *ptr == 'N' || *ptr == 'S'
				|| *ptr == 'W' || *ptr == 'E'))
		{
			free(line);
			continue ;
		}
		return (line);
	}
}
