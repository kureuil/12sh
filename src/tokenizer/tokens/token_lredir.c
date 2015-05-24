/*
** token_lredir.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 08:55:23 2015 Brendan Rius
** Last update Sun May  3 14:54:55 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

/*
** @TESTABLE
*/

ssize_t	parse_token_lredir(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (s[0] != '<')
    return (0);
  t->type = TT_LREDIR;
  return (string_init_from_nbytes(&(t->string), s, 1) == -1 ? -1 : 1);
}
