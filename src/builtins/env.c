/*
** env.c<2> for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Jan 25 22:42:14 2015 Louis Person
** Last update Mon Jan 26 00:44:02 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void		puts_env(void *ptr)
{
  t_bucket	*bucket;

  bucket = (t_bucket *)ptr;
  my_putstr(bucket->key);
  my_putstr("=");
  my_putstr(bucket->data);
  my_putstr("\n");
}

t_error	env_builtin(t_darray *cmd, t_dict *env)
{
  cmd = NULL;
  tree_map(env->root, &puts_env);
  return (OK);
}

t_error	setenv_builtin(t_darray *cmd, t_dict *env)
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
  dict_set(env, key, value);
  return (OK);
}

t_error	unsetenv_builtin(t_darray *cmd, t_dict *env)
{
  if (cmd->current_size < 2)
    return (SYS_ERROR);
  dict_delete(env, cmd->data[1], &free);
  return (OK);
}

t_error	getenv_builtin(t_darray *cmd, t_dict *env)
{
  char	*value;

  if (cmd->current_size < 2)
    return (SYS_ERROR);
  if ((value = dict_search(env, cmd->data[1])) == NULL)
    return (NULL_POINTER);
  my_putstr(value);
  my_putstr("\n");
  return (OK);
}
