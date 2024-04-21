/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:44:54 by bbessard          #+#    #+#             */
/*   Updated: 2022/10/31 19:02:57 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://fr.ans.wiki/2060/comment-utiliser-la-fonction-strlcat/
http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc
.neutrino_lib_ref%2Fi%2Fisascii.html
str : ça parle de chaîne de caractères
l : suivant la longueur
cat : concatène
strlcat met les deux chaînes en paramètre à la suite les unes des autres, 
mais pas de façon plus longue que le troisième paramètre ne l'indique.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	res;
	size_t	len_src;
	size_t	i;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + size;
	while (s[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
