/*
** my_index_of.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 15:14:47 2014 Louis Person
** Last update Sun Dec  28 15:14:47 2014 Louis Person
*/

#include <stdlib.h>

int	index_of(const char c, const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
  {
    while (str[i] != '\0')
    {
      if (str[i] == c)
        return (i);
      i++;
    }
  }
  return (-1);
}
