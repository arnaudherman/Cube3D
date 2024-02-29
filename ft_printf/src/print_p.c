/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:07 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:35:26 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_p(unsigned long ull)
{
	int	len;

	len = 0;
	if (ull == 0)
		return (print_s("0x0"));
	else
	{
		len += print_s("0x");
		len += print_x(ull);
	}
	return (len);
}
