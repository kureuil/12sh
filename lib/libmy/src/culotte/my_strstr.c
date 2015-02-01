/*
** my_strstr.c for my_strstr in /home/person_l/rendu/Piscine_C_J06
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 13:45:27 2014 Louis Person
** Last update Tue Oct  7 15:20:55 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_strstr(char *haystack, char *needle)
{
  int	nee_len;
  int	cur_pos;
  int	range;

  nee_len = my_strlen(needle);
  range = my_strlen(haystack) - nee_len;
  cur_pos = 0;
  while (cur_pos <= range)
  {
    if (!my_strncmp(haystack + cur_pos, needle, nee_len))
      return (haystack + cur_pos);
    cur_pos++;
  }
  return (NULL);
}
