/*
** path.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:19:20 2015 Louis Person
** Last update Thu Jan 22 00:24:06 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*path(char *base, char *add)
{
  int	blen;
  int	alen;
  char	*res;

  blen = my_strlen(base);
  alen = my_strlen(add);
  if ((res = malloc(blen + alen + 2)) == NULL)
    return (NULL);
  res[0] = '\0';
  my_strncpy(res, base, blen);
  my_strncat(res, "/", 1);
  my_strncat(res, add, alen);
  return (res);
}
