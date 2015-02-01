/*
** my_strcpy.c for my_strcpy in /home/person_l/rendu/Piscine_C_J06
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 09:26:05 2014 Louis Person
** Last update Mon Oct  6 11:00:13 2014 Louis Person
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, const char *src)
{
  int	c;

  c = 0;
  if (dest == NULL)
    return (NULL);
  if (src != NULL)
  {
    while (src[c] != '\0')
    {
      dest[c] = src[c];
      c++;
    }
  }
  dest[c] = '\0';
  return (dest);
}
