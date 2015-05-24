/*
** interpreter_empty.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 18:21:22 2015 Louis Person
** Last update Sun May 24 22:45:25 2015 Louis Person
*/

#include <linux/limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include "ast.h"
#include "shell.h"
#include "my/my.h"
#include "error.h"
#include "env/env.h"
#include "builtins.h"
#include "interpreter/interpreter.h"

static int	command_execute(struct s_ast_node_cmd *cmd,
				struct s_shell *shell,
				char **argv)
{
  char		**env;
  char		execpath[PATH_MAX];

  assert(cmd != NULL);
  if (argv == NULL)
    return (-1);
  env = get_all_env();
  if (env == NULL)
    return (-1);
  if (command_prepare(shell, cmd) == -1)
    return (-1);
  if (find_executable(argv[0], execpath, PATH_MAX) != 0)
    {
      sh_return(shell, 1);
      my_error(E_NOEXEC, argv[0]);
      return (-1);
    }
  execve(execpath, argv, env);
  my_perror();
  return (-1);
}

static int		exec_builtin(struct s_shell *shell,
				     struct s_ast_node_cmd *cmd,
				     char **argv,
				     size_t argc)
{
  struct s_builtin	*builtin;

  builtin = dict_get(shell->builtins, argv[0]);
  if (builtin == NULL)
    return (-1);
  if (command_prepare(shell, cmd) == -1)
    return (-1);
  return (builtin->callback(argc - 1, argv + 1));
}

static int		handle_builtin(struct s_shell *shell,
				       struct s_ast_node_cmd *cmd,
				       char **argv,
				       size_t argc)
{
  pid_t			pid;

  if (shell->piped == false && cmd->ltype == RT_LUNKNOWN &&
      cmd->rtype == RT_RUNKNOWN)
    return (exec_builtin(shell, cmd, argv, argc));
  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
    {
      sh_exit(shell, exec_builtin(shell, cmd, argv, argc));
      return (0);
    }
  shell->child = pid;
  if (shell->piped == true && tcsetpgrp(STDIN_FILENO, pid) == -1)
    return (-1);
  return (0);
}

static int	handle_executable(struct s_shell *shell,
				  struct s_ast_node_cmd *cmd,
				  char **argv)
{
  pid_t		pid;

  pid = fork();
  if (pid == -1)
    return (sh_exit(shell, 255), -1);
  else if (pid == 0)
    {
      if (setpgid(getpid(), getpid()) == -1)
	return (sh_exit(shell, 255), -1);
      if (command_execute(cmd, shell, argv) == -1)
	return (sh_exit(shell, 255), -1);
    }
  else
    {
      shell->child = pid;
      if (shell->fd[0][0] == STDIN_FILENO)
	if (tcsetpgrp(STDIN_FILENO, pid) == -1)
	  return (-1);
    }
  return (0);
}

int			interpret_command(t_interpreter *interpreters,
					  struct s_shell *shell,
					  struct s_btree *tnode)
{
  struct s_ast_node	*node;
  char			**argv;

  assert(tnode != NULL);
  (void)interpreters;
  node = (struct s_ast_node *)tnode->data;
  argv = (char **) vec_serialize(&(node->value.cmd.command));
  if (dict_get(shell->builtins, argv[0]) != NULL)
    {
      if (handle_builtin(shell, &(node->value.cmd),
			 argv, node->value.cmd.command.size) == -1)
	return (free(argv), -1);
    }
  else
    {
      if (handle_executable(shell, &(node->value.cmd), argv) == -1)
	return (free(argv), -1);
    }
  free(argv);
  return (0);
}
