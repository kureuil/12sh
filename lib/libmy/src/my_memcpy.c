/*
** my_memcpy.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Thu Jan  8 16:20:16 2015 Louis Person
** Last update Thu Jan  8 16:20:16 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	*my_memcpy(void *dest, void *src, int n)
{
  int	c;

  c = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (c < n)
  {
    ((char *)dest)[c] = ((char *)src)[c];
    c++;
  }
  return (dest);
}
