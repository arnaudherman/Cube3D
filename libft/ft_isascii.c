/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:57:24 by bbessard          #+#    #+#             */
/*   Updated: 2022/10/31 18:46:53 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isascii() function tests for an ASCII character (in the range 0 to 127).
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
