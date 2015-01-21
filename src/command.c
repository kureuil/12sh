/*
** command.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:24:43 2015 Louis Person
** Last update Thu Jan 22 00:33:08 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "path.h"

t_error	launch_command(char *program, t_darray *command, t_dict *env)
{
  extern char **environ;
  pid_t	pid;
  int	status;

  if ((pid = fork()) == 0)
    {
      execve(program, (char **)command->data, environ);
      return (NOENT);
    }
  else if (pid == -1)
    return (SYS_ERROR);
  else
    wait(&status);
  return (OK);
}

t_error	handle_command(t_darray *command, t_dict *env)
{
  char	*program;
  char	**paths;
  int	i;

  if ((paths = my_strsplit(dict_search(env, "PATH"), ":")) == NULL)
    return (NULL_POINTER);
  i = 0;
  while (paths[i] != NULL)
    {
      program = path(paths[i], command->data[0]);
      if (launch_command(program, command, env) == OK)
	return (OK);
      i++;
    }
  return (SYS_ERROR);
}
