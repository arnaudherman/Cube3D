/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:11 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:18 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	c1;

	c1 = 0;
	while (s[c1])
	{
		ft_putchar_fd(s[c1], fd);
		c1++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	ft_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(-1);
}

int	err(char *str)
{	
	while (*str)
		write(2, str++, 1);
	return (1);
}
