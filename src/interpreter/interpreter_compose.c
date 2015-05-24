/*
** interpreter_empty.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 18:21:22 2015 Louis Person
** Last update Sun May 24 09:59:13 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include "my/my.h"
#include "shell.h"
#include "interpreter/interpreter.h"
#include "ast.h"

int			interpret_compose(t_interpreter *interpreters,
					  struct s_shell *shell,
					  struct s_btree *tnode)
{
  struct s_ast_node	*node;

  assert(tnode != NULL);
  shell->child = 0;
  if (tnode->left != NULL)
    {
      node = (struct s_ast_node *)tnode->left->data;
      if (interpreters[node->type](interpreters, shell, tnode->left) == -1)
	return (-1);
    }
  command_supervisor(shell, shell->child);
  if (tnode->right != NULL)
    {
      node = (struct s_ast_node *)tnode->right->data;
      if (interpreters[node->type](interpreters, shell, tnode->right) == -1)
	return (-1);
    }
  return (0);
}
