/*
** my_strcount.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 13:35:56 2014 Louis Person
** Last update Sat Dec  27 13:35:56 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	my_strcount(char *haystack, char *needle)
{
  int	nb;
  char	*src;

  nb = 0;
  src = haystack;
  if (haystack == NULL || needle == NULL || needle[0] == '\0')
    return (0);
  while ((src = my_strstr(src, needle)) != NULL)
  {
    nb += 1;
    src += 1;
  }
  return (nb);
}
