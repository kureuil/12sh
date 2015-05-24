/*
** token_pipe.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 01:10:57 2015 Brendan Rius
** Last update Fri May 22 20:31:31 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

/*
** @TESTABLE
*/

ssize_t	parse_token_pipe(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (s[0] != '|')
    return (0);
  t->type = TT_PIPE;
  return (string_init_from_nbytes(&(t->string), s, 1) == -1 ? -1 : 1);
}
