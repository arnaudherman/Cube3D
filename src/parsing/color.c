

#include "../../include/cub3d.h"

int	encode_rgb(int r, int g, int b)
{
	int	color;

	color = 0;
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	save_color_data(t_color_info *color, char *line)
{
	char	*path;
	char	*path_start;
	char	*newline;

	if (color->found_color == 0)
	{
		path_start = ft_strchr(line, ' ');
		path_start++;
		path = (char *)malloc(strlen(path_start) + 1);
		if (path == NULL)
			return ;
		ft_strcpy(path, path_start);
		newline = ft_strchr(path, '\n');
		if (newline != NULL)
			*newline = '\0';
		color->string_color = path;
		color->found_color = 1;
	}
	else
		ft_error(ERROR_DOUBLE_COLOR);
}

void	found_color_data(char *fname, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		{
			if (ft_strncmp(line, "F ", 2) == 0)
				save_color_data(&data->fcolors, line);
			else if (ft_strncmp(line, "C ", 2) == 0)
				save_color_data(&data->ccolors, line);
		}
	}
	close(fd);
	if ((data->fcolors.found_color != 1) || (data->ccolors.found_color != 1))
		ft_error(ERROR_MISSING_COLOR);
}

void	is_valid_color(t_color_info *color)
{
	char	**tokens;

	tokens = ft_split(color->string_color, ',');
	if (tokens == NULL)
	{
		ft_error(ERROR_SPLIT_COLOR);
	}
	if (tokens[0] == NULL || tokens[1] == NULL
		|| tokens[2] == NULL || tokens[3] != NULL)
	{
		free_tokens(tokens);
		ft_error(ERROR_FORMAT_COLOR);
	}
	color->int_r = atoi(tokens[0]);
	color->int_g = atoi(tokens[1]);
	color->int_b = atoi(tokens[2]);
	free_tokens(tokens);
	if (color->int_r < 0 || color->int_r > 255 || color->int_g < 0
		|| color->int_g > 255 || color->int_b < 0 || color->int_b > 255)
	{
		ft_error(ERROR_RANGE_COLOR);
	}
}

void	check_string_color(t_data data)
{
	int i;

	i = 0;
	while(data.fcolors.string_color[i])
	{
		if(!(data.fcolors.string_color[i] >= 48 && data.fcolors.string_color[i] <= 57) && data.fcolors.string_color[i] != ',')
			ft_error(ERROR_STRING_COLOR);
		i++;
	}
		i = 0;
	while(data.ccolors.string_color[i])
	{
		if(!(data.ccolors.string_color[i] >= 48 && data.ccolors.string_color[i] <= 57) && data.ccolors.string_color[i] != ',')
			ft_error(ERROR_STRING_COLOR);
		i++;
	}
}
// L'objectif est de mettre les couleurs dans nos struct
// On trouve une ligne qui start avec F ou C
// On regarde que cette direction na pas deja une couleur set
// On envoie dans  data, on extrait le char grace a split
// On atoi dans les differents int r, g, b.
// On regarde si c'est bien des valeurs rgb
// et je convertir pour la mlx
void	color_data(char *fname, t_data *data)
{
	found_color_data(fname, data);
	check_string_color(*data);
	is_valid_color(&data->fcolors);
	is_valid_color(&data->ccolors);
	data->fcolors.final_color = encode_rgb(data->fcolors.int_r,
			data->fcolors.int_g, data->fcolors.int_b);
	data->ccolors.final_color = encode_rgb(data->ccolors.int_r,
			data->ccolors.int_g, data->ccolors.int_b);
}
