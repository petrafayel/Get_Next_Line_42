#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
int	ft_strlen(char * str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strchr(char *s, int c);
int	ft_newline(char *s);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);

#endif
