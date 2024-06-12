/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:24 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:25 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
}

void	clear_window(t_mlx *mlx)
{
	if (mlx->mlx_win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win_ptr);
	free(mlx);
}

void	clear_image(t_image *image, t_mlx *mlx)
{
	if (image->road)
		free(image->road);
	if (image->img)
		mlx_destroy_image(mlx->mlx_ptr, image->img);
	free(image);
}

void	destroy_data(t_data *data)
{
	free(data->keys);
	free(data->player);
	clear_window(data->mlx.mlx_win_ptr);
	free(data);
}
