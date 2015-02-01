/*
** my_str_isprintable.c for my_str_isprintable in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 17:00:01 2014 Louis Person
** Last update Tue Oct  7 09:18:01 2014 Louis Person
*/

#include <stdlib.h>

int	my_str_isprintable(const char *str)
{
  int	c;
  int	is_printable;

  c = 0;
  is_printable = 1;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[c] != '\0' && is_printable)
  {
    if (!(str[c] >= ' ' && str[c] <= '~'))
      is_printable = 0;
    c++;
  }
  return (is_printable);
}
