/*
** my_put_nbr2.c for my_put_nbr in /home/person_l/rendu/Piscine_C_J03
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Wed Oct  1 21:58:57 2014 Louis Person
** Last update Mon Nov 17 14:21:51 2014 Louis Person
*/

#include "my.h"

int	my_put_nbr(int n)
{
  return (my_dputnbr_base(1, n, "0123456789"));
}

int	my_putnbr(int n)
{
  return (my_put_nbr(n));
}
