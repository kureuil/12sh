/*
** my_str_trim.c for libmy in /home/person_l/rendu/common/my
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Wed Oct 15 17:20:59 2014 Louis Person
** Last update Wed Oct 15 17:21:02 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*my_str_trim(const char *str)
{
  int	c;
  int	len;
  char	*trimmed;

  c = 0;
  if (str == NULL)
    return (NULL);
  while (my_char_iswordsep(str[c]))
    c++;
  trimmed = my_strdup(str + c);
  len = my_strlen(trimmed) - 1;
  c = 0;
  while (my_char_iswordsep(trimmed[len - c]))
  {
    trimmed[len - c] = '\0';
    c++;
  }
  return (trimmed);
}
