/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:49 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:46:51 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys->w = 1;
	else if (key == KEY_A)
		data->keys->a = 1;
	else if (key == KEY_S)
		data->keys->s = 1;
	else if (key == KEY_D)
		data->keys->d = 1;
	else if (key == KEY_ESC)
		data->keys->esc = 1;
	else if (key == LEFT_ARR)
		data->keys->left = 1;
	else if (key == RIGHT_ARR)
		data->keys->right = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys->w = 0;
	else if (key == KEY_A)
		data->keys->a = 0;
	else if (key == KEY_S)
		data->keys->s = 0;
	else if (key == KEY_D)
		data->keys->d = 0;
	else if (key == KEY_ESC)
		data->keys->esc = 0;
	else if (key == LEFT_ARR)
		data->keys->left = 0;
	else if (key == RIGHT_ARR)
		data->keys->right = 0;
	return (0);
}

void	key_move(t_data *data, int tile_size)
{
	if (data->keys->w == 1)
		go_up(data, tile_size);
	else if (data->keys->a == 1)
		go_left(data, tile_size);
	else if (data->keys->s == 1)
		go_down(data, tile_size);
	else if (data->keys->d == 1)
		go_right(data, tile_size);
	if (data->keys->left == 1)
		rotate_left(data);
	if (data->keys->right == 1)
		rotate_right(data);
	if (data->keys->esc == 1)
		exit_game(data);
}

t_keys	*allocate_keys(void)
{
	t_keys	*keys;

	keys = (t_keys *)ft_calloc(1, sizeof(t_keys));
	if (!keys)
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->esc = 0;
	keys->left = 0;
	keys->right = 0;
	return (keys);
}
