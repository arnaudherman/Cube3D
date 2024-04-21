/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:00:38 by bbessard          #+#    #+#             */
/*   Updated: 2023/08/23 14:00:40 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Stores the excess in the stash for the next reading.*/
static char	*ft_new_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (str == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	str[j] = '\0';
	return (str);
}

/* Return the line cleaned of excess */
static char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

/* reads BUFFER_SIZE elements and adds them to a buffer.
Return the stash to be managed next. */
static char	*ft_fill_stash(int fd, char *stash)
{
	char	*buffy;
	int		byties;

	byties = 1;
	buffy = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffy == NULL)
		return (NULL);
	while (byties != 0 && ft_strchr(stash, '\n') == 0)
	{
		byties = read(fd, buffy, BUFFER_SIZE);
		if (byties == -1)
		{
			free(buffy);
			return (NULL);
		}
		buffy[byties] = '\0';
		stash = ft_strjoin_gnl(stash, buffy);
	}
	free(buffy);
	return (stash);
}

/*
Reads a line from a file descriptor.
@param fd The file descriptor to read from.
@return On success, the function returns a
pointer to the line read. On
error, the function returns NULL.
The function reads the file descriptor and
returns a line of text, delimited by
'\n'. It uses a static linked list to store
the data read from the file descriptor
between successive calls. The function returns
NULL if an error occurs or if the
end of file is reached.
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = 0;
		return (NULL);
	}
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = 0;
	}
	stash = ft_fill_stash(fd, stash);
	if (*stash == 0)
	{
		free(stash);
		return (stash = 0);
	}
	line = ft_extract_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}

// int	main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	printf("Ceci est la 1 line :\n%s", get_next_line(fd));
// 	printf("Ceci est la 2 line :\n%s\n", get_next_line(fd));
// 	printf("Ceci est la 3 line :\n%s\n", get_next_line(fd));
// 	printf("Ceci est la 4 line :\n%s\n", get_next_line(fd));
// 	printf("Ceci est la 5 line :\n%s\n", get_next_line(fd));
// 	printf("Ceci est la 6 line :\n%s\n", get_next_line(fd));
// 	return (0);
// }