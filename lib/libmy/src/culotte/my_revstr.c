/*
** my_revstr.c for my_revstr in /home/person_l/rendu/Piscine_C_J06
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Oct  6 11:54:37 2014 Louis Person
** Last update Tue Oct  7 15:19:48 2014 Louis Person
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	str_pos;
  int	size;
  char	tmp;

  str_pos = 0;
  size = my_strlen(str) - 1;
  while (size - str_pos >= 1)
  {
    tmp = str[str_pos];
    str[str_pos] = str[size];
    str[size] = tmp;
    size--;
    str_pos++;
  }
  return (str);
}
