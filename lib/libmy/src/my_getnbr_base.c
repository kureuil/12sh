/*
** my_getnbr_base.c for my_getnbr_base in /home/person_l/rendu/Piscine_C_J06/ex_16
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 19:38:44 2014 Louis Person
** Last update Sun Nov 16 03:43:41 2014 Louis Person
*/

#include "my.h"

int	my_getnbr_base(const char *str, const char *base)
{
  int	value;
  int	sign;
  int	blen;
  int	nb;
  int	c;

  sign = 1;
  nb = c = 0;
  if ((blen = my_strlen(base)) == 0)
    return (0);
  while (str[c] == '+' || str[c] == '-')
    sign *= (str[c++]  == '-' ? -1 : 1);
  while ((value = my_is_in(base, str[c])))
  {
    if (nb < (-2147483648 / blen) || nb > (2147483647 / blen))
      return (0);
    nb *= blen;
    if (nb < -2147483648 + (value - 1) || nb > 2147483647 - (value - 1))
      return (0);
    nb += ((value - 1) * sign);
    c++;
  }
  return (nb);
}
