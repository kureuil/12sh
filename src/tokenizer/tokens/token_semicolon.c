/*
** token_semicolon.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 09:30:15 2015 Brendan Rius
** Last update Sun May  3 14:59:30 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

/*
** @TESTABLE
*/

ssize_t	parse_token_semicolon(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (s[0] != ';')
    return (0);
  t->type = TT_SEMICOLON;
  return (string_init_from_nbytes(&(t->string), s, 1) == -1 ? -1 : 1);
}
