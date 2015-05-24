/*
** exp_simple.c for 42sh in /home/brendan/rendu/42sh/src/parser
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 22:00:39 2015 Brendan Rius
** Last update Sun May 24 20:19:24 2015 Brendan Rius
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "my/my.h"
#include "parser/parser.h"
#include "ast.h"

static int	ast_init_node_cmd(struct s_ast_node *payload)
{
  assert(payload != NULL);
  payload->type = TCMD;
  payload->value.cmd.rredir = NULL;
  payload->value.cmd.lredir = NULL;
  payload->value.cmd.rtype = RT_RUNKNOWN;
  payload->value.cmd.ltype = RT_LUNKNOWN;
  if (vec_init(&(payload->value.cmd.command), 0, &free) != 0)
    return (-1);
  return (0);
}

static int		eat_tokens(struct s_iterator *i,
				   struct s_btree *node,
				   struct s_ast_node *payload)
{
  struct s_token	*t;
  char			*cmdcopy;

  while (HAS_NEXT(i))
    {
      t = PEEK(i);
      if (t->type == TT_STRING)
	{
	  (void) NEXT(i);
	  if ((cmdcopy = strdup(t->string._string)) == NULL)
	    return (fprintf(stderr, "strdup failed\n"), -1);
	  if (vec_push(&(payload->value.cmd.command), cmdcopy) != 0)
	    return (fprintf(stderr, "cannot push to vector\n"), -1);
	}
      else if (t->type == TT_RREDIR || t->type == TT_DRREDIR ||
	       t->type == TT_LREDIR || t->type == TT_DLREDIR ||
	       t->type == TT_TLREDIR)
	{
	  if (parse_exp_redir(i, node) != 0)
	    return (-1);
	}
      else
	return (0);
    }
  return (0);
}

int			parse_exp_simple(struct s_iterator *i,
					 struct s_btree *node)
{
  struct s_token	*t;
  struct s_ast_node	*payload;

  if (!HAS_NEXT(i))
    return (fprintf(stderr,
		    "error: expected command, ran out of tokens\n"), -1);
  t = PEEK(i);
  if (!(t->type == TT_STRING || t->type == TT_RREDIR ||
	t->type == TT_DRREDIR || t->type == TT_LREDIR ||
	t->type == TT_DLREDIR || t->type == TT_TLREDIR))
    return (fprintf(stderr,
		    "error: expected command, found \"%s\"\n",
		    t->string._string), -1);
  if (ast_node_new(&payload) == -1)
    return (-1);
  if (ast_init_node_cmd(payload) != 0)
    return (fprintf(stderr, "error: cannot create init command\n"), -1);
  btree_set(node, payload);
  return (eat_tokens(i, node, payload));
}
