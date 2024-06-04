

#include "../../include/cub3d.h"

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
		if(*ptr == 'N' || *ptr == 'S'
			|| *ptr == 'W' || *ptr == 'E')
			data->f_spawn++;
		ptr++;
	}
	len = ft_strlen(line);
	if (len > data->map_x)
		data->map_x = len;
	return (0);
}

int	process_line(char *line, t_data *data)
{
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, "\n"); // Allocation mémoire ici
	if (check_auth_char(trimmed_line, data)) // Utilisation de trimmed_line
	{
		free(trimmed_line); // Libération de la mémoire uniquement en cas d'échec
		ft_error("char bizarre found");
		return (1);
	}
	data->map_y++;
	return (0);
}

//débarrasse tout caractère d'espacement inutile au début
//utile pour plus tard
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

// L'objectif général du code est de lire le fichier .cub
// Ce fichier contient les informations suiventes
// les chemins vers des textures (NO, SO, WE, EA) qui sont dans assests,
// les couleurs du plafond (F) et du sol (C) et
// une représentation de la carte elle-même.
void	len_map(char *file_d, t_data *data)
{
	char	*line;
	char	*next_line;
	int		fd;

	fd = open(file_d, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	data->f_spawn = 0;
	line = ignore_texture(fd);
	free(line);
	data->map_y = 1;
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		line = next_line;
		if (process_line(line, data) == 1)
		{
			free(line);
			close(fd);
			ft_error(ERROR_MAP);
		}
		if(line[0] == '\n')
			ft_error(ERROR_BACK_AFTER_MAP);
		free(line);
		next_line = get_next_line(fd);
	}
	close(fd);
	if (data->f_spawn != 1)
		ft_error(ERROR_MAP_SPAWN);
	return ;
}
