/*
** eof.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:00:51 2015 Louis Person
** Last update Thu Jan 29 21:01:16 2015 Louis Person
*/

#include <stdlib.h>
#include "lexer.h"

t_token		*grammar_eof(char **str)
{
  t_token	*res;
  
  res = NULL;
  if (**str == '\0')
    {
      if (token_new(&res) == -1)
	return (NULL);
      (*str)++;
      res->type = T_EOF;
      res->value = NULL;
    }
  return (res);
}
