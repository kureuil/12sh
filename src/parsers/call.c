/*
** call.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 10:32:17 2015 Louis Person
** Last update Thu Jan 29 21:08:29 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "lexer.h"

t_error		parse_call(t_queue *queue, t_tree *parent)
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
  return (parse(queue, parent));
}
