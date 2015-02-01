/*
** get_nbr_len.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sun Nov 16 03:29:29 2014 Louis Person
** Last update Sun Nov 16 20:27:27 2014 Louis Person
*/

#include "my.h"

int		get_nbr_len(int nb)
{
  int		power;
  unsigned int	copy;

  power = 0;
  copy = nb < 0 ? nb * -1 : nb;
  while ((unsigned int)(my_pow(10, power)) < copy)
    power++;
  return (power - 1);
}
