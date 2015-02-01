/*
** my_str_isupper.c for my_str_isupper in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 16:29:43 2014 Louis Person
** Last update Mon Oct  6 16:33:16 2014 Louis Person
*/

#include <stdlib.h>

int	my_str_isupper(const char *str)
{
  int	c;
  int	is_upper;

  c = 0;
  is_upper = 1;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[c] != '\0' && is_upper)
  {
    if (!(str[c] >= 'A' && str[c] <= 'Z'))
      is_upper = 0;
    c++;
  }
  return (is_upper);
}
