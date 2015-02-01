/*
** my_str_isnum.c for my_str_isnum in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 16:20:22 2014 Louis Person
** Last update Fri Dec 26 16:51:39 2014 Louis Person
*/

#include <stdlib.h>

int	my_str_isnum(const char *str)
{
  int	c;
  int	is_num;

  is_num = 1;
  c = 0;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[c] != '\0' && is_num)
  {
    if (!(str[c] >= '0' && str[c] <= '9'))
      is_num = 0;
    c++;
  }
  return (is_num);
}
