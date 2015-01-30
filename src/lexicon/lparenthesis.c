/*
** lparenthesis.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 09:46:40 2015 Louis Person
** Last update Fri Jan 30 10:27:00 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

t_token		*grammar_lparenthesis(char **str)
{
  t_token	*res;

  res = NULL;
  if (**str != '(')
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_LPARENTHESIS;
  res->value = NULL;
  *str += 1;
  return (res);
}
