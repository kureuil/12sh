/*
** get_next_line.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Tue Dec  30 2:24:40 2014 Louis Person
** Last update Wed Jan 21 23:29:53 2015 Louis Person
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	gnl_cat_alloc(char **src, char *add)
{
  char	*res;
  int	len;
  
  if (src == NULL)
    return (-1);
  if ((len = my_strlen(add)) == 0)
    return (0);
  if ((res = malloc(my_strlen(*src) + GNL_BUFFER + 1)) == NULL)
    return (-1);
  my_strcpy(res, *src);
  my_strncat(res, add, len);
  if (*src != NULL)
    free(*src);
  *src = res;
  return (0);
}

char	*extract_line(char *leftover, char *src, bool should_free)
{
  int	index;
  char	*line;
  int	len;

  if (src == NULL || leftover == NULL)
    return (NULL);
  len = my_strlen(src) - 1;
  if ((index = index_of('\n', src)) == -1)
    return (NULL);
  line = my_strndup(src, index);
  my_strcpy(leftover, src + index + 1);
  if (should_free == true)
    free(src);
  return (line);
}

void	gnl_cleanup(char *leftover, char *line)
{
  leftover[0] = '\0';
  free(line);
}

char		*get_next_line(int fd)
{
  static char	leftover[GNL_BUFFER];
  char		buf[GNL_BUFFER];
  char		*l;
  int		count;

  count = 1;
  if ((l = extract_line(leftover, leftover, false)) != NULL)
    return (l);
  l = my_strdup(leftover);
  while (!my_is_in(l, '\n') && (count = my_read(fd, buf, GNL_BUFFER - 1)) > 0)
    gnl_cat_alloc(&l, buf);
  if (count < 0)
    gnl_cleanup(leftover, l);
  else if (count == 0 && l != NULL && l[0] != '\0')
    {
      l = my_strdup(leftover);
      leftover[0] = '\0';
      return (l);
    }
  return (extract_line(leftover, l, true));
}
