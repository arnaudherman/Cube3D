/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:05:37 by bbessard          #+#    #+#             */
/*   Updated: 2022/10/31 15:19:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The isalpha() function tests for any character for which isupper(3) or 
islower(3) is true.  The value of the argument must be
representable as an unsigned char or the value of EOF.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
