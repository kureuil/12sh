/*
** redirections.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 11:36:41 2015 Louis Person
** Last update Fri Jan 30 11:38:28 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

t_token		*grammar_lredir(char **str)
{
  t_token	*res;

  res = NULL;
  if (my_strncmp(">", *str, 1))
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_LREDIR;
  res->value = NULL;
  return (res);
}
