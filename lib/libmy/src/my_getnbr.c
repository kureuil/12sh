/*
** my_getnbr.c for my_getnbr in /home/person_l/rendu/Piscine_C_J07/lib/my
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Oct  7 15:11:25 2014 Louis Person
** Last update Thu Jan 29 21:58:36 2015 Louis Person
*/

#include <stdlib.h>

int	my_getnbr(const char *str)
{
  int	sign;
  int	nb;
  int	c;

  sign = 1;
  nb = c = 0;
  if (str == NULL)
    return (0);
  while (str[c] == '+' || str[c] == '-')
    sign *= (str[c++]  == '-' ? -1 : 1);
  while (str[c] >= '0' && str[c] <= '9')
  {
    if (nb < (-2147483648 / 10) || nb > (2147483647 / 10))
      return (0);
    nb *= 10;
    if (nb < -2147483648 + (str[c] - '0') || nb > 2147483647 - (str[c] - '0'))
      return (0);
    nb += ((str[c] - '0') * sign);
    c++;
  }
  return (nb);
}
