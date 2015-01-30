/*
** token.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 15:37:28 2015 Louis Person
** Last update Thu Jan 29 20:31:58 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

int	token_new(t_token **token)
{
  if ((*token = malloc(sizeof(t_token))) == NULL)
    return (-1);
  (*token)->value = NULL;
  (*token)->type = T_UNDEFINED;
  return (0);
}

void		token_delete(void *ptr)
{
  t_token	*token;

  token = ptr;
  if (token == NULL)
    return;
  if (token->type == T_CALL)
    free_dynamo(token->value);
  free(token);
}

t_tree		*token_root()
{
  t_tree	*node;
  t_token	*tmp;

  node = malloc(sizeof(t_tree));
  if (node == NULL)
    return (NULL);
  node->parent = node->left = node->right = NULL;
  tmp = (t_token *)node->data;
  if (token_new(&tmp) == -1)
    {
      free(node);
      return (NULL);
    }
  node->data = tmp;
  ((t_token *)node->data)->type = T_SOF;
  return (node);
}
