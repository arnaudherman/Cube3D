

#include "../../include/cub3d.h"

void	analyze_map_data(t_data *data)
{
	int	i;
	int	map_x_new;

	i = 0;
	while (i < data->map_y && data->map[i])
	{
		tab_to_space(data->map[i]);
		map_x_new = ft_strlen(data->map[i]);
		if (map_x_new > data->map_x)
			data->map_x = map_x_new - 1;
		i++;
	}
	remove_newline(data->map);
	complet_string_with_space(data->map, data->map_x);
}

void	check_map_bounds(t_data *data)
{
	int	i;

	i = 1;
	only_space_or_one(data->map[0]);
	only_space_or_one(data->map[data->map_y - 1]);
	check_upper(data->map[0], data->map[1]);
	while (i < data->map_y - 1)
	{
		check_down(data->map[i], data->map[i + 1]);
		i++;
	}
}

void	check_map(char *fname, t_data *data)
{
	int	fd_cub;

	fd_cub = open(fname, O_RDONLY);
	if (fd_cub < 0)
	{
		ft_error("Error opening file");
		return ;
	}
	read_map_data(fd_cub, data);
	analyze_map_data(data);
	check_map_bounds(data);
}
