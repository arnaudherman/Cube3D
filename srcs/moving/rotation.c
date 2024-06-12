/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:16 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:47:18 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	data->player->angle -= ROTATION;
	if (data->player->angle < 0.0)
		data->player->angle += 360.0;
	data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
	data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}

void	rotate_right(t_data *data)
{
	data->player->angle += ROTATION;
	if (data->player->angle >= 360.0)
		data->player->angle -= 360.0;
	data->player->x_dir = cos(data->player->angle * (M_PI / 180.0));
	data->player->y_dir = sin(data->player->angle * (M_PI / 180.0));
}
