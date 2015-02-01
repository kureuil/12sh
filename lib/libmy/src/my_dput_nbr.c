/*
** my_dput_nbr.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Nov 17 14:22:24 2014 Louis Person
** Last update Tue Nov 18 11:32:54 2014 Louis Person
*/

#include "my.h"

int	my_dput_nbr(int fd, int n)
{
  return (my_dputnbr_base(fd, n, "0123456789"));
}
