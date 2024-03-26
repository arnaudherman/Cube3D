/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:56 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:35:19 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_di(int n)
{
	int	len;
	int	min;

	len = 0;
	min = -2147483648;
	if (n == min)
	{
		len += print_di(min / 10);
		len += print_di(min % 10 * -1);
	}
	else if (n < 0)
	{
		len += print_c('-');
		len += print_di(n * -1);
	}
	else if (n >= 0 && n <= 9)
	{
		len += print_c(n + '0');
	}
	else
	{
		len += print_di(n / 10);
		len += print_di(n % 10);
	}
	return (len);
}

int	print_d(int nb)
{
	int	len;

	len = print_di(nb);
	return (len);
}
