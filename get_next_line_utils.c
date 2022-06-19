#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	int	c;
	char	*ptr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	c = -1;
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (NULL);
	while (s1[++c])
		ptr[c] = s1[c];
	c = -1;
	while (s2[++c])
		ptr[i++] = s2[c];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strdup(char *src)
{
	int	j;
	int	i;
	char	*ptr;

	if (!src)
		return (NULL);
	j = 0;
	i = ft_strlen(src) + 1;
	ptr = (char *)malloc(sizeof(char) * i);
	if (!ptr)
		return (NULL);
	while (src[j])
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (start > ft_strlen(s))
	{
		*ptr = '\0';
		return (ptr);
	}
	while (s[start] && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

int	ft_newline(char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (s[j] == '\n')
			return (j);
		j++;
	}
	return (-1);
}
