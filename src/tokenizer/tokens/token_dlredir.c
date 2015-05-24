/*
** token_dlredir.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 09:03:14 2015 Brendan Rius
** Last update Thu May 14 20:33:08 2015 Brendan Rius
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

ssize_t	parse_token_dlredir(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (strncmp(s, "<<", 2) != 0)
    return (0);
  t->type = TT_DLREDIR;
  return (string_init_from_nbytes(&(t->string), s, 2) == -1 ? -1 : 2);
}
