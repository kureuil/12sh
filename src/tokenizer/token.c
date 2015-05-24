/*
** token.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 10:26:25 2015 Brendan Rius
** Last update Thu May 14 19:46:11 2015 Antoine Ouvrans
*/

#include <stdlib.h>
#include <assert.h>
#include "tokenizer/token.h"
#include "error.h"
#include "my/my.h"

/*
** @TESTABLE
*/

int			token_new(struct s_token **token_ptr)
{
  struct s_token	*t;

  assert(token_ptr != NULL);
  t = malloc(sizeof(*t));
  if (t == NULL)
    return (my_error(E_CANNOTMALLOC));
  *token_ptr = t;
  return (0);
}

int	token_init(struct s_token *token)
{
  assert(token != NULL);
  return (string_init(&(token->string)));
}

void	token_free(struct s_token *token)
{
  assert(token != NULL);
  free(token);
}
