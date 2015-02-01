/*
** my_strlowcase.c for my_strlowcase in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 15:51:55 2014 Louis Person
** Last update Mon Oct  6 15:52:34 2014 Louis Person
*/

#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int	c;

  c = 0;
  if (str == NULL)
    return (NULL);
  while (str[c] != '\0')
  {
    if (str[c] >= 'A' && str[c] <= 'Z')
      str[c] += ('a' - 'A');
    c++;
  }
  return (str);
}
