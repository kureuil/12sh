/*
** interpreter.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 21:48:35 2015 Louis Person
** Last update Fri Jan 30 10:48:55 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "shell.h"
#include "interpreter.h"

t_behavior	*get_behaviors()
{
  t_behavior	*behaviors;

  if ((behaviors = malloc(sizeof(t_behavior) * TOKEN_TYPES)) == NULL)
    return (NULL);
  behaviors[T_UNDEFINED] = &behavior_sleep;
  behaviors[T_STRING] = &behavior_sleep;
  behaviors[T_CALL] = &behavior_call;
  behaviors[T_OR] = &behavior_or;
  behaviors[T_AND] = &behavior_and;
  behaviors[T_EOC] = &behavior_sleep;
  behaviors[T_EOF] = &behavior_sleep;
  behaviors[T_SOF] = &behavior_sleep;
  behaviors[T_LPARENTHESIS] = &behavior_sleep;
  behaviors[T_RPARENTHESIS] = &behavior_sleep;
  return (behaviors);
}

t_error	process(t_token *token,
		t_behavior *behaviors,
		t_shell *shell,
		t_tree *node)
{
  return (behaviors[token->type](token, shell, node));
}

t_error			interpret(t_tree *node, t_shell *shell)
{
  static t_behavior	*behaviors = NULL;

  if (node == NULL)
    return (NULL_POINTER);
  if (behaviors == NULL && (behaviors = get_behaviors()) == NULL)
    return (COULD_NOT_MALLOC);
  if (process((t_token *)node->data, behaviors, shell, node) == QUIT)
    return (QUIT);
  if (node->left != NULL)
    if (interpret(node->left, shell) == QUIT)
      return (QUIT);
  if (node->right != NULL)
    if (interpret(node->right, shell) == QUIT)
      return (QUIT);
  return (OK);
}
