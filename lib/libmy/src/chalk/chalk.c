/*
** chalk.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 16:1:23 2014 Louis Person
** Last update Sat Dec  27 16:1:23 2014 Louis Person
*/

#include "my.h"

void	chalk_red(char *str)
{
  my_putstr("\033[91m");
  my_putstr(str);
  my_putstr("\033[0m");
}

void	chalk_green(char *str)
{
  my_putstr("\033[92m");
  my_putstr(str);
  my_putstr("\033[0m");
}
