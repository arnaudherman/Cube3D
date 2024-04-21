/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:51:22 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/05 15:25:10 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s != '\0')
	{	
		if (*s == (char)c)
			result = (char *)(s);
		s++;
	}
	if ((char)c == '\0')
		result = (char *)(s);
	return (result);
}
/*
int main(void)
{
	const char	*s;
	s = "bonjour";
	printf("%s\n", ft_strrchr(s, 'o'));
	printf("%s\n", strrchr(s, 'o'));
	
}
*/