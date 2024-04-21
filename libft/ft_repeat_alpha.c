/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:00:21 by bbessard          #+#    #+#             */
/*   Updated: 2023/05/10 18:19:12 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	alpha_index(char c)
{
	int		index;
	char	*str;

	index = 0;
	str = "abcdefghijklmnopqrstuvwxyz";
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	index;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			index = alpha_index(av[1][i]);
			while (index >= 0)
			{
				write(1, &av[1][i], 1);
				index--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
