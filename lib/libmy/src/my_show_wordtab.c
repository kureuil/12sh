/*
** my_show_wordtab.c for my_show_wordtab in /home/person_l/rendu/Piscine_C_J08/ex_04
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Oct  9 16:24:26 2014 Louis Person
** Last update Sun Nov 16 03:46:09 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	c;

  c = 0;
  while (tab[c] != '\0')
  {
    my_putstr(tab[c]);
    my_putchar('\n');
    c++;
  }
  return (0);
}
