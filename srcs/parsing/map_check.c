/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:38 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:48:11 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_upper(char *string_up, char *string_down)
{
	int	i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_down[i]) == 1)
		{
			if (string_up[i] != '1')
				ft_error(ERROR_MAP_CHECK_UPER);
		}
		i++;
	}
}

void	check_down(char *string_up, char *string_down)
{
	int	i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_up[i]) == 1)
		{
			if (string_down[i] != '1' && string_down[i] != '0'
				&& string_down[i] != 'N'
				&& string_down[i] != 'S' && string_down[i] != 'W'
				&& string_down[i] != 'E')
				ft_error(ERROR_MAP_CHECK_DOWN);
		}
		i++;
	}
}

void	check_zero(char *string_up, char *string_down)
{
	int	i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_down[i]) == 1)
		{
			if (string_up[i] != '1' && string_up[i] != '0'
				&& string_up[i] != 'N'
				&& string_up[i] != 'S' && string_up[i] != 'W'
				&& string_up[i] != 'E')
				ft_error(ERROR_MAP_CHECK_DOWN);
		}
		i++;
	}
}

void	check_start_end(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(string);
	while (string[i] == ' ')
		i++;
	if (string[i] != '1')
	{
		ft_error(ERROR_MAP_NOT_ONE_START);
	}
	if (string[len - 1] == '\n')
		len -= 1;
	if (string[len - 1] != '\n')
		len -= 1;
	while (string[len] == ' ')
		len--;
	if (string[len] != '1')
	{
		printf("string len a -2 lol:%d\n", string[len]);
		ft_error(ERROR_MAP_NOT_ONE_END);
	}
}

void	only_space_or_one(char *string)
{
	int	i;

	i = 0;
	while (string[i + 1] != '\0')
	{
		if (string[i] != ' ' && string[i] != '1')
			ft_error(ERROR_MAP_ONLY_SPACE_ONE);
		i++;
	}
}
