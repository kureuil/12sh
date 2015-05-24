/*
** interpreter_empty.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 18:21:22 2015 Louis Person
** Last update Sat May 23 17:41:43 2015 Louis Person
*/

#include <stdlib.h>
#include "interpreter/interpreter.h"
#include "my/my.h"
#include "ast.h"
#include "shell.h"

int			interpret_orif(t_interpreter *interpreters,
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
  if (shell->returnvalue != 0 && tnode->right != NULL)
    {
      node = (struct s_ast_node *)tnode->right->data;
      if (interpreters[node->type](interpreters, shell, tnode->right) == -1)
	return (-1);
    }
  return (0);
}
