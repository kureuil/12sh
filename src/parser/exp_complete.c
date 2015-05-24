/*
** exp_complete.c for 42sh in /home/brendan/rendu/42sh/src/parser
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 21:55:26 2015 Brendan Rius
** Last update Sat May 23 02:35:43 2015 Brendan Rius
*/

#include <stdio.h>
#include "tokenizer/token.h"
#include "my/my.h"
#include "parser/parser.h"
#include "ast.h"

static int		parse_complementary(struct s_iterator *i,
					    struct s_btree *node,
					    struct s_ast_node *ast)
{
  struct s_token	*token;
  struct s_btree	*right;

  if (!HAS_NEXT(i))
    return (0);
  token = PEEK(i);
  if (token->type == TT_PIPE)
    {
      (void) NEXT(i);
      if (!HAS_NEXT(i))
	return (fprintf(stderr, "error (l0): ran out of tokens\n"), -1);
      ast->type = TPIPE;
      if (btree_new(&right) == -1)
	return (-1);
      btree_init(right, NULL, NULL, NULL);
      btree_set_tree(node, RIGHT, right);
      return (parse_exp_complete(i, right));
    }
  return (0);
}

int			parse_exp_complete(struct s_iterator *i,
					   struct s_btree *node)
{
  struct s_btree	*left;
  struct s_ast_node	*ast;

  if (ast_node_new(&ast) != 0)
    return (fprintf(stderr, "error (l0): cannot create ast\n"), -1);
  ast->type = TEMPTY;
  btree_set(node, ast);

  if (btree_new(&left) != 0)
    return (-1);
  btree_init(left, NULL, NULL, NULL);
  btree_set_tree(node, LEFT, left);
  if (parse_exp_simple(i, left) != 0)
    return (-1);
  return (parse_complementary(i, node, ast));
}
