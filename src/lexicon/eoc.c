/*
** eoc.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:01:45 2015 Louis Person
** Last update Thu Jan 29 21:01:58 2015 Louis Person
*/

#include <stdlib.h>
#include "lexer.h"

t_token		*grammar_eoc(char **str)
{
  t_token	*res;
  
  res = NULL;
  if (**str == '\n' || **str == ';')
    {
      if (token_new(&res) == -1)
	return (NULL);
      (*str)++;
      res->type = T_EOC;
      res->value = NULL;
    }
  return (res);
}

