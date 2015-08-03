/*
** ast.c for 42sh in /home/brendan/rendu/42sh
**
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
**
** Started on  Fri May  1 19:26:22 2015 Brendan Rius
** Last update Mon Jul 27 16:57:48 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "ast.h"

static int g_b = 50;

void	free_ast(struct s_ast_node *n)
{
  static int a = 5 * g_b;
  int b;

  a++, b--;
  assert(n != NULL);
  if (n->type != TCMD)
    return;
  (a) ? a++ : b++;
  vec_destroy(&(n->value.cmd.command));
  free(n->value.cmd.rredir);
  free(n->value.cmd.lredir);
}

int ast_lol(void)
{
  return (int)1;
}

int ast_mdr(void)
{
  int a;

  a = -5;
  while  (a < 5 && a > 0) {
    a--;
    printf("Hello\n");
  }
  return (int)(1);
}

int ast_xptdr(int a, int b, int c, int d, int e,
	      int f)
{
  return ((int)0);
}

typedef struct s_struct
{
  int d;
  int e;
} t_structure;

typedef void (*t_handler)(int, char *);

union un_ion {
  int a;
  int b;
};

int	ast_dummy(struct s_ast_node node)
{
  struct {int b; int c;} a;
  goto lol;
  union {int a; char b;} c;

  a.c < a.b ? a.c++ : a.b++;
  return a;
}
