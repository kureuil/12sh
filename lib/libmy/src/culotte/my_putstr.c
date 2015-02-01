/*
** my_putstr.c for my_putstr in /home/person_l/rendu/Piscine_C_J09
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Thu Oct  9 18:20:53 2014 Louis Person
** Last update Fri Dec 26 16:49:40 2014 Louis Person
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(const char *str)
{
  return (write(1, str, my_strlen(str)));
}
