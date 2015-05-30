/*
** check_ast.c for 42sh in /home/brendan/rendu/42sh/src/interpreter
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat May 23 03:33:19 2015 Brendan Rius
** Last update Sat May 30 13:28:22 2015 Louis Person
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "interpreter/interpreter.h"
#include "my/my.h"
#include "ast.h"
#include "shell.h"

static bool		wrong_redirections_left(struct s_btree *tree)
{
  struct s_ast_node	*data;

  if (tree == NULL)
    return (false);
  data = tree->data;
  if (data->type == TCMD && data->value.cmd.lredir != NULL)
    return (true);
  else
    return (wrong_redirections_left(tree->left) ||
	    wrong_redirections_left(tree->right));
}

static bool		wrong_redirections_right(struct s_btree *tree)
{
  struct s_ast_node	*data;

  if (tree == NULL)
    return (false);
  data = tree->data;
  if (data->type == TCMD && data->value.cmd.rredir != NULL)
    return (true);
  else
    return (wrong_redirections_right(tree->left) ||
	    wrong_redirections_right(tree->right));
}

static bool		wrong_redirections(struct s_btree *tree)
{
  struct s_ast_node	*data;

  if (tree == NULL)
    return (false);
  data = tree->data;
  if (data->type == TPIPE)
    {
      if (wrong_redirections_right(tree->left))
	return (true);
      if (wrong_redirections_left(tree->right))
	return (true);
      return (false);
    }
  else
    return (wrong_redirections(tree->left) ||
	    wrong_redirections(tree->right));
}

bool			is_ast_valid(struct s_btree *tree)
{
  struct s_iterator	itree;
  struct s_ast_node	*node;
  struct s_iterator	veci;
  char			executable[255];

  itree = btree_iterator_dfl(tree);
  FOREACH(node IN &itree)
    {
      if (node == NULL || node->type != TCMD)
	continue;
      veci = vec_iterator(&(node->value.cmd.command));
      if (!HAS_NEXT(&veci))
	return (fprintf(stderr, "error: empty command\n"), false);
      if (find_executable(PEEK(&veci), executable, 255) != 0 &&
	  dict_get(sh_get()->builtins, PEEK(&veci)) == NULL)
	{
	  sh_return(sh_get(), EXIT_FAILURE);
	  return (fprintf(stderr,
			  "error: executable not found or not executable\n"),
		  false);
	}
    }
  if (wrong_redirections(tree))
    return (fprintf(stderr, "error: wrong redirections\n"), false);
  return (true);
}
