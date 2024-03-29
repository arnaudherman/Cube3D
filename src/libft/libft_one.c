
#include "../../include/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int		c1;
	char	*s1;

	c1 = 0;
	s1 = (char *)s;
	while (s[c1])
	{
		if (s1[c1] == (char)c)
			return ((char *)&s1[c1]);
		c1++;
	}
	if (s1[c1] == (char)c)
		return (&s1[c1]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}

// char	*ft_strdup(char *src)
// {
// 	size_t	c[2];
// 	char	*s1;

// 	c[0] = 0;
// 	c[1] = 0;
// 	while (src[c[0]])
// 		c[0]++;
// 	s1 = malloc(sizeof(char) * (c[0] + 1));
// 	if (!s1)
// 		return (NULL);
// 	while (c[1] < c[0])
// 	{
// 		s1[c[1]] = src[c[1]];
// 		c[1]++;
// 	}
// 	s1[c[1]] = '\0';
// 	return (s1);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	c1;

	c1 = 0;
	while (c1 != n)
	{
		((unsigned char *)s)[c1] = 0;
		c1++;
	}
}
