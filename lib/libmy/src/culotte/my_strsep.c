/*
** my_strsep.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 0:20:34 2014 Louis Person
** Last update Sun Dec  28 0:20:34 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strsep(char **stringp, const char *delim)
{
  int	pos;
  int	delim_len;
  char	*res;

  if (stringp == NULL || *stringp == NULL)
    return (NULL);
  delim_len = my_strlen(delim);
  pos = 0;
  if (delim == NULL)
    pos = my_strlen(*stringp);
  while (my_strncmp(*stringp + pos, delim, delim_len))
    pos++;
  if ((*stringp)[pos] == '\0')
  {
    res = my_strdup(*stringp);
    *stringp = NULL;
  }
  else
  {
    res = my_strndup(*stringp, pos);
    *stringp += (pos + delim_len);
  }
  return (res);
}
