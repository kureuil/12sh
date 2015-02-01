/*
** my_dputstr.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Nov 17 14:38:20 2014 Louis Person
** Last update Tue Nov 18 11:32:25 2014 Louis Person
*/

#include <unistd.h>
#include "my.h"

int	my_dputstr(int fd, const char *str)
{
  return (write(fd, str, my_strlen(str)));
}
