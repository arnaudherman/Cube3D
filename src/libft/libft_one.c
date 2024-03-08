/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:57:21 by aherman           #+#    #+#             */
/*   Updated: 2024/03/08 15:17:41 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int		c1;
	char	*s1;

	c1 = 0;
	s1 = (char *)s;
	while (s[c1])
	{
		if (s1[c1] == (char)c)
			return ((char *)&s1[c1]);
		c1++;
	}
	if (s1[c1] == (char)c)
		return (&s1[c1]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	while (s2[j] != '\0')
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*ft_strdup(char *src)
{
	size_t	c[2];
	char	*s1;

	c[0] = 0;
	c[1] = 0;
	while (src[c[0]])
		c[0]++;
	s1 = malloc(sizeof(char) * (c[0] + 1));
	if (!s1)
		return (NULL);
	while (c[1] < c[0])
	{
		s1[c[1]] = src[c[1]];
		c[1]++;
	}
	s1[c[1]] = '\0';
	return (s1);
}
