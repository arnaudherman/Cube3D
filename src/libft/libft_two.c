/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:54:11 by aherman           #+#    #+#             */
/*   Updated: 2024/03/14 13:54:39 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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