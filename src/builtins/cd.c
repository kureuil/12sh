/*
** cd.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 20:42:11 2015 Louis Person
** Last update Thu Jan 29 20:45:17 2015 Louis Person
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

void	update_wd(t_dict *env, char *newd)
{
  char	*oldpwd;

  oldpwd = dict_search(env, "PWD");
  dict_set(env, "OLDPWD", oldpwd);
  if (newd[0] == '/')
    dict_set(env, "PWD", newd);
  else
    dict_set(env, "PWD", path(oldpwd, newd));
}

t_error	cd_home(t_dict *env)
{
  char	*home;

  if ((home = dict_search(env, "HOME")) == NULL)
    return (SYS_ERROR);
  if (chdir(home) == -1)
    return (SYS_ERROR);
  update_wd(env, home);
  return (OK);
}

t_error	cd_previous(t_dict *env)
{
  char	*tmp;

  if ((tmp = dict_search(env, "OLDPWD")) == NULL)
    return (NULL_POINTER);
  if (chdir(tmp) == -1)
    return (SYS_ERROR);
  update_wd(env, tmp);
  return (OK);
}

t_error	cd_path(t_darray *cmd, t_dict *env)
{
  if (chdir(cmd->data[1]) == -1)
    return (SYS_ERROR);
  update_wd(env, cmd->data[1]);
  return (OK);
}

t_error	builtin_cd(t_darray *cmd, t_shell *shell)
{
  if (cmd->current_size == 1)
    return (cd_home(shell->env));
  else if (!my_strcmp(cmd->data[1], "-"))
    return (cd_previous(shell->env));
  else
    return (cd_path(cmd, shell->env));
}
