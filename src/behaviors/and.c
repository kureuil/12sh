/*
** and.c<3> for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:16:00 2015 Louis Person
** Last update Thu Jan 29 21:36:39 2015 Louis Person
*/

#include "my.h"
#include "lexer.h"
#include "shell.h"

t_error	behavior_and(t_token *token, t_shell *shell, t_tree *node)
{
  token = NULL;
  if (shell->status != 0)
    {
      tree_free_fn(node->left, &token_delete);
      node->left = NULL;
    }
  return (OK);
}
