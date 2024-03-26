/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:20:21 by aherman           #+#    #+#             */
/*   Updated: 2023/10/17 19:02:00 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_c(int c);
int	print_s(char *s1);
int	print_x(unsigned long n);
int	print_maj_x(unsigned long n);
int	print_d(int nb);
int	print_p(unsigned long ull);
int	print_u(unsigned int ui1);

#endif