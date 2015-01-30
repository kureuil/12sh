/*
** or.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 20:23:02 2015 Louis Person
** Last update Thu Jan 29 20:28:33 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

t_token		*grammar_or(char **str)
{
  t_token	*res;

  res = NULL;
  if (my_strncmp("||", (*str), 2))
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_OR;
  res->value = NULL;
  *str += 2;
  return (res);
}
