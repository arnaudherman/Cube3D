/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:10 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:35:30 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_s(char *s1)
{
	int	c1;

	c1 = 0;
	if (!s1)
		return (write(1, "(null)", 6));
	while (s1[c1])
	{
		write (1, &s1[c1], 1);
		c1++;
	}
	return (c1);
}
