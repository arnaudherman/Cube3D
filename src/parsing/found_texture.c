

#include "../../include/cub3d.h"

void	process_texture_line(char *line, t_data *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		save_texture_data(&data->no, line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		save_texture_data(&data->so, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		save_texture_data(&data->we, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		save_texture_data(&data->ea, line);
}

void	check_missing_textures(t_data *data)
{
	if ((data->no.texture_found == 0) || (data->so.texture_found == 0)
		|| (data->we.texture_found == 0) || (data->ea.texture_found == 0))
	{
		ft_error(ERROR_MISSING_TEXT);
	}
}

void	read_texture_file(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0)
		{
			process_texture_line(line, data);
		}
		free(line);
	}
}

void	found_textures_data(char *fname, t_data *data)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	read_texture_file(fd, data);
	close(fd);
	check_missing_textures(data);
}
