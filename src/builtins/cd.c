/*
** cd.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Jan 25 23:32:34 2015 Louis Person
** Last update Mon Jan 26 00:35:21 2015 Louis Person
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "path.h"

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

t_error	cd_builtin(t_darray *cmd, t_dict *env)
{
  if (cmd->current_size == 1)
    return (cd_home(env));
  else if (!my_strcmp(cmd->data[1], "-"))
    return (cd_previous(env));
  else
    return (cd_path(cmd, env));
}
