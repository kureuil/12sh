/*
** or.c<3> for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:16:51 2015 Louis Person
** Last update Thu Jan 29 21:41:41 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "shell.h"

t_error	behavior_or(t_token *token, t_shell *shell, t_tree *node)
{
  token = NULL;
  if (shell->status == 0)
    {
      tree_free_fn(node->left, &token_delete);
      node->left = NULL;
    }
  return (OK);
}
