/*
** my_is_in.c for libmy in /home/person_l/projets/libmy/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Fri Nov  14 17:59:08 2014 Louis Person
** Last update Fri Dec 26 16:50:06 2014 Louis Person
*/

#include <stdlib.h>

int	my_is_in(const char *str, const char c)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i + 1);
      i++;
    }
  return (0);
}
