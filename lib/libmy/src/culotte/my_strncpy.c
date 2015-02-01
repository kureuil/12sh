/*
** my_strncpy.c for my_strncpy in /home/person_l/rendu/Piscine_C_J06
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 11:30:47 2014 Louis Person
** Last update Fri Oct 10 18:26:31 2014 Louis Person
*/

#include <stdlib.h>

char	*my_strncpy(char *dest, const char *src, int n)
{
  int	c;

  c = 0;
  if (dest == NULL)
    return (NULL);
  if (src != NULL)
  {
    while (c < n && src[c] != '\0')
    {
      dest[c] = src[c];
      c++;
    }
    while (c < n)
    {
      dest[c] = '\0';
      c++;
    }
  }
  return (dest);
}
