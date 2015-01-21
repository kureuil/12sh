/*
** error.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:18:16 2015 Louis Person
** Last update Thu Jan 22 00:23:45 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	handle_error(t_error err, t_darray *command)
{
  my_putstr("Errno: ");
  my_putnbr(err);
  my_putchar('\n');
  exit(err);
}

