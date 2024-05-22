

#include "../../include/cub3d.h"

void	extract_path(char *line, char **path)
{
	char	*path_start;
	char	*newline;

	path_start = ft_strchr(line, ' ');
	path_start++;
	*path = (char *)malloc(strlen(path_start) + 1);
	if (*path == NULL)
		return ;
	ft_strcpy(*path, path_start);
	newline = ft_strchr(*path, '\n');
	if (newline != NULL)
		*newline = '\0';
}

int	verify_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void	save_texture_data(t_texture_info *texture, char *line)
{
	char	*path;

	if (texture->texture_found == 0)
	{
		extract_path(line, &path);
		if (path == NULL)
			return ;
		if (verify_texture_path(path))
		{
			texture->road = path;
		}
		else
		{
			ft_error(ERROR_PATH_TEXT);
			free(path);
		}
	}
	else
	{
		ft_error(ERROR_DOUBLE_TEXT);
	}
	texture->texture_found += 1;
}
