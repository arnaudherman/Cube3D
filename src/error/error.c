/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:46:22 by aherman           #+#    #+#             */
/*   Updated: 2024/03/08 14:03:32 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(int flag)
{
	if (flag == -1)
		ft_putendl_fd(ERROR_NBR_ARG, 2);
	else if (flag == -2)
		ft_putendl_fd(ERROR_WRONG_MAP_NAME, 2);
	else if (flag == -3)
		ft_putendl_fd(ERROR_EXEMPLE, 2);
	else if (flag == -4)
		ft_putendl_fd(ERROR_MAP_EXT, 2);
	exit(-1);
}