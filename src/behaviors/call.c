/*
** call.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 23:36:27 2015 Louis Person
** Last update Sun Feb  1 16:45:41 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"
#include "lexer.h"
#include "shell.h"
#include "errors.h"
#include "builtins.h"

t_error	check_existence(char *filename)
{
  if (access(filename, F_OK) == -1)
    return (NOENT);
  else if (access(filename, X_OK) == -1)
    return (NORIGHT);
  return (OK);
}

t_error		launch_command(char *program, t_darray *cmd, t_shell *shell)
{
  t_error	ret;
  pid_t		pid;
  int		status;

  if ((ret = check_existence(program)) != OK)
    return (ret);
  if ((pid = fork()) == 0)
    {
      execve(program, (char **)cmd->data,
	     dict_serialize(shell->env, &serialize_env));
      exit(0);
    }
  else if (pid == -1)
    return (SYS_ERROR);
  shell->child = pid;
  waitpid(pid, &status, 0);
  if (WIFEXITED(status))
    shell->status = WEXITSTATUS(status);
  return (OK);
}

t_error		run_through_path(t_darray *cmd, t_shell *shell, char **paths)
{
  char		*program;
  int		i;
  t_error	ret;

  i = 0;
  ret = NOENT;
  while (paths[i] != NULL)
    {
      program = path(paths[i], cmd->data[0]);
      if ((ret = launch_command(program, cmd, shell)) == OK)
	break;
      free(program);
      i++;
    }
  if (ret == OK)
    free(program);
  free_env(paths);
  return (ret);
}

t_error		handle_command(t_darray *cmd, t_shell *shell)
{
  char		**paths;
  t_builtin	callback;
  t_error	ret;

  if ((callback = dict_search(shell->builtins, cmd->data[0])) != NULL)
    {
      if ((ret = callback(cmd, shell)) != QUIT)
	shell->status = ret;
      return (ret);
    }
  if (my_strncmp(cmd->data[0], "/", 1) == 0 ||
      my_strncmp(cmd->data[0], ".", 1) == 0)
    if (launch_command(cmd->data[0], cmd, shell) == OK)
      return (OK);
  if ((paths = my_strsplit(dict_search(shell->env, "PATH"), ":")) == NULL)
    return (NULL_POINTER);
  ret = run_through_path(cmd, shell, paths);
  if (ret == NOENT)
    error_no_file(cmd->data[0]);
  else if (ret == NORIGHT)
    error_no_right(cmd->data[0]);
  return (ret);
}

t_error	behavior_call(t_token *token, t_shell *shell)
{
  t_darray	*cmd;

  cmd = (t_darray *)token->value;
  return (handle_command(cmd, shell));
}
