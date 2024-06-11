#include "cub3d.h"

void	handle_texture_line(char *line, t_data *data, t_mlx *mlx)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		save_texture_data(&data->NO, line, mlx);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		save_texture_data(&data->SO, line, mlx);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		save_texture_data(&data->WE, line, mlx);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		save_texture_data(&data->EA, line, mlx);
}

void	check_missing_textures(t_data *data)
{
	if (data->NO.texture_found == 0 || data->SO.texture_found == 0
		|| data->WE.texture_found == 0 || data->EA.texture_found == 0)
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
