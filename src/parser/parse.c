/*
** parse.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 15:23:21 2015 Brendan Rius
** Last update Sat May 23 21:11:17 2015 Brendan Rius
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "my/my.h"
#include "parser/parser.h"
#include "tokenizer/token.h"
#include "ast.h"

int			parse(struct s_vec *tokens, struct s_btree **astptr)
{
  struct s_btree	*root;
  struct s_iterator	itokens;

  assert(tokens != NULL);
  itokens = vec_iterator(tokens);
  itokens = vec_iterator(tokens);
  if (btree_new(&root) == -1)
    return (-1);
  btree_init(root, NULL, NULL, NULL);
  btree_root(root);
  if (parse_exp_complete_l2(&itokens, root) == -1)
    return (-1);
  *astptr = root;
  return (0);
}
