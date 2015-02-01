/*
** my_strndup.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 23:58:43 2014 Louis Person
** Last update Sat Dec  27 23:58:43 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(const char *src, int n)
{
  int	c;
  char	*str;

  c = 0;
  if (src == NULL)
    return (NULL);
  if ((str = malloc(n + 1)) == NULL)
    return (NULL);
  while (c < n && src[c] != '\0')
  {
    str[c] = src[c];
    c++;
  }
  str[c] = '\0';
  return (str);
}
