/*
** my_str_isalpha.c for my_str_isalpha in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 16:05:58 2014 Louis Person
** Last update Fri Dec 26 16:51:10 2014 Louis Person
*/

#include <stdlib.h>

int	my_str_isalpha(const char *str)
{
  int	c;
  int	is_alpha;

  is_alpha = 1;
  c = 0;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[c] != '\0' && is_alpha)
  {
    if (!(str[c] >= 'A' && str[c] <= 'z'))
      is_alpha = 0;
    c++;
  }
  return (is_alpha);
}
