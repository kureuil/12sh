/*
** token_andif.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 09:22:26 2015 Brendan Rius
** Last update Thu May 14 20:34:47 2015 Brendan Rius
*/

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

/*
** @TESTABLE
*/

ssize_t	parse_token_andif(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (strncmp(s, "&&", 2) != 0)
    return (0);
  t->type = TT_ANDIF;
  return (string_init_from_nbytes(&(t->string), s, 2) != 0 ? -1 : 2);
}
