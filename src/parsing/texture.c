// #include "../../include/cub3d.h"

// void	save_texture_data(t_texture *texture, char *line)
// {
// 	char	*path;
// 	char	*path_start;
// 	char	*newline;
// 	int		fd;

// 	if (texture->texture_found == 0)
// 	{
// 		path_start = ft_strchr(line, ' ');
// 		path_start++;
// 		path = (char *)malloc(strlen(path_start) + 1);
// 		if (path == NULL)
// 			return ;
// 		ft_strcpy(path, path_start);
// 		newline = ft_strchr(path, '\n');
// 		if (newline != NULL)
// 			*newline = '\0';
// 		fd = open(path, O_RDONLY);
// 		if (fd != -1)
// 		{
// 			close(fd);
// 			texture->road = path;
// 		}
// 		else
// 		{
// 			ft_error(ERROR_PATH_TEXT);
// 			free(path);
// 		}
// 	}
// 	else
// 		ft_error(ERROR_DOUBLE_TEXT);
// }

// // L'objectif est de mettre les textures dans nos struct
// // On trouve une ligne qui start avec une direction
// // On regarde que cette direction na pas deja une texture set
// // On envoie dans save data, on extrait la path
// // On regarde si le fichier peut etre open
// // On stock dans la struct
// void	found_textures_data(t_data *data)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = get_next_line(data->fd);
// 		if (line == NULL)
// 			break ;
// 		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
// 			|| ft_strncmp(line, "WE ", 3) == 0
// 			|| ft_strncmp(line, "EA ", 3) == 0)
// 		{
// 			if (ft_strncmp(line, "NO ", 3) == 0)
// 				save_texture_data(&(data->texture.NO), line);
// 			else if (ft_strncmp(line, "SO ", 3) == 0)
// 				save_texture_data(&(data->texture.SO), line);
// 			else if (ft_strncmp(line, "WE ", 3) == 0)
// 				save_texture_data(&(data->texture.WE), line);
// 			else if (ft_strncmp(line, "EA ", 3) == 0)
// 				save_texture_data(&(data->texture.EA), line);
// 		}
// 	}
// 	if ((data->texture.NO == NULL) || (data->texture.SO == NULL)
// 		|| (data->texture.WE == NULL) || (data->texture.EA == NULL))
// 		ft_error(ERROR_MISSING_TEXT);
// }