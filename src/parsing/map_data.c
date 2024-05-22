

#include "../../include/cub3d.h"

void	allocate_memory(t_data *data, int fd_cub)
{
	data->map = malloc(sizeof(char *) * (data->map_y + 1));
	if (!data->map)
	{
		ft_error("Memory allocation failed");
		close(fd_cub);
		exit(EXIT_FAILURE);
	}
}

void	read_map_lines(t_data *data, int fd_cub)
{
	int		i;
	char	*line;

	i = 0;
	line = ignore_texture(fd_cub);
	while (line && i < data->map_y)
	{
		data->map[i] = strdup(line);
		if (!data->map[i])
		{
			ft_error("Memory allocation failed");
			close(fd_cub);
			exit(EXIT_FAILURE);
		}
		i++;
		if (i < data->map_y)
			line = get_next_line(fd_cub);
	}
}

void	read_map_data(int fd_cub, t_data *data)
{
	allocate_memory(data, fd_cub);
	read_map_lines(data, fd_cub);
	close(fd_cub);
}
