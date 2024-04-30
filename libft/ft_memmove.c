/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:36:33 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/21 18:48:32 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://koor.fr/C/cstring/memmove.wp
Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre 
source dans un nouvel emplacement désigné par le paramètre destination. 
On peut donc dire que cette fonction est proche de la fonction memcpy. 
Néanmoins, la différence réside dans le fait que la fonction memmove accepte 
que les deux zones de mémoire puissent se chevaucher.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
	char dest[] = "siiiii";
	char src[] = "ok le sang ";
	printf("%s\n", ft_memmove(dest, src, 5));
}
*/