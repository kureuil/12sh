/*
** eval.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 16:57:58 2015 Louis Person
** Last update Sun Feb  1 19:03:34 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "shell.h"
#include "parser.h"
#include "errors.h"
#include "interpreter.h"

t_error	check_pairs(char *str, int len)
{
  int	i;
  int	paren;
  bool	quotes;

  i = -1;
  quotes = false;
  paren = 0;
  while (++i < len)
    {
      if (str[i] == '(')
	paren++;
      else if (str[i] == ')')
	paren--;
      else if (str[i] == '"')
	quotes = (quotes == false ? true : false);
    }
  if (quotes == true)
    return (MISM_QUOT);
  if (paren != 0)
    return (MISM_BRAK);
  return (OK);
}

t_error		evalcmd(char *command, int readb, t_shell *shell)
{
  t_queue	*tokens;
  t_tree	*root;
  t_error	ret;

  if ((ret = check_pairs(command, readb)) == MISM_QUOT)
    return (parse_error("syntax error: mismatched quotes."));
  else if (ret == MISM_BRAK)
    return (parse_error("syntax error: mismatched parenthesis."));
  tokens = tokenize(command, readb);
  if (tokens == NULL || tokens->size == 0)
    return (NULL_POINTER);
  root = token_root();
  ret = parse(tokens, root);
  if (ret == PARSE_ERROR)
    my_puterr("fabrish: syntax error.\n");
  if (ret != OK)
    return (ret);
  queue_delete(tokens);
  if (root == NULL)
    return (NULL_POINTER);
  ret = interpret(root, shell);
  tree_free_fn(root, &token_delete);
  return (ret);
}
