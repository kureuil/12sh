/*
** my_strcat.c for my_strcat in /home/person_l/rendu/Piscine_C_J07/ex_01
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Tue Oct  7 23:24:30 2014 Louis Person
** Last update Wed Oct  8 14:07:30 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, const char *src)
{
  int	dest_len;
  int	src_len;
  int	c;

  c = 0;
  if (src == NULL)
    return (dest);
  if (dest == NULL)
    return (NULL);
  dest_len = my_strlen(dest);
  src_len = my_strlen(src);
  while (c < src_len)
  {
    dest[c + dest_len] = src[c];
    c++;
  }
  dest[dest_len + c] = '\0';
  return (dest);
}
