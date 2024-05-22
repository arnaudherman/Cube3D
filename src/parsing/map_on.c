

#include "../../include/cub3d.h"

int	on_map(char car)
{
	if (car == 'N' || car == 'S' || car == 'E' || car == 'W' || car == '0')
		return (1);
	else
		return (0);
}

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
			if (string_down[i] != '1' && string_down[i]
				!= '0' && string_down[i] != 'N'
				&& string_down[i] != 'S' && string_down[i]
				!= 'W' && string_down[i] != 'E')
				ft_error(ERROR_MAP_CHECK_DOWN);
		}
		i++;
	}
}
