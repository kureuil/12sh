/*
** env.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Wed Jan  7 18:55:1 2015 Louis Person
** Last update Sat Jan 10 18:38:44 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_getenv(char **envp, const char *key)
{
  int	c;
  int	len;
  char	*index;
  char	*res;

  c = 0;
  res = NULL;
  if ((index = malloc(my_strlen(key) + 2)) == NULL)
    return (NULL);
  my_strcpy(index, key);
  my_strcat(index, "=");
  while (envp[c] != NULL && res == NULL)
  {
    len = my_strlen(index);
    if (my_strncmp(envp[c], index, len) == 0)
      res = envp[c] + len;
    c++;
  }
  free(index);
  return (res);
}
