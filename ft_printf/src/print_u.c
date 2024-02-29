/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:12 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:35:35 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_u(unsigned int ui1)
{
	int	len;

	len = 0;
	if (ui1 >= 0 && ui1 <= 9)
	{
		len += print_c(ui1 + '0');
	}
	else
	{
		len += print_u(ui1 / 10);
		len += print_u(ui1 % 10);
	}
	return (len);
}
