#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


char *ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

// void	free_tokens(char **tokens)
// {
// 	int	i;

// 	i = 0;
// 	if (tokens == NULL)
// 		return ;
// 	while (tokens[i] != NULL)
// 	{
// 		free(tokens[i]);
// 		i++;
// 	}
// 	free(tokens);
// }

// static char	*in_tab(const char *s1, int c1, int c2)
// {
// 	char	*s2;
// 	int		i;

// 	i = 0;
// 	s2 = malloc((c2 - c1 + 1) * sizeof(char));
// 	while (c1 < c2)
// 		s2[i++] = s1[c1++];
// 	s2[i] = '\0';
// 	return (s2);
// }

static int	number_word(const char *s1, char c)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (*s1)
	{
		if (*s1 != c && c2 == 0)
		{
			c2 = 1;
			c1++;
		}
		else if (*s1 == c)
			c2 = 0;
		s1++;
	}
	return (c1);
}