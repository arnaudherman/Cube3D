/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zonedechantier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:57:45 by aherman           #+#    #+#             */
/*   Updated: 2024/03/14 13:45:09 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Ici c'est juste pour coder sans y mettre la forme

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	c1;

	c1 = 0;
	while (s1[c1] == s2[c1] && c1 != size && s1[c1] != '\0' && s2[c1] != '\0')
		c1++;
	if (c1 == size)
		return (0);
	return (((unsigned char *)s1)[c1] - ((unsigned char *)s2)[c1]);
}

void	save_texture_data(t_texture_info *texture, char *line)
{
	char	*path;
	char	*path_start;
	char	*newline;
	int		fd;


	if (texture->texture_found == 0)
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
		fd = open(path, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			texture->road = path;
		}
		else
		{
			ft_error(ERROR_PATH_TEXT);
			free(path);
		}
	}
	else
		ft_error(ERROR_DOUBLE_TEXT);
}

void	found_textures_data(t_data *data)
{
	char *line;
	
	while ((line = get_next_line(data->fd)) != NULL) 
	{
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		{
			if(ft_strncmp(line, "NO ", 3) == 0)
				save_texture_data(&data->no, line);
			else if (ft_strncmp(line, "SO ", 3) == 0)
				save_texture_data(&data->so, line);

			else if (ft_strncmp(line, "WE ", 3) == 0)
				save_texture_data(&data->we, line);

			else if (ft_strncmp(line, "EA ", 3) == 0)
				save_texture_data(&data->ea, line);
		}
	}
	if ((data->no.texture_found == 0) && (data->so.texture_found == 0) && (data->we.texture_found == 0) && (data->ea.texture_found == 0))
		ft_error(ERROR_MISSING_TEXT);
}
