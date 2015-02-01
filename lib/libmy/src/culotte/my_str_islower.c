/*
** my_str_islower.c for my_str_islower in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 16:22:43 2014 Louis Person
** Last update Mon Oct  6 16:27:42 2014 Louis Person
*/

#include <stdlib.h>

int	my_str_islower(const char *str)
{
  int	c;
  int	is_lower;

  c = 0;
  is_lower = 1;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[c] != '\0' && is_lower)
  {
    if (!(str[c] >= 'a' && str[c] <= 'z'))
      is_lower = 0;
    c++;
  }
  return (is_lower);
}
