/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:25:08 by aherman           #+#    #+#             */
/*   Updated: 2024/03/08 15:17:02 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*read_the_line(int fd, char *left_line)
{
	int		f1;
	char	*s1;

	f1 = 1;
	s1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!s1)
		return (NULL);
	while (f1 >= 1)
	{
		f1 = read(fd, s1, BUFFER_SIZE);
		if (f1 <= -1)
		{
			free(s1);
			free(left_line);
			return (NULL);
		}
		s1[f1] = 0;
		left_line = join_line(left_line, s1);
		if (ft_strchr(left_line, '\n'))
			break ;
	}
	free(s1);
	return (left_line);
}

char	*join_line(char *left_line, char *s1)
{
	char	*s2;

	if (!left_line)
		left_line = ft_calloc(1, sizeof(char));
	s2 = ft_strjoin(left_line, s1);
	free(left_line);
	return (s2);
}

char	*go_line(char *left_line)
{
	int		c1;
	char	*line;

	c1 = 0;
	if (!left_line[c1])
		return (NULL);
	while (left_line[c1] != '\0' && left_line[c1] != '\n')
		c1++;
	line = ft_calloc(c1 + 2, sizeof(char));
	c1 = 0;
	while (left_line[c1] != '\0' && left_line[c1] != '\n')
	{
		line[c1] = left_line[c1];
		c1++;
	}
	if (left_line[c1] != '\0' && left_line[c1] == '\n')
		line[c1++] = '\n';
	return (line);
}

char	*go_next(char *left_line)
{
	int		c[2];
	char	*line;

	c[0] = 0;
	c[1] = 0;
	while (left_line[c[0]] != '\0' && left_line[c[0]] != '\n')
		c[0]++;
	if (left_line[c[0]] == '\0')
	{
		free(left_line);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(left_line) - c[0] + 1), sizeof(char));
	c[0]++;
	while (left_line[c[0]] != '\0')
		line[c[1]++] = left_line[c[0]++];
	free(left_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_line);
		left_line = 0;
		return (NULL);
	}
	left_line = read_the_line(fd, left_line);
	if (!left_line)
		return (NULL);
	return_line = go_line(left_line);
	left_line = go_next(left_line);
	return (return_line);
}
