/*
** eoc.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 10:36:27 2015 Louis Person
** Last update Thu Jan 29 10:57:35 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "parser.h"

t_error	parse_eoc(t_queue *queue, t_tree *parent)
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
  node->data = token;
  node->parent = parent;
  parent->right = node;
  return (parse(queue, node));
}
