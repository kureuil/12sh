/*
** my_strncmp.c for my_strncmp in /home/person_l/rendu/Piscine_C_J06/ex_04
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 15:17:28 2014 Louis Person
** Last update Sun Oct 12 07:43:07 2014 Louis Person
*/

#include <stdlib.h>

int	my_strncmp(const char *str1, const char *str2, int n)
{
  int	result;
  int	c;

  c = 0;
  result = 0;
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (str1[c] != '\0' && str2[c] != '\0' && result == 0 && c < n)
  {
    if (str1[c] > str2[c])
      result = 1;
    else if (str1[c] < str2[c])
      result = -1;
    c++;
  }
  return (result);
}
