/*
** rparenthesis.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 10:40:48 2015 Louis Person
** Last update Fri Jan 30 11:20:07 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "parser.h"

t_error	parse_rparenthesis(t_queue *queue, t_tree *parent)
{
  t_token	*token;
  t_tree	*node;

  if ((token = queue->pop(queue)) == NULL)
    return (NULL_POINTER);
  if ((node = malloc(sizeof(t_tree))) == NULL)
    return (COULD_NOT_MALLOC);
  node->left = node->right = node->parent = node->data = NULL;
  if (parent->right != NULL)
    return (PARSE_ERROR);
  parent->right = node;
  node->parent = parent;
  node->data = token;
  while (node != NULL &&
	 ((t_token *)node->data)->type != T_LPARENTHESIS)
    node = node->parent;
  if (node == NULL || ((t_token *)node->data)->type != T_LPARENTHESIS)
    return (PARSE_ERROR);
  return (parse(queue, node->parent));
}
