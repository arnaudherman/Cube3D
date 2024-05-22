

#include "../../include/cub3d.h"

size_t	strlen(const char *s)
{
	size_t	c1;

	c1 = 0;
	while (s[c1] != '\0')
		c1++;
	return (c1);
}

static void	small_mallocman(char ***s, int c)
{
	*s = malloc((c + 1) * sizeof(char *));
}

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

static char	*in_tab(const char *s1, int c1, int c2)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc((c2 - c1 + 1) * sizeof(char));
	while (c1 < c2)
		s2[i++] = s1[c1++];
	s2[i] = '\0';
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	size_t	c1;
	size_t	c2;
	int		c3;
	char	**s1;

	small_mallocman(&s1, number_word(s, c));
	if (!s || !s1)
		return (NULL);
	c1 = 0;
	c2 = 0;
	c3 = -1;
	while (c1 <= strlen(s))
	{
		if (s[c1] != c && c3 < 0)
			c3 = c1;
		else if ((s[c1] == c || c1 == strlen(s)) && c3 >= 0)
		{
			s1[c2++] = in_tab(s, c3, c1);
			c3 = -1;
		}
		c1++;
	}
	s1[c2] = 0;
	return (s1);
}
