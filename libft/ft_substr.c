/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:44:05 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/22 11:19:51 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Elle renvoie la sous-chaîne de la chaîne source qui commence à la position m 
et se termine à la position n-1. 
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(*str) * (len + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s + start, len);
		str[len] = '\0';
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("%s\n", ft_substr("abcdefghijklmnopppppppp", 7, 10));
}
*/