/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:54:59 by rapetros          #+#    #+#             */
/*   Updated: 2022/06/20 14:09:52 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char	*s)
{
	int		i;
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

char	*ft_readline(int fd, char *s)
{
	char	buffer[BUFFER_SIZE + 1];
	int		size;

	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || BUFFER_SIZE <= 0)
			return (NULL);
		buffer[size] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (size == 0 || ft_newline(buffer) > -1)
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*temp;
	char		*newline;

	line[fd] = ft_readline(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	newline = ft_line(line[fd]);
	if (ft_newline(line[fd]) > -1)
	{
		temp = line[fd];
		line[fd] = ft_substr(line[fd], ft_newline(line[fd]) + 1, \
				ft_strlen(line[fd]) - (ft_strlen(newline)));
		free (temp);
	}
	else
	{
		free (line[fd]);
		line[fd] = NULL;
	}	
	return (newline);
}
