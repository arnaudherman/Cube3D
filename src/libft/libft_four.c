
#include "../../include/cub3d.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strrchr(const char *s, int c)
{
	int	c1;

	c1 = 0;
	c1 = ft_strlen(s);
	while (c1 > 0 && s[c1] != (char)c)
		c1--;
	if (s[c1] == (char)c)
		return ((char *)s + c1);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst2 = dst;
	src2 = src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*petit_s;
	size_t	size;
	size_t	size_s;

	size_s = ft_strlen(s);
	size = len;
	if (len > size_s - start)
		size = size_s - start;
	if (start >= size_s)
		size = 0;
	petit_s = malloc(size + 1);
	if (petit_s == 0)
		return (NULL);
	ft_memcpy(petit_s, s + start, size);
	petit_s[size] = '\0';
	return (petit_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	start;
	size_t	end;

	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (ft_strdup(""));
	start = 0;
	end = len_s1 - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}