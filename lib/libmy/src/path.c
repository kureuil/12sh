/*
** path.c<2> for libmy in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 00:11:13 2015 Louis Person
** Last update Thu Jan 29 00:11:27 2015 Louis Person
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
  my_strcpy(res, base);
  my_strncat(res, "/", 1);
  my_strncat(res, add, alen);
  return (res);
}
