

#include "../../include/cub3d.h"

void	for_line_len(char *line, int fd)
{
	free(line);
	close(fd);
	ft_error(ERROR_MAP);
}

void	handle_error_on_open(int fd)
{
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
}

void	process_map_lines(int fd, t_data *data)
{
	char	*line;
	char	*next_line;

	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		line = next_line;
		if (process_line(line, data) == 1)
			for_line_len(line, fd);
		if (line[0] == '\n')
			ft_error(ERROR_BACK_AFTER_MAP);
		free(line);
		next_line = get_next_line(fd);
	}
}

void	check_spawn(t_data *data)
{
	if (data->f_spawn != 1)
		ft_error(ERROR_MAP_SPAWN);
}

void	len_map(char *file_d, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file_d, O_RDONLY);
	handle_error_on_open(fd);
	data->f_spawn = 0;
	line = ignore_texture(fd);
	free(line);
	data->map_y = 1;
	process_map_lines(fd, data);
	close(fd);
	check_spawn(data);
}
