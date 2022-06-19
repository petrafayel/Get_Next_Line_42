#include "get_next_line.h"

char	*ft_line(char	*s)
{
	int	i;
	char	*tmp;

	i = 0;
	if (!*s)
		return (NULL);
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			tmp = ft_substr(s, 0, i + 1);
			return (tmp);
		}
		i++;
	}
	tmp = ft_strdup(s);
	return (tmp);
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
		if (size == 0 || ft_strchr(buffer, '\n'))
			break ;
	}
	newline = ft_line(line);
	if (ft_newline(line) > -1)
	{
		temp = line;
		line = ft_substr(line, ft_newline(line) + 1, ft_strlen(line) - ft_strlen(newline));
		free (temp);
	}
	else
	{
		free (line);
		line = NULL;
	}
	return (newline);
}
