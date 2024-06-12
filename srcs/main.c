/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:50:31 by bbessard          #+#    #+#             */
/*   Updated: 2024/06/12 15:50:37 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		perror("There must be precisely 2 arguments\n");
		return (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	if (!data)
	{
		fprintf(stderr, "Failed to malloc data in main\n");
		exit(EXIT_FAILURE);
	}
	if (init_default_all(data) || init_custom_all(data) != 0)
	{
		perror("Failed to init struct in main\n");
		return (-1);
	}
	parsing(av[1], data);
	init_map2d(data->map2d, &data->mlx, data->map.x_map, data->map.y_map);
	loop(data);
	free_all(data);
	return (0);
}
