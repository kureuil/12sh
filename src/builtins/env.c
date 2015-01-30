/*
** env.c<2> for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 20:46:56 2015 Louis Person
** Last update Fri Jan 30 12:45:16 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

void		puts_env(void *ptr)
{
  t_bucket	*bucket;

  if (ptr == NULL)
    return;
  bucket = (t_bucket *)ptr;
  my_putstr(bucket->key);
  my_putstr("=");
  my_putstr(bucket->data);
  my_putstr("\n");
}

t_error	builtin_env(t_darray *cmd, t_shell *shell)
{
  cmd = NULL;
  if (shell->env->root != NULL)
    tree_map(shell->env->root, &puts_env);
  return (OK);
}

t_error	builtin_setenv(t_darray *cmd, t_shell *shell)
{
  char	*key;
  char	*value;
  char	*copy;

  if (cmd->current_size < 2)
    return (SYS_ERROR);
  copy = cmd->data[1];
  key = my_strsep(&copy, "=");
  value = my_strdup(copy);
  if (my_strlen(value) == 0)
    return (SYS_ERROR);
  dict_set(shell->env, key, value);
  return (OK);
}

t_error	builtin_unsetenv(t_darray *cmd, t_shell *shell)
{
  if (cmd->current_size < 2)
    return (SYS_ERROR);
  dict_delete(shell->env, cmd->data[1], &free);
  return (OK);
}

t_error	builtin_getenv(t_darray *cmd, t_shell *shell)
{
  char	*value;

  if (cmd->current_size < 2)
    return (SYS_ERROR);
  if ((value = dict_search(shell->env, cmd->data[1])) == NULL)
    return (NULL_POINTER);
  my_putstr(value);
  my_putstr("\n");
  return (OK);
}
