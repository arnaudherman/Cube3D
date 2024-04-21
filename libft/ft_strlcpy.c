/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:51:57 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/16 11:04:02 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.
lib_ref/topic/s/strlcat.html
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
int main(void)
{
    char dest[] = "julien";
    char src[] = "cava";
    printf("%d\n", ft_strlcpy(dest, src, 3));
}*/