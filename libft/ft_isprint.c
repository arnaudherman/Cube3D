/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:05:35 by bbessard          #+#    #+#             */
/*   Updated: 2022/10/31 18:51:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isprint() function tests for any printing character, including space (` ').  
The value of the argument must be
representable as an unsigned char or the value of EOF.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
