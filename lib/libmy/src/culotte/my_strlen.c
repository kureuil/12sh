/*
** my_strlen.c for my_strlen in /home/person_l/rendu/Piscine_C_J07/lib/my
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Tue Oct  7 15:18:26 2014 Louis Person
** Last update Fri Dec 26 16:51:54 2014 Louis Person
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	c;

  c = 0;
  if (str != NULL)
  {
    while (str[c] != '\0')
      c++;
  }
  return (c);
}
