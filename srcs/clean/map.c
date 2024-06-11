#include "cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h_map)
	{
		free(map->map2d[i]);
		i++;
	}
	free(map->map2d);
}
