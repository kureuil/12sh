/*
** my_strsplit.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 13:28:45 2014 Louis Person
** Last update Tue Jan 20 14:28:30 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	**my_strsplit(char *src, char *sep)
{
  char  **res;
  int	occurences;
  int	c;
  char	*copy;
  char	*copy_addr;
  char	*tok;

  occurences = my_strcount(src, sep);
  if ((res = malloc(sizeof(char *) * (occurences + 2))) == NULL)
    return (NULL);
  copy_addr = copy = my_strdup(src);
  c = 0;
  while ((tok = my_strsep(&copy, sep)) != NULL)
  {
    if (my_strlen(tok) == 0)
      {
	free(tok);
	continue;
      }
    res[c] = tok;
    c++;
  }
  res[c] = NULL;
  free(copy_addr);
  return (res);
}
