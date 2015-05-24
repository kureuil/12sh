/*
** interpreter_empty.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu May 21 03:49:44 2015 Louis Person
** Last update Sat May 23 18:15:26 2015 Louis Person
*/

#include <stdlib.h>
#include "interpreter/interpreter.h"
#include "ast.h"
#include "my/my.h"

int			interpret_empty(t_interpreter *interpreters,
					struct s_shell *shell,
					struct s_btree *tnode)
{
  struct s_ast_node	*node;

  if (tnode->left != NULL)
    {
      node = (struct s_ast_node *)tnode->left->data;
      if (interpreters[node->type](interpreters, shell, tnode->left) == -1)
	return (-1);
    }
  if (tnode->right != NULL)
    {
      node = (struct s_ast_node *)tnode->right->data;
      if (interpreters[node->type](interpreters, shell, tnode->left) == -1)
	return (-1);
    }
  return (0);
}
