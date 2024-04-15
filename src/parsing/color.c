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

void	save_color_data(t_color *color, char *line)
{
	char	*path;
	char	*path_start;
	char	*newline;
	// int		fd;

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
	}
	else
		ft_error(ERROR_DOUBLE_COLOR);
}

void	found_color_data(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		{
			if (ft_strncmp(line, "F ", 2) == 0)
				save_color_data(&data->color.fcolor, line);
			else if (ft_strncmp(line, "C ", 2) == 0)
				save_color_data(&data->color.fcolor, line);
		}
	}
	if ((data->color.found_color == 1) || (data->color.found_color == 1))
		ft_error(ERROR_MISSING_COLOR);
}

void	is_valid_color(t_color *color)
{
	char	**tokens;

	tokens = ft_split(color, ',');
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

// L'objectif est de mettre les couleurs dans nos struct
// On trouve une ligne qui start avec F ou C
// On regarde que cette direction na pas deja une couleur set
// On envoie dans  data, on extrait le char grace a split
// On atoi dans les differents int r, g, b.
// On regarde si c'est bien des valeurs rgb
// et je convertir pour la mlx
void	color_data(t_data *data)
{
	found_color_data(data);
	is_valid_color(&(data->color.fcolor));
	is_valid_color(&(data->color.ccolor));
	data->color.final_color = encode_rgb(data->color.int_r,
			data->color.int_g, data->color.int_b);
	data->color.final_color = encode_rgb(data->color.int_r,
			data->color.int_g, data->color.int_b);
}

