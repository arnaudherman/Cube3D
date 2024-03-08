/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:48:53 by aherman           #+#    #+#             */
/*   Updated: 2024/03/08 14:09:59 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	read_map(char *fdmap, t_data *data, int *count)
{
	data->fd = open(fdmap, O_RDONLY); // set fd to .cub
	if (data->fd == -1)
		return (write(1, "Error\ninvalid file\n", 20), 0);
	data->line = get_next_line(data->fd);
	if (data->line == NULL)
		return (write(1, "Error\nempty file\n", 18), 0);
	data->ture = ft_strdup("");
	while (data->line && data->line[0] != '1' && data->line[0] != 32)
	{
		if (check_color_textures(data->line))
		{
			data->ture = ft_strjoin(data->ture, data->line);
			(*count)++;
		}
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	if (!check_countture(data, *count))
		return (freeme(NULL, NULL, data->fd), 0);
	data->ture2d = ft_split(data->ture, '\n');
	if (!data->ture2d)
		return (freeme(data->ture, NULL, data->fd), 0);
	if (!read_map_(data, *count))
		return (freeme(data->ture, NULL, data->fd), free_2d(data->ture2d), 0);
	return (freeme(data->ture, data->line, data->fd), 1);
}

int ft_check_ext_name(char *fname, char *name)
{
	char	*dotp;

	dotp = ft_strrchr(fname, '.');
	if (dotp && !ft_strcmp(dotp, name))
		return (1);
	else if (!fname || !dotp)
		return (0);
	return (0);
}

int	parsing(int argc, char *argv[], t_data *data, t_txtr *l_ture)
{
	int		count;

	count = 0;
	l_ture = NULL;
	if (argc != 2 || !ft_check_ext_name(argv[1], ".cub"))
	{
		ft_error(-4);
		exit(0);
	}
	if (!read_map(argv[1], data, &count))
		return (0);
	if (!valid_map(data))
		return (0);
	if (!lst_ture(data, &l_ture))
		return (free_map(data), freelist(&l_ture), 0);
	if (!color_ture(data, l_ture))
		return (free_map(data), freelist(&l_ture), 0);
	get_x_y_player(data);
	get_rows_cols(data);
	data->t = l_ture;
	return (1);
}
