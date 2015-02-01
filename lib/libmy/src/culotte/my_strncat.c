/*
** my_strncat.c for my_strncat.c in /home/person_l/rendu/Piscine_C_J07/ex_01
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Tue Oct  7 23:34:25 2014 Louis Person
** Last update Sun Jan 18 12:58:26 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strncat(char *dest, const char *src, int n)
{
  int	dest_len;
  int	c;

  c = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  dest_len = my_strlen(dest);
  while (src[c] != '\0' && c < n)
  {
    dest[c + dest_len] = src[c];
    c++;
  }
  dest[dest_len + c] = '\0';
  return (dest);
}
