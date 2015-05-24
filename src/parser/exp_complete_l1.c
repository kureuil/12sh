/*
** exp_complete_l1.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May 22 20:16:06 2015 Louis Person
** Last update Sat May 23 02:41:07 2015 Brendan Rius
*/

#include <stdio.h>
#include "tokenizer/token.h"
#include "my/my.h"
#include "parser/parser.h"
#include "ast.h"

static int		parse_complementary_orif(struct s_iterator *i,
						 struct s_btree *node,
						 struct s_ast_node *ast)
{
  struct s_btree	*right;

  (void) NEXT(i);
  if (!HAS_NEXT(i))
    return (fprintf(stderr, "error (l1): ran out of tokens\n"), -1);
  ast->type = TORIF;
  if (btree_new(&right) == -1)
    return (-1);
  btree_init(right, NULL, NULL, NULL);
  btree_set_tree(node, RIGHT, right);
  return (parse_exp_complete_l1(i, right));
}

static int		parse_complementary_andif(struct s_iterator *i,
						  struct s_btree *node,
						  struct s_ast_node *ast)
{
  struct s_btree	*right;

  (void) NEXT(i);
  if (!HAS_NEXT(i))
    return (fprintf(stderr, "error (l1): ran out of tokens\n"), -1);
  ast->type = TANDIF;
  if (btree_new(&right) == -1)
    return (-1);
  btree_init(right, NULL, NULL, NULL);
  btree_set_tree(node, RIGHT, right);
  return (parse_exp_complete_l1(i, right));
}

int			parse_exp_complete_l1(struct s_iterator *i,
					      struct s_btree *node)
{
  struct s_btree	*left;
  struct s_token	*token;
  struct s_ast_node	*ast;

  if (ast_node_new(&ast) != 0)
    return (fprintf(stderr, "error (l1): cannot create ast\n"), -1);
  ast->type = TEMPTY;
  btree_set(node, ast);
  if (btree_new(&left) != 0)
    return (-1);
  btree_init(left, NULL, NULL, NULL);
  btree_set_tree(node, LEFT, left);
  if (parse_exp_complete(i, left) != 0)
    return (-1);
  if (!HAS_NEXT(i))
    return (0);
  token = PEEK(i);
  if (token->type == TT_ORIF)
    return (parse_complementary_orif(i, node, ast));
  else if (token->type == TT_ANDIF)
    return (parse_complementary_andif(i, node, ast));
  return (0);
}
