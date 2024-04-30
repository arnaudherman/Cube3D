/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:37:14 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/05 15:24:50 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://koor.fr/C/cstring/strchr.wp
Cette fonction recherche la première occurrence du caractère passé en second 
paramètre dans la chaîne de caractères spécifiée via le premier paramètre.

la fonction strchr est très proche de la fonction strrchr. La différence réside 
dans le fait que strchr renvoi la position de la première occurrence du 
caractère recherché alors que strrchr renvoi la dernière occurrence 
(recherche par la droite : r signifiant right).
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*
int main(void)
{
	const char    str[50] = "the cake is a lie !\0I'm hidden lol\r\n";
	printf("%s\n", ft_strchr(str, 'x'));
	printf("%s\n", strchr(str, 'x'));
}
*/