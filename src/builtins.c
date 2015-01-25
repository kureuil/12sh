/*
** builtins.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 23 18:22:48 2015 Louis Person
** Last update Mon Jan 26 00:43:32 2015 Louis Person
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "builtins.h"
#include "path.h"

t_dict		*get_builtins()
{
  t_dict	*builtins;

  if (dict_new(&builtins) == -1)
    return (NULL);
  register_builtins(builtins);
  return (builtins);
}

t_error	exit_builtin(t_darray *cmd, t_dict *env)
{
  int	arg;

  arg = 0;
  env = NULL;
  if (cmd->current_size >= 2)
    arg = my_getnbr(cmd->data[1]);
  exit(arg);
  return (QUIT);
}

void	register_builtins(t_dict *builtins)
{
  dict_set(builtins, "exit", &exit_builtin);
  dict_set(builtins, "env", &env_builtin);
  dict_set(builtins, "setenv", &setenv_builtin);
  dict_set(builtins, "getenv", &getenv_builtin);
  dict_set(builtins, "unsetenv", &unsetenv_builtin);
  dict_set(builtins, "cd", &cd_builtin);
}
