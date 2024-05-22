

#include "../../include/cub3d.h"

void	only_space_or_one(char *string)
{
	int	i;

	i = 0;
	while (string[i + 1] != '\0')
	{
		if (string[i] != ' ' && string[i] != '1')
			ft_error(ERROR_MAP_ONLY_SPACE_ONE);
		i++;
	}
}

void	check_start_end(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(string);
	while (string[i] == ' ')
	{
		i++;
	}
	if (string[i] != '1')
	{
		ft_error(ERROR_MAP_NOT_ONE_START);
	}
	if (string[len - 1] == '\n')
		len -= 1;
	if (string[len - 1] != '\n')
		len -= 1;
	while (string[len] == ' ')
	{
		len--;
	}
	if (string[len] != '1')
		ft_error(ERROR_MAP_NOT_ONE_END);
}

int	find_max_string_length(char **strings, int len)
{
	int	max_len;
	int	i;
	int	string_len;

	max_len = 0;
	i = 0;
	while (i < len && strings[i] != NULL)
	{
		string_len = strlen(strings[i]);
		if (string_len > max_len)
			max_len = string_len;
		i++;
	}
	return (max_len);
}

void	adjust_string_length(char *string, int new_len)
{
	int	current_len;

	current_len = strlen(string);
	if (current_len < new_len)
	{
		string = realloc(string, new_len + 1);
		if (string == NULL)
		{
			ft_error("Error: Memory allocation failed");
			return ;
		}
		memset(string + current_len, ' ', new_len - current_len);
		string[new_len] = '\0';
	}
}

void	complet_string_with_space(char **strings, int len)
{
	int	max_len;
	int	i;

	max_len = find_max_string_length(strings, len);
	i = 0;
	while (i < len && strings[i] != NULL)
	{
		adjust_string_length(strings[i], max_len);
		i++;
	}
}
