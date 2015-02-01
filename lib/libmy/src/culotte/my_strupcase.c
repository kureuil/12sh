/*
** my_strupcase.c for my_strupcase in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 15:22:30 2014 Louis Person
** Last update Mon Oct  6 15:50:25 2014 Louis Person
*/

#include <stdlib.h>

char	*my_strupcase(char *str)
{
  int	c;

  c = 0;
  if (str == NULL)
    return (NULL);
  while (str[c] != '\0')
  {
    if (str[c] >= 'a' && str[c] <= 'z')
      str[c] -= ('a' - 'A');
    c++;
  }
  return (str);
}
