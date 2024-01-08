#include "get_next_line.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
    int i;
    int j;
    int len;
    char *tab;

    i = 0;
    j = size;
    len = ft_strlen(s1) + j;
    tab = malloc(sizeof(char) * (len + 1));
    if (!tab)
        return (NULL);
    while (s1[i])
    {
        tab[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        tab[j] = s2[i];
        i++;
        j++;
    }
    tab[j] = '\0';
    free(s1);
    s1 = NULL;
    return (tab);
}

size_t  ft_strlcpy(char *dst, char *src, size_t size)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = ft_strlen(src);
    if (size > 0)
    {
        while (src[i] && i < (size - 1))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (j);
}

char *ft_strdup(char *s1)
{
    char    *tab;
    int i;

    i = 0;
    tab = malloc(sizeof(char) * ft_strlen(s1) + 1);
    if(!tab)
        return (NULL);
    while (s1[i])
    {
        tab[i] = s1[i];
        i++;
    }
    tab[i] = '\0';
    return (tab);
}


char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char    *line;
    char    *new_line;
    int     countread;
    int     to_copy;

    line = ft_strdup(buf);
    while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[countread] = '\0';
        line = ft_strjoin(line, buf, countread);
    }
    if (ft_strlen(line) == 0)
    {
        free(line);
        return (NULL);
    }
    new_line = ft_strchr(line, '\n');
    if (new_line != NULL)
    {
        to_copy = new_line - line + 1;
        ft_strlcpy(buf, new_line, BUFFER_SIZE + 1);
    }
    else
    {
        to_copy = ft_strlen(line);
        ft_strlcpy(buf, "", BUFFER_SIZE + 1);
    }
    line[to_copy] = '\0';
    return (line);
}