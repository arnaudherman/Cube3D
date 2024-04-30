/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:58:55 by bbessard          #+#    #+#             */
/*   Updated: 2023/05/08 10:58:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Plus Grand Common Divider = PGCD
*/

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	tmp;

	a = atoi(av[1]);
	b = atoi(av[2]);
	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (0);
	}
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	printf("%d\n", a);
}
