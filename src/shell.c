/*
** shell.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 09:48:27 2015 Louis Person
** Last update Fri Jan 30 11:56:29 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"
#include "shell.h"
#include "lexer.h"
#include "builtins.h"

static t_shell	*g_shell = NULL;

int	shell_new(t_shell **shell)
{
  if (shell == NULL)
    return (-1);
  if ((*shell = malloc(sizeof(t_shell))) == NULL)
    return (-1);
  if (((*shell)->env = parse_env()) == NULL)
    return (-1);
  if (((*shell)->builtins = get_builtins()) == NULL)
    return (-1);
  (*shell)->prompt = "\\u(\\r)$> ";
  (*shell)->status = 0;
  (*shell)->child = 0;
  return (0);
}

int	shell_delete(t_shell *shell)
{
  if (shell == NULL)
    return (-1);
  if (shell->env->size > 0)
    dict_free(shell->env, &free);
  else
    free(shell->env);
  if (shell->builtins->size > 0)
    dict_free(shell->builtins, &nofree);
  else
    free(shell->builtins);
  free(shell);
  return (0);
}

bool	set_shell(t_shell *shell)
{
  if (shell == NULL)
    return (false);
  g_shell = shell;
  return (true);
}

t_shell	*get_shell()
{
  return (g_shell);
}
