/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:36:03 by bbessard          #+#    #+#             */
/*   Updated: 2023/05/08 10:59:48 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned	int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
			++n;
	}
}

int	main(void)
{
	unsigned int	a;
	unsigned int	b;

	a = 20;
	b = 10;
	printf("%u", lcm(a, b));
	return (0);
}
