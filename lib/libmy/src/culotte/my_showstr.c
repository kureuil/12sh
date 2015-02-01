/*
** my_showstr.c for my_showstr in /home/person_l/rendu/Piscine_C_J06/ex_17
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Oct  7 09:03:23 2014 Louis Person
** Last update Fri Dec 26 16:50:41 2014 Louis Person
*/

#include "my.h"

int	my_showstr(const char *str)
{
  int   cursor;
  int   len;

  cursor = 0;
  len = my_strlen(str);
  if (str[cursor] == '\0')
    return (0);
  while (str[cursor] != '\0')
  {
    if (!my_char_isprintable(str[cursor]))
    {
      my_putstr("\\0");
      my_putnbr_base((int) str[cursor], "01234567");
    }
    else
      my_putchar(str[cursor]);
  }
  return (len);
}
