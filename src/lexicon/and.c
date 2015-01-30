/*
** and.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 20:16:26 2015 Louis Person
** Last update Thu Jan 29 21:00:20 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

t_token		*grammar_and(char **str)
{
  t_token	*res;

  res = NULL;
  if (my_strncmp("&&", (*str), 2))
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_AND;
  res->value = NULL;
  *str += 2;
  return (res);
}
