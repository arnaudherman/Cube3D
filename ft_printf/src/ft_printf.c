/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:50:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:35:15 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	what(va_list ap, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = print_c(va_arg(ap, int));
	else if (format == 's')
		len = print_s(va_arg(ap, char *));
	else if (format == 'p')
		len = print_p(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		len = print_d(va_arg(ap, int));
	else if (format == 'u')
		len = print_u(va_arg(ap, unsigned int));
	else if (format == 'x')
		len = print_x(va_arg(ap, unsigned int));
	else if (format == 'X')
		len = print_maj_x(va_arg(ap, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len = len + what(ap, *(format + 1));
			format++;
		}
		else
			len = len + ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
/*
Affiche un seul caractère.
Affiche une chaîne de caractères (telle que définie par la convention C).
L’argument de pointeur void * doit être affiché en hexadécimal.
Affiche un nombre décimal (base 10).
Affiche un entier en base 10.
Affiche un nombre décimal non signé (base 10).
Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
Affiche un signe pourcentage.
*/