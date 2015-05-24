/*
** exp_redir.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon May 18 20:01:27 2015 Brendan Rius
** Last update Sun May 24 17:35:45 2015 Brendan Rius
*/

#include <stdlib.h>
#include <stdio.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "my/my.h"
#include "parser/parser.h"
#include "ast.h"

int			parse_exp_redir(struct s_iterator *i,
					struct s_btree *node)
{
  struct s_token	*t;

  if (HAS_NEXT(i))
    {
      t = PEEK(i);
      if (t->type == TT_RREDIR)
	return (parse_exp_rredir(i, node));
      else if (t->type == TT_DRREDIR)
	return (parse_exp_drredir(i, node));
      else if (t->type == TT_LREDIR)
	return (parse_exp_lredir(i, node));
      else if (t->type == TT_DLREDIR)
	return (parse_exp_dlredir(i, node));
      else if (t->type == TT_TLREDIR)
	return (parse_exp_tlredir(i, node));
      else
	return (fprintf(stderr, "error: unexpected token \"%s\"\n",
			t->string._string), -1);
    }
  return (0);
}
