/*
** my_strdup.c for my_strdup in /home/person_l/rendu/Piscine_C_J08/ex_01
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Wed Oct  8 14:22:36 2014 Louis Person
** Last update Sat Jan 17 15:46:54 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *src)
{
  int	len;
  int	c;
  char	*str;

  c = 0;
  if (src == NULL)
    return (NULL);
  len = my_strlen(src) + 1;
  if (len == 1)
    return (NULL);
  if ((str = malloc(len)) == NULL)
    return (NULL);
  while (c < len)
  {
    str[c] = src[c];
    c++;
  }
  return (str);
}
