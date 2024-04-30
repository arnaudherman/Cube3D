/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:11:14 by bbessard          #+#    #+#             */
/*   Updated: 2022/10/31 15:03:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The bzero() function fills the first n bytes of the object pointed to by dst 
with zero (NUL) bytes.
*s = *dst
This function is similar to the ANSI memset() function. New code should 
use the ANSI function.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
