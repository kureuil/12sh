/*
** exp_complete_l2.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May 22 23:38:59 2015 Louis Person
** Last update Sun May 24 16:46:33 2015 Brendan Rius
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
  if (token->type == TT_SEMICOLON)
    {
      (void) NEXT(i);
      if (!HAS_NEXT(i))
	return (0);
      ast->type = TCOMPOSE;
      if (btree_new(&right) == -1)
	return (-1);
      btree_init(right, NULL, NULL, NULL);
      btree_set_tree(node, RIGHT, right);
      return (parse_exp_complete_l2(i, right));
    }
  return (0);
}
int			parse_exp_complete_l2(struct s_iterator *i,
					      struct s_btree *node)
{
  struct s_btree	*left;
  struct s_ast_node	*ast;

  if (ast_node_new(&ast) != 0)
    return (fprintf(stderr, "error (l2): cannot create ast\n"), -1);
  ast->type = TEMPTY;
  btree_set(node, ast);
  if (btree_new(&left) != 0)
    return (-1);
  btree_init(left, NULL, NULL, NULL);
  btree_set_tree(node, LEFT, left);
  if (parse_exp_complete_l1(i, left) != 0)
    return (-1);
  return (parse_complementary(i, node, ast));
}
