/*
** lexer.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 09:39:12 2015 Louis Person
** Last update Fri Jan 30 12:13:10 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "char.h"
#include "lexer.h"

void	nofree(void *ptr)
{
  ptr = NULL;
  return;
}

t_token		*get_next_token(char **str, t_darray *grammar)
{
  int		i;
  t_token	*(*callback)(char **);
  t_token	*token;

  skip_whitespace(str);
  i = -1;
  token = NULL;
  while (++i < grammar->current_size)
    {
      callback = grammar->data[i];
      token = callback(str);
      if (token != NULL)
	break;
    }
  return (token);
}

t_queue		*tokenize(char *input, int len)
{
  t_queue	*tokens;
  t_darray	*grammar;
  t_token	*tmp;
  char		*start;
  
  if (queue_new(&tokens, &nofree) != OK)
    return (NULL);
  if (lexicon(&grammar) == -1)
    return (NULL);
  start = input;
  while ((tmp = get_next_token(&input, grammar)) != NULL)
    {
      tokens->add(tokens, tmp);
      if ((input - start) > len)
	break;
    }
  free_dynamo(grammar);
  return (tokens);
}
