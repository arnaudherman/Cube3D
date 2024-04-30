/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:45:37 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/21 18:53:31 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://www.geeksforgeeks.org/strdup-strdndup-functions-c/#:~:text=strdup()%20%3A
&text=This%20function%20returns%20a%20pointer,to%20the%20duplicated%20string%20s.
*/
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*copie;
	int		i;

	size = ft_strlen(str);
	i = 0;
	copie = (char *)malloc(sizeof(char) * (size + 1));
	if (copie == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		copie[i] = str[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
