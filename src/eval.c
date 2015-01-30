/*
** eval.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 16:57:58 2015 Louis Person
** Last update Fri Jan 30 09:25:09 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "shell.h"
#include "parser.h"
#include "interpreter.h"

t_error		evalcmd(char *command, int readb, t_shell *shell)
{
  t_queue	*tokens;
  t_tree	*root;
  t_error	ret;

  tokens = tokenize(command, readb);
  if (tokens == NULL || tokens->size == 0)
    return (NULL_POINTER);
  root = token_root();
  ret = parse(tokens, root);
  if (ret == PARSE_ERROR)
    my_puterr("Syntax error.\n");
  if (ret != OK)
    return (ret);
  queue_delete(tokens);
  if (root == NULL)
    return (NULL_POINTER);
  ret = interpret(root, shell);
  tree_free_fn(root, &token_delete);
  return (ret);
}
