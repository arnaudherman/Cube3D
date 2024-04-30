/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:32:56 by bbessard          #+#    #+#             */
/*   Updated: 2023/05/01 17:10:54 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		nbr = (nbr % 10000000) + 1;
		ft_putchar('-');
		ft_putchar('2');
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
}

int	ft_atoi(char *s1)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if ((*s1 >= 9 && *s1 <= 13) || *s1 == 32)
		s1++;
	if (*s1 == '-')
		sign = -1;
	if (*s1 == '-' || *s1 == '+')
		s1++;
	while (*s1 >= '0' && *s1 <= '9')
	{
		result = (result * 10) + (*s1 - '0');
		s1++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	int	x;
	int	nbr;

	x = 1;
	nbr = ft_atoi(av[1]);
	if (ac == 2)
	{
		while (x <= 9)
		{
			ft_putnbr(x);
			write (1, " x ", 3);
			ft_putnbr(nbr);
			write (1, " = ", 3);
			ft_putnbr(nbr * x);
			x++;
			write (1, "\n", 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}
