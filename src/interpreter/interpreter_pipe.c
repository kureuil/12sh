/*
** interpreter_empty.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 18:21:22 2015 Louis Person
** Last update Fri May 29 23:16:04 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "interpreter/interpreter.h"
#include "my/my.h"
#include "shell.h"
#include "ast.h"

static void	rotate_couples(int fd[3][2])
{
  if (fd[0][0] != STDIN_FILENO)
    {
      close(fd[0][0]);
      close(fd[0][1]);
    }
  fd[0][0] = fd[1][0];
  fd[0][1] = fd[1][1];
  fd[1][0] = -1;
  fd[1][1] = STDOUT_FILENO;
}

static int	pipe_couples(int fd[3][2])
{
  if (fd[1][1] != STDOUT_FILENO)
    rotate_couples(fd);
  if (pipe(fd[1]) == -1)
    return (-1);
  return (0);
}

static bool	process_is_alive(pid_t pid, struct s_shell *shell)
{
  int		status;

  status = 0;
  if (waitpid(pid, &status, WNOHANG) == -1)
    return (false);
  if (WIFEXITED(status) || WIFSIGNALED(status))
    {
      report_exit_status(pid, status, shell);
      return (WIFEXITED(status));
    }
  return (true);
}

static int		exec_node(t_interpreter *interpreters,
				  struct s_shell *shell,
				  struct s_btree *tnode)
{
  struct s_ast_node	*node;

  node = (struct s_ast_node *)(tnode->data);
  if (node == NULL)
    return (-1);
  if (interpreters[node->type](interpreters, shell, tnode) == -1)
    return (-1);
  return (0);
}

int	interpret_pipe(t_interpreter *interpreters,
		       struct s_shell *shell,
		       struct s_btree *tnode)
{
  if (pipe_couples(shell->fd) == -1)
    return (-1);
  shell->piped = true;
  if (tnode->left != NULL)
    {
      if (exec_node(interpreters, shell, tnode->left) == -1)
	return (-1);
    }
  rotate_couples(shell->fd);
  shell->piped = false;
  if (!process_is_alive(shell->child, shell))
    return (0);
  if (tnode->right != NULL)
    {
      if (exec_node(interpreters, shell, tnode->right) == -1)
	return (-1);
    }
  if (shell->fd[0][0] != STDIN_FILENO)
    close(shell->fd[0][0]);
  if (shell->fd[0][1] != -1)
    close(shell->fd[0][1]);
  shell->fd[0][0] = STDIN_FILENO;
  shell->fd[0][1] = -1;
  return (0);
}
