/*
** or.c<2> for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:12:54 2015 Louis Person
** Last update Thu Jan 29 21:39:23 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "lexer.h"

t_error		parse_or(t_queue *queue, t_tree *parent)
{
  t_token	*token;
  t_tree	*node;

  if ((token = queue->pop(queue)) == NULL)
    return (NULL_POINTER);
  if ((node = malloc(sizeof(t_tree))) == NULL)
    return (COULD_NOT_MALLOC);
  node->left = node->right = node->parent = node->data = NULL;
  if (parent->left == NULL)
    return (PARSE_ERROR);
  node->data = token;
  node->parent = parent;
  parent->right = node;
  return (parse(queue, node));
}
