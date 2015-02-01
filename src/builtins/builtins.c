/*
** builtins.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 16:01:01 2015 Louis Person
** Last update Sun Feb  1 18:16:29 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"
#include "builtins.h"

t_error	builtin_alias(t_darray *cmd, t_shell *shell)
{
  char	*key;
  char	*copy;
  char	*alias;

  if (cmd == NULL || cmd->current_size <= 1)
    return (NULL_POINTER);
  copy = cmd->data[1];
  key = my_strsep(&copy, "=");
  alias = my_strdup(copy);
  dict_set(shell->alias, key, alias);
  return (OK);
}

t_dict		*get_builtins()
{
  t_dict	*builtins;

  if (dict_new(&builtins) == -1)
    return (NULL);
  dict_set(builtins, "cd", &builtin_cd);
  dict_set(builtins, "exit", &builtin_exit);
  dict_set(builtins, "env", &builtin_env);
  dict_set(builtins, "setenv", &builtin_setenv);
  dict_set(builtins, "unsetenv", &builtin_unsetenv);
  dict_set(builtins, "getenv", &builtin_getenv);
  dict_set(builtins, "alias", &builtin_alias);
  return (builtins);
}
