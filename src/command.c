/*
** command.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:24:43 2015 Louis Person
** Last update Mon Jan 26 00:42:53 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"
#include "path.h"

t_error	launch_command(char *program, t_darray *command, t_dict *env)
{
  pid_t	pid;
  int	status;

  if (access(program, X_OK) == -1)
    return (NOENT);
  if ((pid = fork()) == 0)
    {
      execve(program, (char **)command->data,
	     dict_serialize(env, &serialize_env));
      exit(0);
    }
  else if (pid == -1)
    return (SYS_ERROR);
  else
    {
      wait(&status);
      return (OK);
    }
  return (NOENT);
}

t_error		handle_command(t_darray *cmd, t_dict *env, t_dict *builtins)
{
  char		*program;
  char		**paths;
  int		i;
  t_error	(*builtin)(t_darray *, t_dict *);
  t_error	ret;

  if ((builtin = dict_search(builtins, cmd->data[0])) != NULL)
    return (builtin(cmd, env));
  if (my_strncmp(cmd->data[0], "/", 1) == 0 ||
      my_strncmp(cmd->data[0], "./", 2) == 0)
    if (launch_command(cmd->data[0], cmd, env) == OK)
      return (OK);
  if ((paths = my_strsplit(dict_search(env, "PATH"), ":")) == NULL)
    return (NULL_POINTER);
  i = -1;
  ret = NOENT;
  while (paths[++i] != NULL)
    {
      program = path(paths[i], cmd->data[0]);
      if ((ret = launch_command(program, cmd, env)) == OK)
	return (OK);
    }
  return (NOENT);
}
