

#include "../../include/cub3d.h"

void	remove_newline(char **array)
{
	char	**ptr;
	size_t	len;

	ptr = array;
	if (array == NULL || *array == NULL)
	{
		return ;
	}
	while (*ptr != NULL)
	{
		len = strlen(*ptr);
		if (len > 0 && (*ptr)[len - 1] == '\n')
		{
						(*ptr)[len - 1] = '\0';
		}
		ptr++;
	}
}

size_t	calculate_new_length(const char *string)
{
	size_t		len;
	const char	*p;

	len = 0;
	p = string;
	while (*p != '\0')
	{
		if (*p == '\t')
			len += 4;
		else
			len += 1;
		p++;
	}
	return (len);
}

void	copy_with_spaces(const char *src, char *dest)
{
	while (*src != '\0')
	{
		if (*src == '\t')
		{
			*(dest++) = ' ';
			*(dest++) = ' ';
			*(dest++) = ' ';
			*(dest++) = ' ';
		}
		else
		{
			*(dest++) = *src;
		}
		src++;
	}
	*dest = '\0';
}

void	tab_to_space(char *string)
{
	size_t	new_len;
	char	*new_string;

	new_len = calculate_new_length(string);
	new_string = malloc(new_len + 1);
	if (new_string == NULL)
	{
		ft_error(ERROR_MALLOC);
		return ;
	}
	copy_with_spaces(string, new_string);
	strcpy(string, new_string);
	free(new_string);
}
