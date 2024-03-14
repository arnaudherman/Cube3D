/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:34 by aherman           #+#    #+#             */
/*   Updated: 2024/03/14 12:53:52 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		ft_error(ERROR_NBR_ARG);
	ft_bzero(&data, sizeof(t_data));
	if (!parsing(argv, &data))
		return (0);
}
