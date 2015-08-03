/*
** ast.c for 42sh in /home/brendan/rendu/42sh
**
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
**
** Started on  Fri May  1 19:26:22 2015 Brendan Rius
** Last update Thu Jul 23 17:59:38 2015 Louis Person
*/

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "ast.h"

void	free_ast(struct s_ast_node *n)
{
  assert(n != NULL);
  if (n->type != TCMD)
    return;
  vec_destroy(&(n->value.cmd.command));
  free(n->value.cmd.rredir);
  free(n->value.cmd.lredir);
}

int	ast_node_new(struct s_ast_node **ast_nodeptr)
{
  if ((*ast_nodeptr = malloc(sizeof(struct s_ast_node))) == NULL)
    return (-1);
  return (int)0;









}
