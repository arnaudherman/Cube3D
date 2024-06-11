#include "cub3d.h"

void	remove_newline(char **array)
{
	char	**ptr;
	size_t	len;

	if (array == NULL || *array == NULL)
		return ;
	ptr = array;
	while (*ptr != NULL)
	{
		len = strlen(*ptr);
		if (len > 0 && (*ptr)[len - 1] == '\n')
			(*ptr)[len - 1] = '\0';
		ptr++;
	}
}

void	pad_strings_with_spaces(char **string, int max_len)
{
	int		i;
	int		string_len;
	char	*new_str;

	i = 0;
	string_len = 0;
	while (string[i] != NULL)
	{
		string_len = strlen(string[i]);
		if (string_len < max_len)
		{
			new_str = malloc(max_len + 1);
			if (new_str == NULL)
			{
				ft_error("ERROR_MALLOC");
				return ;
			}
			strcpy(new_str, string[i]);
			memset(new_str + string_len, ' ', max_len - string_len);
			new_str[max_len] = '\0';
			string[i] = new_str;
		}
		i++;
	}
}

int	find_max_len(char **string, int len)
{
	int	max_len;
	int	i;
	int	string_len;

	max_len = 0;
	i = 0;
	string_len = 0;
	while (string[i] != NULL)
	{
		string_len = strlen(string[i]);
		if (string_len > max_len)
			max_len = string_len;
		i++;
	}
	if (len > max_len)
		max_len = len;
	return (max_len);
}

void	complet_string_with_space(char **string, int len)
{
	int	max_len;

	max_len = find_max_len(string, len);
	pad_strings_with_spaces(string, max_len);
}

int	on_map(char car)
{
	if (car == 'N' || car == 'S' || car == 'E' || car == 'W' || car == '0')
		return (1);
	else
		return (0);
}
