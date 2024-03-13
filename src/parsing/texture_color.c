/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:33:07 by aherman           #+#    #+#             */
/*   Updated: 2024/03/13 17:17:09 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/cub3d.h"

// int	open_file_and_init(const char *file_d, int *fd, int *line_counter)
// {
// 	*line_counter = 0;
// 	*fd = open(file_d, O_RDONLY);
// 	if (*fd < 0)
// 		fail("Error opening file (parse_texture)");
// 	return (0);
// }

// int	check_value(char *rgb_str, unsigned int i)
// {
// 	unsigned int	j;
// 	char			*tmp_str;
// 	int				tmp;

// 	j = i;
// 	while (ft_isdigit(rgb_str[i]))
// 		i++;
// 	if (i - j == 0 || i - j > 3)
// 		fail("No number or too big.");
// 	tmp_str = ft_substr(rgb_str, j, 3);
// 	if (!tmp_str)
// 		fail("Error substr (check_value)");
// 	tmp = ft_atoi(tmp_str);
// 	free(tmp_str);
// 	if (tmp < 0 || tmp > 255)
// 		return (-1);
// 	return ((int) i);
// }

// int	check_format(char *rgb_str)
// {
// 	int	i;

// 	i = 0;
// 	if (!rgb_str)
// 		fail("No color?");
// 	i = check_value(rgb_str, (unsigned int) i);
// 	if (i < 0 || rgb_str[i++] != ',')
// 		return (1);
// 	i = check_value(rgb_str, (unsigned int) i);
// 	if (i < 0 || rgb_str[i++] != ',')
// 		return (1);
// 	i = check_value(rgb_str, (unsigned int) i);
// 	if (i < 0)
// 		return (1);
// 	if (rgb_str[i] != '\0')
// 		return (1);
// 	return (0);
// }

// int	convert_colors(t_data *data)
// {
// 	char	**tmp;

// 	if (check_format(data->colors.c_color))
// 		fail("Wrong format for ceiling color.");
// 	if (check_format(data->colors.f_color))
// 		fail("Wrong format for floor color.");
// 	tmp = ft_split(data->colors.f_color, ',');
// 	if (tmp == NULL)
// 		fail("error split (convert_colors");
// 	data->colors.floor = convert_color(tmp);
// 	tmp = ft_split(data->colors.c_color, ',');
// 	if (tmp == NULL)
// 		fail("error split (convert_colros)");
// 	data->colors.ceiling = convert_color(tmp);
// 	return (0);
// }

// void	check_and_close(int fd, int line_counter)
// {
// 	close(fd);
// 	if (line_counter != 6)
// 		fail("Incorrect number of texture/color lines");
// }

// int	get_rgb(int dir, char *line, t_data *data)
// {
// 	char	**tmp;

// 	tmp = ft_split(line, ' ');
// 	if (tmp == NULL)
// 		fail("In get_color");
// 	if (dir == FLOOR)
// 	{
// 		data->colors.f_color = ft_strdup(tmp[1]);
// 		if (data->colors.f_color == NULL)
// 			fail("In get_color floor");
// 		data->colors.f_color[ft_strlen(tmp[1]) - 1] = 0;
// 	}
// 	else if (dir == CEILING)
// 	{
// 		data->colors.c_color = ft_strdup(tmp[1]);
// 		if (data->colors.c_color == NULL)
// 			fail("In get_color ceiling");
// 		data->colors.c_color[ft_strlen(tmp[1]) - 1] = 0;
// 	}
// 	free(tmp[0]);
// 	free(tmp[1]);
// 	free(tmp);
// 	return (0);
// }

// int	get_texture_path(t_orientation dir, char *line, t_data *data)
// {
// 	char	**tmp;

// 	tmp = ft_split(line, ' ');
// 	if (!tmp || !tmp[0] || !tmp[1])
// 		fail("split error");
// 	if (reverse_strncmp(tmp[1], ".xpm", 4) != 0)
// 		fail("Texture not a xpm file");
// 	if (dir == NORTH)
// 		get_path_texture(tmp[1], &data->no_path, "fail to open North texture");
// 	else if (dir == SOUTH)
// 		get_path_texture(tmp[1], &data->so_path, "fail to open South texture");
// 	else if (dir == WEST)
// 		get_path_texture(tmp[1], &data->we_path, "fail to open West texture");
// 	else if (dir == EAST)
// 		get_path_texture(tmp[1], &data->ea_path, "fail to open East texture");
// 	else if (dir == DOOR)
// 		get_path_texture(tmp[1], &data->door_path, "fail to open Door texture");
// 	free(tmp[0]);
// 	free(tmp[1]);
// 	free(tmp);
// 	return (0);
// }

// int	get_path_texture(char *path, char **texture_path, char *error_message)
// {
// 	*texture_path = ft_strdup(path);
// 	if (!(*texture_path))
// 		fail("memory error get_path_texture");
// 	(*texture_path)[ft_strlen(*texture_path) - 1] = 0;
// 	if (open(*texture_path, O_RDONLY) < 0)
// 		fail(error_message);
// 	return (0);
// }

// void	extract_info(char *trimmed_line, t_data *data, int *line_counter)
// {
// 	if (!ft_strncmp(trimmed_line, "NO", 2))
// 		get_texture_path(NORTH, trimmed_line, data);
// 	else if (!ft_strncmp(trimmed_line, "SO", 2))
// 		get_texture_path(SOUTH, trimmed_line, data);
// 	else if (!ft_strncmp(trimmed_line, "WE", 2))
// 		get_texture_path(WEST, trimmed_line, data);
// 	else if (!ft_strncmp(trimmed_line, "EA", 2))
// 		get_texture_path(EAST, trimmed_line, data);
// 	else if (!ft_strncmp(trimmed_line, "F", 1))
// 		get_rgb(FLOOR, trimmed_line, data);
// 	else if (!ft_strncmp(trimmed_line, "C", 1))
// 		get_rgb(CEILING, trimmed_line, data);
// 	*line_counter = *line_counter + 1;
// }

// void	check_line_type(char *trimmed_line, t_data *data, int *line_counter)
// {
// 	if (!ft_strncmp(trimmed_line, "NO", 2)
// 		|| !ft_strncmp(trimmed_line, "SO", 2)
// 		|| !ft_strncmp(trimmed_line, "WE", 2)
// 		|| !ft_strncmp(trimmed_line, "EA", 2)
// 		|| !ft_strncmp(trimmed_line, "F", 1)
// 		|| !ft_strncmp(trimmed_line, "C", 1))
// 	{
// 		extract_info(trimmed_line, data, line_counter);
// 	}
// }

// void	trimmed_line(char *line, t_data *data, int *line_counter)
// {
// 	char	*trimmed_line;

// 	trimmed_line = line;
// 	while (*trimmed_line == ' ' || *trimmed_line == '\t')
// 		trimmed_line++;
// 	check_line_type(trimmed_line, data, line_counter);
// }

// int	parse_textures(char *file_d, t_data *data)
// {
// 	int		fd;
// 	int		line_counter;
// 	char	*line;

// 	open_file_and_init(file_d, &fd, &line_counter);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		trimmed_line(line, data, &line_counter);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	check_and_close(fd, line_counter);
// 	return (0);
// }
