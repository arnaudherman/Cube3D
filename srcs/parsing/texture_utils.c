#include "cub3d.h"

char	*get_texture_path(char *line)
{
	char	*path_start;
	char	*path;
	char	*newline;

	path_start = ft_strchr(line, ' ');
	path_start++;
	path = (char *)malloc(strlen(path_start) + 1);
	if (path == NULL)
		return (NULL);
	ft_strcpy(path, path_start);
	newline = ft_strchr(path, '\n');
	if (newline != NULL)
		*newline = '\0';
	return (path);
}

void	process_texture_path(t_image *texture, char *path, t_mlx *mlx)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		texture->road = path;
		init_texture_img(texture, mlx, path);
	}
	else
	{
		ft_error(ERROR_PATH_TEXT);
		free(path);
	}
}

void	save_texture_data(t_image *texture, char *line, t_mlx *mlx)
{
	char	*path;

	if (texture->texture_found == 0)
	{
		path = get_texture_path(line);
		if (path != NULL)
		{
			process_texture_path(texture, path, mlx);
		}
	}
	else
	{
		ft_error(ERROR_DOUBLE_TEXT);
	}
	texture->texture_found += 1;
}
