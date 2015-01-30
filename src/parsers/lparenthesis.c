/*
** lparenthesis.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 10:33:03 2015 Louis Person
** Last update Fri Jan 30 10:43:42 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "parser.h"

t_error		parse_lparenthesis(t_queue *queue, t_tree *parent)
{
  t_token	*token;
  t_tree	*node;

  if ((token = queue->pop(queue)) == NULL)
    return (NULL_POINTER);
  if ((node = malloc(sizeof(t_tree))) == NULL)
    return (COULD_NOT_MALLOC);
  node->left = node->right = node->parent = node->data = NULL;
  if (parent->left != NULL)
    return (PARSE_ERROR);
  node->data = token;
  node->parent = parent;
  parent->left = node;
  return (parse(queue, node));
}
