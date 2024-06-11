#include "cub3d.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_if_malloc_failed(t_data *data)
{
	free(data->map2d);
	free(data->world);
	free(data->player);
	free(data->keys);
	free(data->image);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->map2d);
	free(data->world);
	free(data->player);
	free(data->keys);
	free(data->ray);
	while (i < data->map.h_map)
	{
		free(data->map.map2d[i]);
		i++;
	}
	free(data->map.map2d);
}
