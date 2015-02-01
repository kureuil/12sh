/*
** my_puterr.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sat Jan 17 15:57:51 2015 Louis Person
** Last update Sat Jan 17 16:04:35 2015 Louis Person
*/

#include "my.h"

int	my_puterr(const char *str)
{
  int	written;
  
  my_dputstr(2, "\033[91m");
  written = my_dputstr(2, str);
  my_dputstr(2, "\033[0m");
  return (written);
}
