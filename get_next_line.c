#include "get_next_line.h"

char	*ft_line(char	*s)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			line = (char *)malloc((sizeof(char) * i) + 2);
			if (!line)
				return (NULL);
			while (j < i)
			{
				line[j] = s[j];
				j++;
			}
			line[j] = '\n';
			line[j + 1] = '\0';
		}
		i++;
	}
	if (!line)
		return (s);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	int		size;

	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buffer[size] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n') || size == 0)
			break ;
	}
	newline = ft_line(line);
	if (ft_strchr(newline, '\n'))
	{
		temp = line;
		line = (char *)(line + (ft_strlen(newline) + 1));
		free (temp);
	}
	return (newline);
}