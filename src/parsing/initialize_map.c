/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:26:03 by aherman           #+#    #+#             */
/*   Updated: 2024/03/11 14:29:09 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initialize_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(data->map_y * sizeof(char *));
	if (!data->map)
		fail("Error when allocating map memory");
	while (i < data->map_y)
	{
		data->map[i] = ft_calloc(data->map_x, sizeof(char));
		i++;
	}
}

void	fill_validate_and_close_map(char *file_d, t_data *data, int fd)
{
	if (fill_map(file_d, data) != 0)
		fail("Error filling the map");
	if (check_walls(data) != 0)
		fail("Error not enough walls in map");
	if (data->pos_x == 0 || data->pos_y == 0)
		fail("No start position found");
	close(fd);
}

int	fill_map(char *in_file, t_data *data)
{
	int	fd;
	int	y;

	fd = init_and_open(in_file, data);
	process_lines(fd, data, &y);
	validate_and_close(fd, data, y);
	return (0);
}

int	init_and_open(char *in_file, t_data *data)
{
	int	fd;

	fd = open(in_file, O_RDONLY);
	if (fd < 0)
		fail("fail open (init_and_open)");
	if (!data->map)
		fail("malloc error (init_and_open)");
	return (fd);
}

void	process_lines(int fd, t_data *data, int *y)
{
	char	*line;
	char	*tmp;

	*y = 0;
	line = ignore_texture(fd);
	if (!line)
	{
		free(line);
		fail("No map found");
	}
	while (*y < data->map_y && line != NULL)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		if (!line)
			fail("Error strtrim (process_lines)");
		if (ft_strlen(line) < (size_t)data->map_x)
			line = fill_with_space(line, data);
		free(tmp);
		free(data->map[*y]);
		data->map[*y] = line;
		(*y)++;
		if (*y < data->map_y)
			line = get_next_line(fd);
	}
}

char	*fill_with_space(char *line, t_data *data)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(line);
	while (len < (size_t)data->map_x)
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		if (!line)
			fail("Error strjoin set_space");
		free(tmp);
		len++;
	}
	return (line);
}

void	validate_and_close(int fd, t_data *data, int y)
{
	close(fd);
	if (y != data->map_y)
		fail("Map size does not match expected dimensions");
}

int	check_walls(t_data *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->player_orientation = NORTH;
	check_player_positions(data);
	if (cross_check(data) == -1)
	{
		fail("Not enough walls (cross_check)");
		return (-1);
	}
	return (0);
}

void	check_player_positions(t_data *data)
{
	int		x;
	int		y;
	char	i_char;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			i_char = data->map[y][x];
			if (i_char == 'N' || i_char == 'S'
				|| i_char == 'W' || i_char == 'E')
				player_pos(x, y, data);
			x++;
		}
		y++;
	}
}

int	player_pos(int x, int y, t_data *data)
{
	if (data->pos_x != 0 || data->pos_y != 0)
		fail("Multiple start position for player");
	data->pos_x = x;
	data->pos_y = y;
	data->player_orientation = data->map[y][x];
	data->map[y][x] = '0';
	return (0);
}

int	cross_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map[y][x] == '0')
			{
				if (y == 0 || y == data->map_y - 1
					|| x == 0 || x == data->map_x - 1
					|| data->map[y][x - 1] == ' '
					|| data->map[y][x + 1] == ' '
					|| data->map[y - 1][x] == ' '
					|| data->map[y + 1][x] == ' ')
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
