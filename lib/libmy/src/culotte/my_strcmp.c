/*
** my_strcmp.c for my_strcmp in /home/person_l/rendu/Piscine_C_J06/ex_04
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 15:06:59 2014 Louis Person
** Last update Wed Oct  8 11:37:31 2014 Louis Person
*/

#include <stdlib.h>

int	my_strcmp(const char *str1, const char *str2)
{
  int	result;
  int	c;

  c = result = 0;
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (str1[c] == str2[c])
  {
    if (str1[c] == '\0')
      return (0);
    c++;
  }
  if (str1[c] < str2[c])
    return (-1);
  else
    return (1);
}
